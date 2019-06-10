
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> prevPermOpt1(vector<int>& A) {
	int index1 = -1;
	int index2 = -1;
	int min = 10000;
	int num = 10000;
	for(unsigned int i=0; i<A.size(); i++){
		for(unsigned int j=i+1; j<A.size(); j++){
			if((A[i]-A[j]<=min and A[i]-A[j]>0 and (A[i]<num or i>index1)) or (A[i]-A[j]<min and A[i]-A[j]>0)){
				cout << A[i] << " " << A[j] << "\n";
				min = A[i]-A[j];
				index1 = i;
				index2 = j;
				num = A[i];
			}
			
		}
	}
	if(index1==-1)
		return A;
	A[index1] = A[index2];
	A[index2] += min;
	return A;
}
int main(){
	vector<int> nums = {3, 1, 1, 3};
	vector<int> nums2 = {2,1,2,1,1,2,2,1};
	for(auto& e : prevPermOpt1(nums2)){
		cout<<e<<"\n";
	}
	
	return 0;
}
