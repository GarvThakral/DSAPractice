#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool balancedParanthesis(string s){
    stack<int> s1;
    unordered_map<char,char> newMap;
    newMap['('] = ')';
    newMap['['] = ']';
    newMap['{'] = '}';
    for(char c:s){
        if(s1.empty()){
            if(c == '(' || c == '[' || c == '{'){
                s1.push(c);
            }else{
                return false;
            }
        }else if(c == '(' || c == '[' || c == '{'){
            s1.push(c);
        }else{
            if(c == ')'||c == ']'||c == '}'){
                if(newMap[s1.top()] == c){
                    s1.pop();
                }else{
                    return false;
                }
            }else{
                s1.push(c);
            }
        }
    }

    return s1.empty();
}

int main(){
    int res = balancedParanthesis("()");
    if(res == 1){
        cout << "true";
    }else{
        cout << "false";
    }
}