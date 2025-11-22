#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool isPrime(int num) {
    if (num <= 1) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

vector<int> primeFactors(int num){
    vector<int> answers;    
    for(int i = 1 ; i <= sqrt(num);i++){
        if((num%i) == 0){
            if(isPrime(i)){
                answers.push_back(i);
            }
            if((num/i) != i){
                if(isPrime(num/i)){
                    answers.push_back(i);
                }
            }
        }
    }
    return answers;
}
vector<int> primeFactorsOptimal(int num){
    vector<int> answers;
    int startNum = num;
    if(num <= 1) return answers;
    if(num == 2) return {2};     
    for(int i = 2 ;  i * i <= num;i++){
        if((num%i) == 0){
            answers.push_back(i);
            while((num%i) == 0){
                num /= i;
            }
        }
    }
    if(num != 1){
        answers.push_back(num);
    }
    return answers;
}

int main(){
    int num = 35;
    vector<int> answers = primeFactorsOptimal(num);
    for(auto ans:answers){
        cout << ans << ' ';
    }
}