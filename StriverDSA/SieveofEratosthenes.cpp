#include <iostream>
#include <vector>
using namespace std;


int sieveOf(int n){
    if(n == 2){
        return 0;
    }
    if(n <= 1){
        return 0;
    }
    vector<int> arr(n+1,1);
    for(int i = 2; i <= n ;i++){
        if(arr[i] == 1){
            for(long long j = (1LL*i*i) ; j <= n ;j+=i){
                arr[j] = 0;
            }
        }
    }
    int sum = 0;
    for(int i = 2;i<n;i++){
        if(arr[i] == 1){
            sum++;
        }
    }
    return sum;
}

vector<vector<int>> PrimeFactorisationQuery(vector<int> queries){
    vector<vector<int>> answers;
    int biggest = 0;
    for(int i = 0 ;i < queries.size() ;i++){
        biggest = max(biggest,queries[i]);
    }
    vector<int> arr(biggest+1,0);
    for(int i = 2 ; i < arr.size() ; i++){
        arr[i] = i;
    }
    for(int i = 2; i < arr.size() ; i++){
        if(arr[i] == i){
            for(int j = (i*i) ; j < arr.size() ;j+=i){
                if(arr[j] > i){
                    arr[j] = i;
                }
            }
        }
    }
    for(auto query:queries){
        vector<int> temp;
        while(query > 1){
            temp.push_back(arr[query]);
            query/=arr[query];
        }
        answers.push_back(temp);
    }
    return answers;
}

int main(){
    vector<int> queries = {2, 3, 4, 5, 6};
    vector<vector<int>> answer =  PrimeFactorisationQuery(queries);
    for(auto ans:answer){
        for(int it:ans){
            cout << it << ' ';
        }
        cout << endl;
    }
}