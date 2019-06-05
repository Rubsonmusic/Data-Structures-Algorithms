#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

//Balanced parenthesis
 
bool isbalanced(const string c, unordered_map<char, char>& brackets){
	
	stack<char, list<char>> last;

	for(auto e: c){
		if(brackets.count(e)==0)
			last.push(e);
		else if (brackets.at(e) != last.top())
			return false;
		else
			last.pop();
	}
	
	if(last.empty())
		return true;
	
	return false;
}

int main(){
	unordered_map<char, char> brackets = {{')','('},{']','['},{'}','{'}};
	cout << isbalanced("[{]}", brackets);
	return 0;
}
