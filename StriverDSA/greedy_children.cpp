#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.beign(),g.end());
        sort(s.beign(),s.end());
        int i = 0 ; 
        int j= 0;
        int satisfied_children = 0;
        while(i < g.size() && j < s.size()){
            if(g[i]<=s[j]){
                i++;
                j++;
                satisfied_children++;
            }else if(g[i] > s[j]){
                j++;
            }
        }
        return satisfied_children;
    }
};
int main(){

}
