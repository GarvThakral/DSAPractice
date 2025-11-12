#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> createPowerSet(vector<int> set){
    unordered_map<int,int> newMap;
    int index = 0;
    for(int i = set.size()-1 ; i >= 0 ;i--){
        newMap[i] = set[index];
        index++;
    }
    for(auto x:newMap){
        cout << x.first << " " << x.second << endl;
    }
    int numElements = (1 << set.size());
    vector<vector<int>> answer;
    
    for(int i = 0 ; i < numElements ;i++){
        vector<int> temp = {};
        for(int j = 0 ; j < set.size() ;j++){
            if ((i >> j) & 1){
                temp.push_back(newMap[j]);
            }
        }
        answer.push_back(temp);
    }
    return answer;
}

int main(){
    vector<vector<int>> answer = createPowerSet({1,2,3});
for (auto &v : answer) {
    cout << "{ ";
    for (auto &x : v) cout << x << " ";
    cout << "}\n";
}

}