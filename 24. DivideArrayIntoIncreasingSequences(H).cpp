// https://leetcode.com/problems/divide-array-into-increasing-sequences/

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int previous = -1;
        int duplicates = 1;
        int max_duplicates = 1;
        for(auto& e: nums){
            if(e==previous){
                duplicates++;
                max_duplicates = max(duplicates, max_duplicates);
            }
            else{
                previous = e;
                duplicates = 1;
            } 
        }

        return ((int)nums.size())/max_duplicates >= K;
    }
};
