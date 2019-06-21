// https://leetcode.com/problems/sum-of-distances-in-tree

// O(n) time, O(n) space
class Solution {
private:
    vector<set<int>> graph;
	vector<int> summs;
	vector<int> conns;
	int N;
	
	void receive(int node, int parent){

		int sum = 0;
		int num_conns = 0;
		for (auto e: graph[node]){
			if(e==parent)
				continue;
			receive(e, node);
			sum += summs[e] + 1 + conns[e];
			num_conns += 1 + conns[e]; 
		}
		summs[node] = sum;
		conns[node] = num_conns;
	}
	
	void transmit(int node, int parent){
		if(parent!=-1){
			summs[node] = summs[parent] - 2 + (N-2*conns[node]);
		}
		for(auto e: graph[node]){
			if(e!=parent)
				transmit(e, node);
		}
	}
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges){
        if (N==1){
            return vector<int>(1, 0);
        }
		graph = vector<set<int>>(N, set<int>());
		summs = vector<int>(N, 0);
		conns = vector<int>(N, 0);
		this->N = N;
		
		for (auto& e : edges){
			graph[e[0]].insert(e[1]);
			graph[e[1]].insert(e[0]);
		}
		
		receive(edges[0][0], -1);
		transmit(edges[0][0], -1);
		return summs;
	}
};
