#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    int num_platforms = 0;
    vector<int> current_end;
    for(int i = 0 ; i < Arrival.size() ;i++){
        if(current_end.size() == 0){
            current_end.push_back(Departure[i]);
            num_platforms+=1;
        }else{
            bool canFit = false;
            int earliestFit = INT_MAX;
            int earliestIndex = 0;
            for(int j = 0 ; j < current_end.size() ;j++){
                if(current_end[j] < Arrival[i]){
                    canFit = true; 
                    if(current_end[j] < earliestFit){
                        earliestFit = current_end[j];
                        earliestIndex = j;
                    }
                }
            }
            if(!canFit){
                current_end.push_back(Departure[i]);
                num_platforms++;
            }else{
                current_end[earliestIndex] = Departure[i];
            }
        }
    }
    return num_platforms;
}

int main(){
    vector<int> arrival;
    vector<int> departure;
    cout << findPlatform(arrival,departure);
}