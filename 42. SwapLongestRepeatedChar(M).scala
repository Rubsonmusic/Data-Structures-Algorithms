// https://leetcode.com/submissions/detail/251052520/

// scala functional

import scala.annotation.tailrec
object Solution {
    def maxRepOpt1(text: String): Int = {

        def f(c:Char, l: List[(Char, Int)])= {
            if(l.head._1==c) (c, l.head._2+1)::l.tail
            else (c, 1)::l
        }

        val charList = text.toList
        val grouped = charList.foldRight(List((text.charAt(text.length-1),0)))(f)
        val counter = charList.groupBy(identity).mapValues( _.length)
        
        @tailrec
        def solve(charCount: List[(Char, Int)], currMax: Int): Int = charCount match{
            case (c1, n1)::(_, 1)::(c2, n2)::_ => {
                if (c1==c2)
                    solve(charCount.tail, currMax.max(n1+n2+{if (counter(c1)>n1+n2) 1 else 0}))
                else
                    solve(charCount.tail, currMax.max(n1+{if (counter(c1)>n1) 1 else 0}))
            }
            case (c, n)::_ => {
                solve(charCount.tail, currMax.max(n+{if (counter(c)>n) 1 else 0}))
            }
            case _ => currMax
        }
        
        solve(grouped, 0)
    }
}
