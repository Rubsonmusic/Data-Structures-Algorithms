class Solution:
    def convertToBase7(self, num: int) -> str:
        l = [(abs(num)%7**(i+1))//(7**i) for i in range(9,-1,-1)]
        rv = ""
        for s in l[:-1]:
            rv = rv+str(s) if (s!=0 or rv!="") else rv
        return ("-" if num<0 else "") + rv + str(l[-1])
