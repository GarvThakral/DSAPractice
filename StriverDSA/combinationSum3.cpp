class Solution {
public:
    vector<vector<int>> glob;
    void combinationSum3Temp(int k, int n,int index,vector<int> temp){
        if(temp.size() == k){
            if(n == 0){
                glob.push_back(temp);
                return;
            }
            return;
        }
        if(index > 9){
            return;
        }
        // Case Did not pick
        combinationSum3Temp(k,n,index+1,temp);

        // Case Picked Number
        temp.push_back(index);
        combinationSum3Temp(k,n-index,index+1,temp);
        temp.pop_back();

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        combinationSum3Temp(k,n,1,temp);
        return glob;
    }
};