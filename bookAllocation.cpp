    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <climits>
    #include <numeric>
    using namespace std;

    int countStudents(vector<int> pages , int minMaxPages){
        int student = 1;
        int pagesHolding = 0;
        for(int i = 0;i<pages.size();i++){
            if(pagesHolding+pages[i] <= minMaxPages){
                pagesHolding+=pages[i];
            }else{
                student+=1;
                pagesHolding = pages[i];
            }
        }
        return student;
    }


    int findPages(vector<int> &nums, int m)  {
        int size = nums.size();
        if(size < m){
            return -1;
        }
        int ans = INT_MIN;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = (low+high)/2;
            int numStu = countStudents(nums , mid);
            if(numStu <= m){
                ans = mid; 
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int main(){
        vector<int> books = {12, 34, 67, 90};
        int num = 2;
        int ans = findPages(books,num);
        cout << ans;
    }
