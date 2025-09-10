#include <stack>
class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = -1;
        string answer = "";
        for(int i = 0 ; i < s.size() ;i++){
            if(s[i] == '('){
                depth+=1;
                if(depth>0){
                    answer+="(";
                }
            }else{
                depth -=1;
                if(depth >= 0){
                    answer+=')';
                }
            }
        }
        return answer;
    }   
};