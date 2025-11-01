#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int binary_to_int(string bitString){
    int n = bitString.size();
    int index = 1;
    u_int32_t total = 0;
    for(char c:bitString){
        total += (static_cast<int>(pow(2,n-index))*(c-'0'));
        index++;
    }
    return total;
}

string int_to_binary(int num){
    string answer = "";
    if(num == 0){
        return "0";
    }
    while(num != 1){
        if(num%2 == 1){
            answer += '1';
        }else{
            answer += '0';
        }
        num /= 2;
        cout << num << endl;
    }
    answer+='1';
    reverse(answer.begin(),answer.end());
    return answer;
}

int main(){
    // int number = binary_to_int("101101001010100");
    // cout << number;
    cout << int_to_binary(13) << endl;
    return 0;
}