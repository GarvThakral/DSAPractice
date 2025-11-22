#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> allDivisors(int num){
    vector<int> answers;    
    for(int i = 1 ; i <= sqrt(num);i++){
        if((num%i) == 0){
            answers.push_back(i);
            if((num/i)!=i){
                answers.push_back(num/i);
            }
        }
    }
    return answers;
}

int main(){
    int num = 35;
    vector<int> answers = allDivisors(num);
    for(auto ans:answers){
        cout << ans << ' ';
    }
}