//  https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

#include <iostream>
#include <vector>

using namespace std;

// O(n) time, O(1) space
bool canThreePartsEqualSum(vector<int>& A) {
	int sum = 0;
	
	for(auto& e : A){
		sum += e;
	}
	
	if(sum%3 != 0)
		return false;
		
	uint8_t count = 0;

	int partition = sum/3;
	int part_sum = 0;
	
	for(auto& e : A){
		part_sum += e;
		if (part_sum==partition){
			count++;
			part_sum = 0;
		}
		if (count==2)
			return true;
	}
	return false;
 
}

int main(){
	vector<int> nums = {18,12,-18,18,-19,-1,10,10};

	cout << canThreePartsEqualSum(nums);
	return 0;
}
