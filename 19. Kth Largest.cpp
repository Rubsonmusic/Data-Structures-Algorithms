// https://leetcode.com/problems/kth-largest-element-in-an-array/

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		partial_sort(nums.begin(), nums.begin()+k, nums.end(), [](int c, int d){return c>d;});
		return nums[k-1];
    }
};
int main(){
	vector<int> b({3,2,3,1,2,4,5,5,6});
	cout << Solution().findKthLargest(b, 4) << endl;

}


