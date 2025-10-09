#include <vector>
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
vector<vector<int>> glob ;
vector<vector<int>> combinationSum(int index , int target , vector<int> temp , vector<int>& candidates) {
    if(index == (candidates.size())){
        if(target == 0){
            glob.push_back(temp);
        }
        return glob;
    }
    // Picked
    if((target - candidates[index])>-1){
        vector<int> newTemp = temp;
        newTemp.push_back(candidates[index]);
        combinationSum(index,target-candidates[index],newTemp,candidates);
    }
    // Not picked
    combinationSum(index+1,target,temp,candidates);
    return glob;

}  


    double calculatePow(double x , long long int n){
        if(n  == 0){
            return 1;
        }
        if(n%2 == 0){
            return calculatePow(x*x,n/2);
        }
        return x*calculatePow(x,n-1);
    }

    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        if(x == 1){
            return 1;
        }

        bool neg = false;
        long long int nn = n;
        if(nn < 0){
            nn = -1*nn;
            neg = true;
        }
        double val = calculatePow(x,nn);
        if(neg){
            return 1/val;
        }
        return val;
    }
int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;    
    vector<vector<int>> combinations = combinationSum(0,target,{},candidates);
    
    for(auto vec : glob){
        for(auto item:vec){
            cout << item << " ";
        }
        cout << endl;
    }
}