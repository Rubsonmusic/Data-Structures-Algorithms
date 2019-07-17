// https://leetcode.com/problems/target-sum/

// O(Sn) time, O(S) space
class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int S) {
        int size = 0;
        for (auto& n : nums)
            size += n;
        
        if(S>size || S<-size) return 0;
        
        vector<int> a(2*size+1,0);
        vector<int> b(2*size+1,0);

        a[nums[0]+size] = 1;
        a[-nums[0]+size] += 1;
        
        for(auto it = nums.begin()+1; it!=nums.end(); it++){
            for(int i = -size; i<size+1; i++){
                if(a[i+size]!=0){
                    b[i+*it + size] += a[i+size];
                    b[i-*it + size] += a[i+size];
                }
            }
            a.swap(b);
            fill(b.begin(), b.end(), 0);
        }
        
        return a[S+size];
    }

};
