// https://leetcode.com/problems/knight-dialer

// O(1) space 95 percentile, O(n) time 100 percentile
class Solution {
public:
    int knightDialer(int N) {
        if(N==1){
            return 10;
        }
        
	int M = pow(10, 9) + 7;

        unsigned int t0, t1, t2, t3;
        unsigned int t0_old, t1_old, t2_old, t3_old;
        
        t0_old = 1; t1_old = 1; t2_old = 1; t3_old = 1;
        
        for(int i=1; i<N; i++){
            t1 = t0_old%M + t2_old%M; // 1,3,7,9
            t0 = 2*t1_old %M; //2 and 8
            t2 = 2*t1_old%M + t3_old%M; //4 and 6
            t3 = 2*t2_old%M; //0
            
            t0_old = t0 % M;
            t1_old = t1 % M;
            t2_old = t2 % M;
            t3_old = t3 % M;
        }

	unsigned int totes = 4*t1_old%M + 2*t0_old%M + 2*t2_old%M + t3_old%M;
		
		
	return (int)(totes % M);

    }
};
