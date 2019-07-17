// https://leetcode.com/problems/possible-bipartition/

// O(n) time
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1, vector<int>());
        
        for(auto& edge : dislikes){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(N+1, 0);
        bool rv;
        auto it = find(visited.begin(), visited.end(), 0);
        while(it != visited.end()){
            rv = bipartite(graph, visited, it-visited.begin(), 1);
            if(!rv) return rv;
            it = find(visited.begin(), visited.end(), 0);
        }
        return true;
    }
    
    bool bipartite(vector<vector<int>>& graph, vector<int>& visited, int index, int depth){
        if((visited[index]-depth)%2 == 1) 
            return false;
        if (!visited[index]){
            visited[index] = depth;
            for(int i : graph[index]){
                if(!bipartite(graph, visited, i, depth+1))
                   return false;
            }
        }
        return true;
    }
};
