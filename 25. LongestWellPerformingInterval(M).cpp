// https://leetcode.com/problems/longest-well-performing-interval/

// wrong answer

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int count = 0, len = 0;
        int max_len = 0, count_max_len = 0;
        for(auto it = hours.begin(); it != hours.end(); it++){
            count += *it>8 ? 1 : -1;
            len++;
            if(count==-1){
                len = 0;
                count = 0;
            }
            if(count!=0 && len>max_len) {
                max_len = len;
                count_max_len = count;
            }
        }

        count = 0; len = 0;
        for(auto it = hours.end()-1; it >= hours.begin(); it--){
            count += *it>8 ? 1 : -1;
            len++;
            if(count==-1){
                len = 0;
                count = 0;
            }
            if(count!=0 && len>max_len) {
                max_len = len;
                count_max_len = count;
            }
        }
        
        if(count_max_len>1) max_len = min((int)hours.size(), max_len+count_max_len-1);
        
        return max_len;
    }
};
