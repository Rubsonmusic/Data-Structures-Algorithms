// https://leetcode.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if(size<3)
            return false;
        
        vector<int> mins(size);
        mins[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            mins[i] = min(mins[i-1], nums[i]);
        }
        
        stack<int> s;
        s.push(INT_MAX);

        for(int i = size-1; i>0; i--){
            while(s.top()<=mins[i])
                s.pop();
            
            if(nums[i]>s.top() && s.top()>mins[i])
                return true;
            
            if(nums[i]<s.top() && nums[i]>mins[i])
                s.push(nums[i]);
            
        }
        return false;
    }
};
