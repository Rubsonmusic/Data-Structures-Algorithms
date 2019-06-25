class Solution {
private:
	int N;
	
	struct coords{
		coords(int a, int b):x(a),y(b){}
		int x, y;
		bool operator==(const coords& b){
			return (b.x==x) && (b.y==y);
		}
		bool operator!=(const coords& b){
			return !(this->operator ==(b));
		}
	};
	
	bool within_bounds(coords point){
		return (0 <= point.x && point.x <= N-1) && 
				(0 <= point.y && point.y <= N-1);
	}
	
	
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        N = grid.size();
		if(grid[0][0]==1)
			return -1;
		queue<coords> q;
		q.push(coords(0,0));
		vector<vector<int>> steps(N, vector<int>(N, N*N));
		steps[0][0] = 1;
		
		while(q.front() != coords(N-1, N-1)){
			if(q.empty())
				return -1;

			auto curr = q.front();
			q.pop();
			for(int dx = -1; dx<=1; dx++){
				for(int dy = -1; dy<=1; dy++){
					if(!within_bounds(coords(curr.x+dx, curr.y+dy)) || (dx==0 && dy==0))
						continue;
					
					if(grid[curr.x+dx][curr.y+dy] || 
					(steps[curr.x+dx][curr.y+dy]<=steps[curr.x][curr.y]+1)){
						continue;
					}
					
					steps[curr.x+dx][curr.y+dy] = steps[curr.x][curr.y]+1;
					q.push(coords(curr.x+dx, curr.y+dy));
				}
			}
		}
		return steps[N-1][N-1];
    }
};
