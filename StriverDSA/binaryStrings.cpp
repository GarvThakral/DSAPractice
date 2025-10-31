#include <iostream>
#include <vector>
using namespace std;


vector<string> glob;
void generateBinaryStrings(int n ,string& current){
    if(current.size() == n){
        glob.push_back(current);
        return;
    }
    // Pick 0
    current+="0";
    generateBinaryStrings(n,current);
    current.pop_back();

    if (current.empty() || current.back() != '1') {
        current.push_back('1');
        generateBinaryStrings(n, current);
        current.pop_back();
    }
}

int main(){
    vector<string> temp ;
    string current = "";
    generateBinaryStrings(10,current);
    for(string str : glob){
        cout << str << endl;
    }
}
