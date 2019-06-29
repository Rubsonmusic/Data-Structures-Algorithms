// https://leetcode.com/problems/maximal-square/


class Solution {
private:
	
	int rec_maximal(vector<vector<char>> matrix, int depth){
		int height = matrix.size();
		int width = matrix[0].size();
		
		if(!non_zero(matrix))
			return depth-1;
			
		if(height == 2){
			for(int i =0; i<width-1; i++){
				if(is_square(matrix, i, 0))
					return depth+1;
			}
			if (non_zero(matrix))
				return depth;
			return depth-1;
		}
		else if(width==2){
			for(int i=0; i<height-1; i++){
				if(is_square(matrix, 0, i))
					return depth+1;
			}
			if (non_zero(matrix))
				return depth;
			return depth-1;
		}
		vector<vector<char>> next_mat(height-1, vector<char>(width-1, '1'));
		
		for(int y = 0; y<height-1; y++){
			for(int x = 0; x<width-1; x++){
				if(!is_square(matrix, x, y))
					next_mat[y][x] = '0';
			}
		}
		return rec_maximal(next_mat, depth+1);
	}
public:

	bool non_zero(vector<vector<char>>& mat){
		for (auto& e: mat){
			for(auto& g: e)
				if(g=='1')
					return true;
		}
		return false;
	}
	
	bool is_square(vector<vector<char>>& mat, int x, int y){
		bool rv = mat[y][x] == '1' and mat[y][x+1] == '1';
		rv = rv and mat[y+1][x]=='1' and mat[y+1][x+1]=='1';
		return rv;
	}
	
    int maximalSquare(vector<vector<char>>& matrix) {
		if(matrix.size()==0)
			return 0;
		bool nonzero = non_zero(matrix);
		if (!nonzero)
			return 0;
		if (matrix.size()==1 || matrix[0].size()==1){
			if(nonzero)
				return 1;
			return 0;
		}
			
		int side = rec_maximal(matrix, 1);
		return side*side;
    }
};
