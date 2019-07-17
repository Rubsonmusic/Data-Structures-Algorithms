// https://leetcode.com/problems/longest-repeating-character-replacement/

// O(n) time , O(1) space
class Solution {
public:
    int characterReplacement(string s, int k) {
        set<char> a;
        for(char e: s){ a.insert(e);}
        int K, start, end;
        int max_count = 0;
        for(char e: a){
            K = 0; start = 0; end = 0;
            if(s[0]!=e) K++;
            while(end<s.size()-1){
                if(K>k && s[start++]!=e) K--;
                else if (s[++end]!=e) K++;
                
                if(K<=k) max_count = max(max_count, end-start+1);
            }
        }
        return max_count;
    }
};
