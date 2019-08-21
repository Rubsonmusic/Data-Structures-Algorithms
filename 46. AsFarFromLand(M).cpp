// https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
private:
    vector<vector<int>> distances;
public:
    int maxDistance(vector<vector<int>>& grid) {
        distances = vector<vector<int>>(grid.size(), vector<int>(grid.size(), -1));
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    q.push(pair<int,int>(i,j));
                    distances[i][j] = 0;
                }
            }
        }
        

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            if(valid(curr.first+1, curr.second)){
                cout << curr.first << " " <<  curr.second << endl;
                q.push(pair<int,int>(curr.first+1, curr.second));
                distances[curr.first+1][curr.second] = distances[curr.first][curr.second] + 1;
            }
            
            if(valid(curr.first, curr.second + 1)){
                q.push(pair<int,int>(curr.first, curr.second + 1));
                distances[curr.first][curr.second + 1] = distances[curr.first][curr.second] + 1;
            }
            
            if(valid(curr.first-1, curr.second)){
                q.push(pair<int,int>(curr.first-1, curr.second));
                distances[curr.first-1][curr.second] = distances[curr.first][curr.second] + 1;
            }
            
            if(valid(curr.first, curr.second -1)){
                q.push(pair<int,int>(curr.first, curr.second - 1));
                distances[curr.first][curr.second - 1] = distances[curr.first][curr.second] + 1;
            }

        }
        
        int maxdist = -1;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(distances[i][j]>0){
                    maxdist = max(distances[i][j], maxdist);
                }
            }
        }
        
        return maxdist;
    }
    
    bool valid(int x, int y){
        if (x >=distances.size() || y >=distances.size()) return false;
        if (x<0 || y<0) return false;
        if (distances[x][y] != -1) return false;
        
        return true;
    }
};
