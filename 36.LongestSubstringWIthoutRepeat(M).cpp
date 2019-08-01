// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int max_sub=0, start = 0;
        
        for(int i = 0; i<s.size(); i++){
            
            if(map.count(s[i])>0){
                //clear from start to s[i]
                int j = start;
                start = map[s[i]] + 1;
                for(; j<=map[s[i]]; j++) map.erase(s[j]);
            }
            map[s[i]] = i;
            max_sub = max(max_sub, i-start + 1);
            
        }
        return max_sub;
    }
};
