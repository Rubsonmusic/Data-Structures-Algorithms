package quickcheck

import common._

import org.scalacheck._
import Arbitrary._
import Gen._
import Prop._

abstract class QuickCheckHeap extends Properties("Heap") with IntHeap {

  lazy val genHeap: Gen[H] = oneOf(const(empty), for{
	v <- arbitrary[A]
	m <- oneOf( const(empty), genHeap )
  } yield insert(v, m) )

  lazy val nonEmptyHeap: Gen[H] = genHeap.filter(x => !isEmpty(x))

  implicit lazy val arbHeap: Arbitrary[H] = Arbitrary(genHeap)

  property("gen1") = forAll { (h: H) =>
    val m = if (isEmpty(h)) 0 else findMin(h)
    findMin(insert(m, h)) == m
  }

  property("merge") = forAll { (h1: H, h2: H) =>
	if(!isEmpty(h1) && !isEmpty(h2)){
	  val m = findMin(h1) min findMin(h2)
	  findMin(meld(h1, h2)) == m
	}
	else true
  }

  property("insertion") = forAll(nonEmptyHeap){ h =>
    findMin(h)!=Int.MinValue ==>
	{val newMin = findMin(h) - 1
    val newHeap = insert(newMin, h)
	newMin == findMin(newHeap)}
  }

  property("merge") = forAll { (h1: H) =>
	meld(h1, empty) == meld(empty, h1) && meld(h1, empty) == h1
  }
  
  def checkOrder(heap: H): Boolean = {
	  if (isEmpty(heap)) true
	  else {
	    val m = findMin(heap)
	    val subHeap = deleteMin(heap)
	    if (isEmpty(subHeap)) true
		else (ord.lteq(m, findMin(subHeap)) && checkOrder(subHeap))
      }
  }

  def count(heap: H, c: Int = 0): Int = {
	if (isEmpty(heap)) c
	else count(deleteMin(heap), c+1)
  }

  def getElements(heap: H, s: Set[A] = Set()): Set[A] = {
	if (isEmpty(heap)) s
	else getElements(deleteMin(heap), s+findMin(heap))
  }

  property("merge") = forAll{ (h1: H, h2: H) =>
	val combined = meld(h1, h2)
	checkOrder(combined) && (getElements(h1)++getElements(h2)) == getElements(combined)
  }

  property("merge") = forAll{ (h1: H, h2: H) =>
	count(meld(h1, h2)) <= count(h1) + count(h2)
  }

  property("ordering") = forAll { (h: H) =>
	checkOrder(h)
  }

  property("empty") = forAll { (x: A) =>
	val h = insert(x, empty)
	findMin(h)==x && deleteMin(h) == empty
  }
}
