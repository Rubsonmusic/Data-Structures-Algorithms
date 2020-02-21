class Solution:

    def longestPalindrome(self, s: str) -> str:
        self.string = s
        rv = ''
        for i in range(len(self.string)):
            newPalindrome = self.isPalindrome(i)
            if len(newPalindrome) > len(rv):
                rv = newPalindrome
        return rv

    def isPalindrome(self, center):
        
        # returns largest palindrome in self.string with given center

        if (center < 0 or center >= len(self.string)):
            return ''

        l = 0
        while center-l-1 >=0 and center+l+1 < len(self.string):
            if self.string[center-l-1] == self.string[center+l+1]:
                l += 1
            else:
                break

        # even case 
        k = 0
        while (center-k >= 0) and (center+k+1 < len(self.string)):
            if self.string[center-k] == self.string[center+k+1]:
                k += 1
            else:
                break
        # print( "l:",l," k:",k)
        if l>=k:
            return self.string[center-l: center+l+1]
        else:
            return self.string[center+1-k: center+k+1]

if __name__=="__main__":
    solution = Solution()
    solution.string = "abcdcba"
    print(solution.isPalindrome(0), "zeroth")
    print(solution.isPalindrome(1))
    print(solution.isPalindrome(2))
    print(solution.isPalindrome(3))
    print(solution.isPalindrome(4))
    print(solution.isPalindrome(5))
    print(solution.isPalindrome(6))
    print(solution.isPalindrome(7))
    print(solution.longestPalindrome("abadaba"))
