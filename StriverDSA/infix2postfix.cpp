#include <iostream>
#include <stack>
using namespace std;

int return_priority(char op){
    switch (op)
    {
    case '^':
        return 3;
        break;
    case '*':
        return 2;
        break;
    
    case '/':
        return 2;
        break;
    
    case '+':
        return 1;
        break;
    
    case '-':
        return 1;
        break;
    
    default:
        break;
    }
    return 0;
}


string infix_to_postfix(string expression){
    stack<char> operator_stack;
    string answer = "";
    for(char c:expression){
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
            if(operator_stack.empty()){
                operator_stack.push(c);
            }else{
                while(!operator_stack.empty() &&
                        return_priority(operator_stack.top()) >= return_priority(c) && operator_stack.top()!='(')
                    {
                        answer.push_back(operator_stack.top());
                        operator_stack.pop();
                    }
                    operator_stack.push(c);
            }
        }else if(c == '('){
            operator_stack.push(c);
        }        else if(c == ')'){
            while(operator_stack.top()!='('){
                answer.push_back(operator_stack.top());
                operator_stack.pop();
            }
            operator_stack.pop();
        }        else{
            answer.push_back(c);
        }
    }
    while(!operator_stack.empty()){
        if(operator_stack.top()!='(' && operator_stack.top()!=')' ){
            answer.push_back(operator_stack.top());
        }
        operator_stack.pop();
    }
    return answer;
}


int main(){

    cout << infix_to_postfix("A + B * (C ^ D - E)");

}