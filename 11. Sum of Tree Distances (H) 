#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm> 
#include <stack>

using namespace std;


class Solution {
private:
	
	
public:
	
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges){
		vector<set<int>> graph(N, set<int>());
		vector<unsigned int> num_conns(N, 0);
		vector<int> sum(N, 0);
		queue<int> to_visit;
		stack<int> visited;
		vector<int> parents(N, -1);
		vector<bool> touched(N, false);
		vector<unsigned int> cumulative_conns(N, 0);
		
		for (auto& e : edges){
			graph[e[0]].insert(e[1]);
			graph[e[1]].insert(e[0]);
		}
		
		//placing deepest nodes in queue
		int i = 0;
		for (auto& e : graph){
			if(e.size() == 1)
				to_visit.push(i);
			i++;
		}
		
		
		while(! to_visit.empty()){
			int child = to_visit.front();
			to_visit.pop();
			
			set<int> possible_parents = graph[child];
			
			int parent = -1;
			for(auto& pp : possible_parents){
				if(!touched[pp])
					parent = pp;
			}
			
			if (parent != -1){
				parents[child] = parent;
				
				num_conns[parent]++;
				cumulative_conns[parent] += cumulative_conns[child] + 1;
				
				if (num_conns[parent]+1 == graph[parent].size())
					to_visit.push(parent);
				
				
				sum[parent] += 1 + sum[child] + cumulative_conns[child];
			}
			
			visited.push(child);
			touched[child] = true;
		}
		
		if (! visited.empty())
			visited.pop();
		
		while(! visited.empty()){
			i = visited.top();
			//sum[i] = sum[parents[i]] - (num_conns[i]) + 1) + (N - num_conns[i] -1)
			sum[i] = N + sum[parents[i]] - 2 - 2*cumulative_conns[i];
			visited.pop();
		}
		
		int j = 0;
		for (auto& e: parents){
			cout<< "parent of "<<j<< ": " << e << endl;
			j++;
		}
		
		j = 0;
		for (auto& e: sum){
			cout<< "sum of "<<j<< ": " << e << endl;
			j++;
		}
		
		j = 0;
		for (auto& e: num_conns){
			cout<< "num_cons of "<<j<< ": " << e << endl;
			j++;
		}
		
		
		j = 0;
		for (auto& e: cumulative_conns){
			cout<< "cumulative_cons of "<<j<< ": " << e << endl;
			j++;
		}

		while(! visited.empty()){
			cout<< "visited: " << visited.top() << endl;
			visited.pop();
		}
		
		int n = 0;
		for (auto& i : graph){
			if (! i.empty()){
				cout << n << ": ";
				for (auto& j : i)
					cout << j << " ";
				cout << endl;
			}
			n++;
		}
		
		return edges[0];
		
	}
    vector<int> sumOfDistancesInTree1(int N, vector<vector<int>>& edges) {
		for (auto it = edges.begin(); it != edges.end(); it++){
			auto& edge = *it;
			if (edge[0]>edge[1])
				swap(edge[0], edge[1]);
		}
		vector<int> sum(N, 0);
		vector<int> num_cons(N, 0);
		int i = 0;
        for (auto it = edges.rbegin(); it != edges.rend(); it++){
			auto& edge = *it;
			sum[edge[0]] += sum[edge[1]] + 1 + num_cons[edge[1]];
			num_cons[edge[0]] += 1;
			i++;
		}
		
		for (auto it = edges.begin(); it != edges.end(); it++){
			auto& edge = *it;
			//sum[edge[1]] = sum[edge[1]] + (sum[edge[0]] - 1 - sum[edge[1]] - num_cons[edge[1]]) + (N - num_cons[edge[1]] -1) ;
			sum[edge[1]] =  N + sum[edge[0]] - 2 - 2*num_cons[edge[1]] ;
		}
		
		
		//cout << sums[0] << endl;
		return sum;
    }
};


int main(){
	vector<vector<int>> y = {{0,1},{0,2},{2,3},{2,4},{2,5}};
	vector<vector<int>> y2 = {{1,2},{1,4},{5,0},{3,0},{3,4}};
	vector<vector<int>> y3 = {{0,1}};
	auto x = Solution().sumOfDistancesInTree(2, y3);
	for (auto e: x)
		cout << e << endl;

	cout<< "DOne" << endl;
	return 0;
}
