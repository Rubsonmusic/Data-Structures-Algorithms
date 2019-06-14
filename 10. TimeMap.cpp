#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;


class TimeMap {
private:
	struct data{
		int timestamp;
		string value;
	};
	
	string binary(const vector<data>& v, int x){
		int l = 0;
		int r = v.size()-1;
		
		while(l<r){
			int m = l+(r-l)/2;
			if((x<v[m+1].timestamp) and (v[m].timestamp<=x))
				return v[m].value;
			else if(x<=v[m].timestamp)
				r = m;
			else
				l = m+1;
		}
		
		if (l==r){
			if(v[l].timestamp<=x)
				return v[l].value;
			else
				return "";
		}
			
		return "";
	}
	
public:
    /** Initialize your data structure here. */
	unordered_map<string, vector<data>> dict;
	
    TimeMap() {
		
    }
    
    void set(string key, string value, int timestamp) {

		if (dict.count(key)==0){
			dict[key] = *(new vector<data>(1, {timestamp, value}));
		}
		else{
			dict[key].push_back({timestamp, value});
		}
    }
    
    string get(string key, int timestamp) {
        return this->binary(dict[key], timestamp);
    }
	
	void print_all(){
		for (auto i : dict) 
			for (auto j: i.second)
				cout << "Key: " << i.first << ", Value: " << j.value << ", Timestamp: "<< j.timestamp << endl; 
	}

	
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
 
int main(){
	TimeMap a;
	a.set("a", "aval", 4);
	a.set("a", "er", 5);
	a.set("a", "sdlk", 6);
	cout<< a.get("a", 1) << endl;
	a.print_all();
	return 0;
}
