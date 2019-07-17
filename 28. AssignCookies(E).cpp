// https://leetcode.com/problems/assign-cookies/

// O(nlogn) time, O(1) space
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int ret = 0, i = 0;
        while(ret<g.size() && i<s.size()){
            if(g[ret]>s[i]) i++;
            else{
                ret++;
                i++;
            }
        }
        
        return ret;
    }
};
