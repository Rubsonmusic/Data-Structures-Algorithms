class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> a(K, -1);
        int sum = 0, count = 0;
        a[0] = 0;
        for(int e : A){
            sum = (sum + e)%K;
            sum = sum<0 ? K+sum : sum;
            if(a[sum]>=0){
                count += a[sum] + 1;
                a[sum]++;
            }
            else {
                a[sum] = 0;
            }
        }
        
        return count;
    }
};
