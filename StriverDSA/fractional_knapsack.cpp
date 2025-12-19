    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <map>
    #include <algorithm>
    using namespace std;
double max_value(vector<vector<int>> nums , int weight){   // 🔹 int → double
    vector<pair<double, pair<int,int>>> newMap;

    for(int i = 0 ; i < nums.size() ; i++){
        double power = (double)nums[i][0] / nums[i][1];
        newMap.push_back({power, {nums[i][0], nums[i][1]}});
    } 

    // 🔹 MUST sort by ratio
    sort(newMap.begin(), newMap.end());

    double totalVal = 0;        // 🔹 int → double
    int totalWeight = 0;

    for(int i = newMap.size()-1 ; i >= 0 ; i--){
        if(totalWeight == weight) break;

        int weightLeft = weight - totalWeight;
        int itemWeight = newMap[i].second.second;
        int itemValue  = newMap[i].second.first;
        double ratio   = newMap[i].first;

        if(weightLeft < itemWeight){
            totalVal += ratio * weightLeft;   
            break;
        } else {
            totalWeight += itemWeight;
            totalVal += itemValue;
        }
    }
    return totalVal;
}


    int main(){
        vector<vector<int>> nums= {{100,20},{60,10},{100,50},{200,50}};
        int weight = 90;
        cout << max_value(nums,weight);
    }
