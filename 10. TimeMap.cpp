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
		bool operator <(const data& a){
			return timestamp < a.timestamp;
		}
	};


	string binary(const vector<data>& v, vector<data>::iterator start, vector<data>::iterator end, data x){
		if((end-start)==1){
			if((*end>x) and (x>*start))
				return start->value;
			return " ";
		}
		
		
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
        return "hello";
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
	TimeMap a, b;
	//a.set("a", "aval", 2);
	//a.set("a", "sdlk", 13);
	//a.set("b", "er", 4);
	a.print_all();
	return 0;
}
