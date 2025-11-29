#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


bool isOperator(char c){
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^'){
        return true;
    }
    return false;
}


string prefixtoinfix(string prefix){
    reverse(prefix.begin(),prefix.end());
    stack<string> s1;
    for(char c:prefix){
        if(c == ' '){
            continue;
        }
        if(isOperator(c)){
            string top1 = s1.top();
            s1.pop();
            string top2 = s1.top();
            s1.pop();
            string temp = '(' + top2 + c + top1 + ')';
            s1.push(temp);
        }else{
            s1.push(string(1, c));
        }
    }
    string answer;
    while(!s1.empty()){
        answer+=s1.top();
        s1.pop();
    }
    return answer;
}

int main(){
    cout << prefixtoinfix("*+PQ-MN");
}