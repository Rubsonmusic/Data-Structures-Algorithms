# stack size 'n', time complexity O(2^n)
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        power_set = []
        
        def df(rsub, i):
            if(i==len(nums)):
                power_set.append(rsub)
                return
                
            lsub = rsub.copy()
            lsub.append(nums[i])
            
            df(lsub, i+1)
            df(rsub, i+1)
        
        df([], 0)
        return power_set
