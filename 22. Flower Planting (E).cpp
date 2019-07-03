class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<set<int>>  graph(N,set<int>());
        vector<int> colors(N,-1);
        
        for(auto& e : paths){
            graph[e[0]-1].insert(e[1]-1);
            graph[e[1]-1].insert(e[0]-1);
        }
        
        bool possible[4];
        for(int i = 0; i<N; i++){
            possible[0] = true;
            possible[1] = true;
            possible[2] = true;
            possible[3] = true;
            for(auto& nbr : graph[i]){
                if(colors[nbr] !=-1)
                    possible[colors[nbr]-1] = false;
            }
            
            for(int j = 0; j<4; j++)
                if(possible[j]){colors[i] = j+1; break;}
        }
        return colors;
    }
};
