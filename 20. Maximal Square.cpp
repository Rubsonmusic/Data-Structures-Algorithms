// https://leetcode.com/problems/maximal-square/

// O(n) space, O(mn) time
class Solution {
public:
    	int maximalSquare(vector<vector<char>>& matrix){
            int M = matrix.size();
            if(M==0)
                return 0;

            int N = matrix[0].size();
            vector<int> bottom(N+1, 0);
            vector<int> current_row(N+1, 0);

            int right;
            int max_side = 0;
            for(int y = M-1; y>=0; y--){
                right = 0;
                for(int x = N-1; x>=0; x--){
                    if(matrix[y][x]=='1'){
                        current_row[x] = min(min(bottom[x], bottom[x+1]), right) + 1;
                        max_side = (current_row[x]>max_side) ? current_row[x]: max_side;
                        right++;
                    }
                    else{
                        current_row[x] = 0;
                        right = 0;
                    }
                }
                bottom.swap(current_row);
		}
		return max_side*max_side;
	}
};

int main(){
	vector<vector<char>> b({{'0','0'},{'1','1'}, {'1','1'}});
	vector<vector<char>> c({{'0'},{'0'}});
	vector<vector<char>> d({{'0', '1'}});
	vector<vector<char>> e({{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'}});
	vector<vector<char>> f({{'0','0','0','0','0'},{'1','0','0','0','0'},{'0','0','0','0','0'},{'0','0','0','0','0'}});
	vector<vector<char>> g;
	cout << Solution().maximalSquare(b) << endl;
}


