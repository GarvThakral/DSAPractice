class Solution {
public:
    unordered_map<int, string> numMap = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    vector<string> glob;
    void letterCombinationsTemp(string digits,int index,string temp) {
        if(temp.size() > digits.size()){
            return;
        }
        if(index == digits.size()){
            glob.push_back(temp);
            return;
        }
        for(char c:numMap[digits[index] - '0']){
            temp.push_back(c);
            letterCombinationsTemp(digits,index+1,temp);
            temp.pop_back();
        }
        

    }   
    vector<string> letterCombinations(string digits) {
        string temp = "";
        letterCombinationsTemp(digits , 0  , temp);
        return glob;
    }
};