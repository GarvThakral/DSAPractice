class Solution {
public:
    int balancedStringSplit(string s) {
        int maxB = 0;
        for(int i = 0 ; i < s.size() ;i++){
            int countL = 0;
            int countR = 0;
            for(int j = i ; j < s.size() ;j++){
                if(s[j] == 'L'){
                    countL++;;
                }else if(s[j] == 'R'){
                    countR++;
                }
            }
            if(countL == countR){
                maxB++;
            }
        }
        return maxB; 
    }
};
