// https://leetcode.com/problems/rabbits-in-forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> sums(1000,0);
        int total = 0;
        for(int i = 0; i<answers.size(); i++){
            int curr = sums[answers[i]];
            if (curr==0 || curr>answers[i]){
                total += 1 + answers[i];
                sums[answers[i]] = 1;
            }
            else if (curr <= answers[i])
                sums[answers[i]]++;

        }
        return total;
    }
};
