class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int xored = start^goal;
        for(int i = 0 ; i < 32 ; i++){
            if((xored & 1 )== 1){
                count ++;
            }
            xored >>= 1;
        }
        return count;
    }
};