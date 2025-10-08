#include <iostream>
using namespace std;


void print1toN(int start , int n){
    cout << start << endl;
    if(start == n){
        return;
    }
    start+=1;
    print1toN(start,n);
}
void printNto1(int start , int n){
    cout << start << endl;
    if(start == n){
        return;
    }
    
    printNto1(start-1,n);
}

int sumOfNnatural(int n){
    if(n == 0){
        return 0;
    }
    return n+sumOfNnatural(n-1);
}

string reverseString(string s,int index){
    if(index == (s.size()-1)){
        string temp = "";
        return temp+s[index];
    }
    string temp = reverseString(s,index+1);
    return temp + s[index];
}

bool isPalindrome(string s,int index){
    if(index == s.size()/2){
        return true;
    }
    if(s[index]!=s[s.size()-1-index]){
        return false;
    }
    return isPalindrome(s,index+1);
}

int nthFibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1 || n == 2){
        return 1;
    }
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}

void subSequencesString(string s,int len){
    if(len  == s.size()){
        return;
    }
    cout << s.substr(s.size()-1-len,len);
    subSequencesString(s,len+1);
}

int main(){
    subSequencesString("garv",0);
    
}