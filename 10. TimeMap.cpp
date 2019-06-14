// https://leetcode.com/problems/time-based-key-value-store/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


class TimeMap {
	private:
	    
		struct data{
			int timestamp;
			string value;
		bool operator <(const data& y) const{
				return timestamp < y.timestamp;
			}
		};

		unordered_map<string, vector<data>> dict;
	
	public:
	    /** Initialize your data structure here. */	
	    TimeMap() {	
	    }
	    
	    void set(string key, string value, int timestamp) {
				dict[key].push_back({timestamp, value});
	    }
	    
	    string get(string key, int timestamp) {

			vector<data>& v = dict[key];
			if (v.size()==0)
				return "";
			auto it = upper_bound(v.begin(), v.end(), data({timestamp, ""}));
		
			if (it==v.end() or it==v.begin()){
				if (v.back().timestamp<=timestamp)
					return v.back().value;
				else
					return "";
			}
		
			return (--it)->value;
	    }
};

 
int main(){
	TimeMap a;
	a.set("a", "aval", 4);
	a.set("a", "er", 5);
	a.set("a", "sdlk", 6);
	cout<< a.get("a", 1) << endl;
	return 0;
}
