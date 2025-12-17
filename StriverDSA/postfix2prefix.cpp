#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '/' || c == '^' || c == '*'){
        return true;
    }
    return false;
}


string postfixtoprefix(string expression){
    stack<string> s1;
    for(char c:expression){
        if(c == ' '){
            continue;
        }
        if(isOperator(c)){
            string top1 = s1.top();
            s1.pop();
            string top2 = s1.top();
            s1.pop();
            string temp = c + top2 + top1;
            s1.push(temp);
        }else{
            s1.push(string(1,c));
        }
    }
    return s1.top();
}


int main(){
    cout << postfixtoprefix("AB-DE+F*/");
}