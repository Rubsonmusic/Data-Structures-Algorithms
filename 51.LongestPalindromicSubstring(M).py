class Solution:

    def longestPalindrome(self, s: str) -> str:

        def isPalindrome(s, m, n):
            # returns largest palindrome in s with m,n as its center

            while m >= 0 and n < len(s):
                if s[m] != s[n]:
                    break
                m -= 1
                n += 1
            return s[m+1:n]
        
        cl, cr = len(s)//2 - 1 , len(s)//2
        rv = ''
        if len(s)%2==1:
            rv = isPalindrome(s, cl, cl)
            cl += 1

        for r,l in zip(range(cr,len(s)), range(cl,-1,-1)):

            if len(rv) > 2*l+1:
                return rv

            rv = max(rv,
                    isPalindrome(s, l, l),
                    isPalindrome(s, l, l+1),
                    isPalindrome(s, r, r),
                    isPalindrome(s, r, r-1),
                    key = len)
            
        return rv


if __name__=="__main__":
    solution = Solution()
    print(solution.longestPalindrome("abadaba"))
    print(solution.longestPalindrome("calskdfn"))
    print(solution.longestPalindrome("bb"))
    print(solution.longestPalindrome("a"))
    print(solution.longestPalindrome("ccc"))
    print(solution.longestPalindrome("dddd"))
    print(solution.longestPalindrome("aacdefcaa"))
    print(solution.longestPalindrome("cbbd"))
