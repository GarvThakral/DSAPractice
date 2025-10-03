class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";
        for(int i = 0; i< s.size() ;i++){

            if(s[i] == ' '){
                if (!temp.empty()) words.push_back(temp);
                temp = "";
            }else{
                temp+=s[i];
            }
        }
        if (!temp.empty()) words.push_back(temp);

        string final = "";
        for(int i = words.size()-1 ; i >= 0 ;i--){
            if(words[i]!= " ") final+=words[i];
            if(i!=0) final+=" ";
        }
        return final;
    }
};

class Solution {
public:
    vector<vector<int>> countFN(string s){
        cout << s << endl;
        vector<int> nums;
        vector<int> counts;
        int count = 1;
        for(int i = 0 ; i < s.size()-1 ;i++){
            if(s[i] == s[i+1]){
                count++;
            }else{
                nums.push_back(s[i]%48);
                counts.push_back(count);
                count = 1;
            }
        }
        if(nums.empty()){
            nums.push_back(s[s.size()-1]%48);
            counts.push_back(count);
        }else{
                nums.push_back(s[s.size()-1]%48);
                counts.push_back(count);
        }

        return {nums,counts};
    }
    string sayFN(vector<vector<int>> vec){
        string answer = "";
        int index = 0;
        while(index < vec[0].size()){
            answer+=to_string(vec[1][index]);
            answer+=to_string(vec[0][index]);
            index++;

        }
        return answer;
    }
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string initial = "1";
        for(int i = 1; i < n ; i++){
            vector<vector<int>> mid = countFN(initial);
            initial = sayFN(mid);
        }
        return initial;
    }
};