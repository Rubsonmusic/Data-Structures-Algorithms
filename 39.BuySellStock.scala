import scala.annotation.tailrec

object Solution {
    def maxProfit(prices: Array[Int]): Int = {
        val length = prices.length
        
        @tailrec def mp(index: Int, minm: Int, best: Int): Int = {
            if (index==length) 
                best
            else 
                mp(index+1, Math.min(prices(index), minm), Math.max(best, prices(index)-minm))
        }
        
        mp(0, Int.MaxValue, 0)
    }
}
