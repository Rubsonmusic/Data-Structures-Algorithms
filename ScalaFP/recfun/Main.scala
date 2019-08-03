package recfun

object Main {
  def main(args: Array[String]) {
    println("Pascal's Triangle")
    for (row <- 0 to 10) {
      for (col <- 0 to row)
        print(pascal(col, row) + " ")
      println()
    }
  }

  /**
   * Exercise 1
   */
  def pascal(c: Int, r: Int): Int = {
    if (c==0 || c==r) 1 else pascal(c-1, r-1) + pascal(c, r-1)
  }
  
  /**
   * Exercise 2
   */
  def balance(chars: List[Char]): Boolean = {
    def b(arr: List[Char], open: Int): Boolean = {
	  if (arr.isEmpty && open==0) true 
	  else if (open<0) false
	  else if (arr.head == '(') b(arr.tail, open+1)
	  else if (arr.head == ')') b(arr.tail, open-1)
	  else b(arr.tail, open)
	}
	  
	  b(chars, 0)
  }
  
  /**
   * Exercise 3
   */
  def countChange(money: Int, coins: List[Int]): Int = {
    if (coins.isEmpty || money<=0) 0
    else if (money==coins.head) 1 + countChange(money, coins.tail)
	else countChange(money-coins.head, coins) +
            countChange(money, coins.tail)
  					
  }
  }
