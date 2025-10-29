#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> glob;
    bool isPalindrome(string s){
        string copy = s;
        reverse(s.begin(),s.end());
        return s == copy;
    }

    void partitionTemp(string s ,int startIndex,vector<string> temp){
        if(startIndex == s.size()){
            glob.push_back(temp);
            return;
        }
        for(int i = startIndex ; i < s.size() ;i++){
            if(isPalindrome(s.substr(startIndex,i - startIndex + 1))){
                temp.push_back(s.substr(startIndex,i - startIndex + 1));
                partitionTemp(s,i+1,temp);
                temp.pop_back();
            }
        }
    } 
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        partitionTemp(s,0,temp);
        return glob;
    }
};

int main(){
    Solution s1;
    vector<vector<string>> result = s1.partition("hello");
    for(auto part:result){
        for(string palindrome:part){
            cout << palindrome << ", ";
        }
        cout << endl;
    }
}
