// https://leetcode.com/problems/find-in-mountain-array/submissions/

// O(logN) time, O(1) space
class Solution {
private:
	MountainArray * arr;
	
	int binary(int s, int e, int x, bool decreasing){
		int mid, midval;
		while(s<=e){
			mid = s + (e-s)/2;
			midval = arr->get(mid);
			
			if(x == midval)
				return mid;
			
			if(decreasing)
				if(x < midval)
					s = mid + 1;
				else
					e = mid - 1;
			else
				if(x < midval)
					e = mid - 1;
				else
					s = mid + 1;
		}
		return -1;
	}
	
	
public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		arr = &mountainArr;
		
		int s = 0;
		int e = arr->length()-1;
		int mid, val0, val1, val2;
		bool slope0 = true;
		bool slope1 = true;
		while(slope0 == slope1){
			mid = s + (e-s)/2;
			val0 = arr->get(mid-1);
			val1 = arr->get(mid);
			val2 = arr->get(mid+1);
			slope0 = val1 > val0;
			slope1 = val2 > val1;
			if(slope0 and slope1)
				s = mid;
			else if (!slope0 and !slope1)
				e = mid;
		}
		
		int index;
		if(slope0)
			 index = binary(0, mid, target, false);
			 if(index!=-1)
				 return index;
		else
			index = binary(mid, arr->length()-1, target, true);
			if(index!=-1)
				return index;
		
		return -1;
	}
		
};
