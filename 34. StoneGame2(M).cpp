// https://leetcode.com/problems/stone-game-ii/

class Solution {
public:

    vector<int> cumsum;
    vector<vector<int>>cache;
    
    int stoneGameII(vector<int>& piles) {
        int size = piles.size();
        cumsum = vector<int>(size, 0);
        cumsum[size-1] = piles[size-1];
        for(int i = size-2; i>=0; i--){
            cumsum[i] = cumsum[i+1] + piles[i];
        }
        cache = vector<vector<int>>(size, vector<int>(size, -1));
        return turn(0, 1);
    }
    
    int turn(int index, int M){
        if(2*M >= cumsum.size()-index){
            return cumsum[index];
        }
        
        int min_sum = INT_MAX;
        for(int i = 1; i<= 2*M; i++){
            if(cache[index+i][max(M,i)] != -1)
                min_sum = min(min_sum, cache[index+i][max(M,i)]);
            else
                min_sum = min(min_sum, turn(index+i, max(M, i)));
        }
        
        cache[index][M] = cumsum[index]-min_sum;
        return cumsum[index]-min_sum;
    }
    
    
};
