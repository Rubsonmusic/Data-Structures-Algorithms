// https://leetcode.com/problems/unique-paths/

// Note: has a closed form solution 

class Solution {
public:
    int uniquePaths(int m, int n) {

        int num_paths[m] = {0};
        
        num_paths[0] = 1;
        
        int i,j;
        for(i = 0; i<n; i++){
            for(j = 0; j<m ; j++){
                if(j-1>=0) num_paths[j] += num_paths[(j-1)];
            }
        }
        return num_paths[m-1];
    }
};

