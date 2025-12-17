#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


string removeKdigits(string num, int k) {
    int removed = 0;
    stack<int> s1;
    for(int i = 0 ; i < num.size() ;i++){
        int cha = num[i]-'0';
        if(removed == k){
            for(int j = i+1 ; j < num.size() ;j++){
                s1.push(num[j]-'0');
            }
            break;
        }
        if(s1.empty()){
            s1.push(cha);
        }else if(s1.top() > cha){
            while(!s1.empty() && s1.top() > cha && removed < k){
                removed++;
                s1.pop();
            }
            s1.push(cha);
        }else{
            s1.push(cha);
        }
    }
    string answer = "";
    while(!s1.empty()){
        answer += to_string(s1.top());
        s1.pop();
    }
    reverse(answer.begin(),answer.end());
    if(removed < k){
        int missing = k - removed;
        answer = answer.substr(0, answer.size() - missing);

    }
    // remove leading zeros
int idx = 0;
while (idx < answer.size() && answer[idx] == '0') idx++;
answer = answer.substr(idx);

// handle empty
if (answer.empty()) return "0";

    return answer;
}

int main(){
    string c = "1432219";
    cout << removeKdigits(c,3);
}