class Solution {
public:
    int compress(vector<char>& chars) {
        int groupLen = 1;
        string answer = "";
        if(chars.size() == 1){
            return 1;
        }
        for(int i = 0; i  < chars.size()-1 ;i++){
            if(chars[i] == chars[i+1]){
                groupLen+=1;
            }else{
                if(groupLen > 1){
                    answer+=chars[i]+to_string(groupLen);
                }else{
                    answer+=chars[i];
                }
                groupLen = 1;
            }
            if(i == chars.size()-2){
                if(chars[i] == chars[i+1]){
                    answer+=chars[i]+to_string(groupLen);

                }else{
                    answer+=chars[i+1];

                }
            }
        }
        cout << answer << endl;
        chars = {};
        for(char c : answer){
            chars.push_back(c);
        }
        return chars.size();
    }
};