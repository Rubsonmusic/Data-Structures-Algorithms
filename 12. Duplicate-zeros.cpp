// https://leetcode.com/contest/weekly-contest-141/problems/duplicate-zeros/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
	vector<int> duplicate(arr);
	int i = 0;
	for(auto it = arr.begin(); it != arr.end(); it++){
		if(duplicate[i]==0){
			*it = 0;
			if((it+1) == arr.end())
				return;
			*(it+1) = 0;
			it += 1;
		}
		else
			*it = duplicate[i];
		
		i += 1;
	}
}
};
