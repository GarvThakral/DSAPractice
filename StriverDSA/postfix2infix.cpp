#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return true;
    }
    return false;
}


string post2in(string postfix){
    stack<string> s1;
    // AB-DE+F*/;
    for(char c:postfix){
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
    string answer = "";
    while(!s1.empty()){
        answer+=s1.top();
        s1.pop();
    }
    return answer;
}




int main(){
    cout << post2in("AB-DE+F*/");
}