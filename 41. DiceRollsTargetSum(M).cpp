// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// dp problem
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> a(target+1);
        vector<int> b(target+1);
        
        a[0] = 1;
        
        for(int i = 1; i<= d; i++){
            for (int n = 1; n<=f; n++){
                if (n > target) break;
                
                for(int j = 0; j<=target; j++){
                    if (n + j > target) break;
                    
                    b[n + j] = (b[n + j] + a[j]) %1000000007;
                }
            }
            
            swap(a, b);
            fill(b.begin(), b.end(), 0);
        }
        
        
        return a[target];
    }
};
