#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int avgWait(vector<int> bt){
    int time = 0;
    int totalWait = 0;
    sort(bt.begin(),bt.end());
    for(int x:bt){
        totalWait+=time;
        time+=x;
    }
    return totalWait/bt.size();
}   

int main(){
    vector<int> bt = {4,3,7,1,2};
    cout << avgWait(bt);
}