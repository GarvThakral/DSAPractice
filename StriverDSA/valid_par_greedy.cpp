#include <iostream>
using namespace std;

bool is_valid(string paran_string , int index , int count){
    if(count < 0){
        return false;
    }
    if(index == paran_string.size()){
        return count == 0;
    }
    if(paran_string[index] == '('){
        return is_valid(paran_string, index + 1, count + 1);
    }else if(paran_string[index] == ')'){
        return is_valid(paran_string, index + 1, count - 1);
    }    else { // '*'
        return is_valid(paran_string, index + 1, count + 1) ||   // '('
               is_valid(paran_string, index + 1, count - 1) ||   // ')'
               is_valid(paran_string, index + 1, count);         // empty
    }
}

int main(){
    cout << is_valid("(*)",0,0);
}

class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                min++;
                max++;
            }else if(s[i] == ')'){
                if(min+max == 0){
                    return false;
                }
                if(min == 0){
                    max--;
                }else{
                    min--;
                    max--;
                }
            }else{
                if(min+max == 0){
                    max++;
                }else if(min == 0){
                    max++;
                }else{
                    min--;
                    max++;
                }
            }
        }
    return min == 0;
    }
};