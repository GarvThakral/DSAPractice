#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int num_meetings(vector<int> start , vector<int> end){
    vector<pair<int,int>> pairVec;
    for(int i = 0 ; i < start.size() ;i++){
        pair<int,int> newPair = {start[i],end[i]};
        pairVec.push_back(newPair);
    }
    sort(pairVec.begin(),pairVec.end(),[](pair<int,int> pairOne,pair<int,int> pairTwo){
        return pairOne.second < pairTwo.second;
    });
    int lastEnd = 0;
    int num_meets = 0;
    for(auto pairs:pairVec){
        if(pairs.first > lastEnd){
            num_meets++;
            lastEnd = pairs.second;
        }
    }
    return num_meets;
}

int main(){
    vector<int> start = {10, 12, 20};
    vector<int> end = {20, 25, 30};
    cout << num_meetings(start,end);
};