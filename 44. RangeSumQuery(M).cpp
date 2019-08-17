// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
private:
    vector<int> original;
    int size;
    vector<int> n;
public:
    NumArray(vector<int>& nums): original(nums), size(nums.size()), n(size+1, 0) {
        for(int i = 0; i<size; i++){
            n[i+1] = n[i] + nums[i];
        }
    }
    
    void deltaUpdate(int start, int end, int delta){
        for(int i = start; i<=end; i++){
            n[i] += delta;
        }
    }
    void update(int i, int val) {

        int delta = val - original[i];
        original[i] = val;
        
        if(i+1>size/2)
            deltaUpdate(i+1, size, delta);
        else
            deltaUpdate(0, i, -delta);
    }
    
    int sumRange(int i, int j) {
        if(i==j) return original[i];
        return n[j+1] - n[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
