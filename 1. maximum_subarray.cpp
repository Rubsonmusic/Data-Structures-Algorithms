// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n^3)
int exhaustive(const vector<int>& v){
	int largest_sum = *max_element(v.begin(), v.end());

	for(auto i = v.begin(); i < v.end()-1; i++){
		for(auto j = i+1; j != v.end(); j++){
			int sum = 0;
			for(auto k = i; k!=j+1; k++){
				sum = sum + *k;
			}
			if (sum>largest_sum){
				largest_sum = sum;
			}
		}
	}
	return largest_sum;
}

// O(n)
int maxSubArray(const vector<int> v){
	int largest_sum = *(v.begin());
	int current_sum = 0;
	
	for(auto e : v){
		
		if(largest_sum<0 && e > largest_sum){
			largest_sum = e;
		}
		
		if(current_sum+e > 0){
			current_sum += e;
		}
		else{
			current_sum = 0;
		}
		
		if (largest_sum>=0 && (current_sum>largest_sum)){
			largest_sum = current_sum;
		}
		
	}
	return largest_sum;
}

int main(){
	vector<int> arr = {0,2,0,2};
	cout << maxSubArray(arr);
	return 0;
}
