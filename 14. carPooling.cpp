// https://leetcode.com/problems/car-pooling/

// O(n) time and O(n) space
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

		if(trips.size() ==0)
			return true;

        vector<int> addons(1001, 0);

		for(auto e: trips){
			addons[e[1]] += e[0];
			addons[e[2]] -= e[0];
		}
		
		int current = 0;
		for (auto e: addons){
			current += e;
			if (current>capacity)
				return false;
		}
		return true;
    }
};

