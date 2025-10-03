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