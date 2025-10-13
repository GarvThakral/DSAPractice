class Solution {
public:
    bool isValid(string paranthesis){
        stack<char> validPar;
        for(char c :paranthesis){
            if(c == ')' && validPar.empty()){
                return 0;
            }
            if(c == '(' && validPar.empty()){
                validPar.push(c);
                continue;
            }
            if(c == '('){
                validPar.push(c);
                continue;
            }
            if(c == ')' && validPar.top() == '('){
                validPar.pop();
                continue;
            }
            if(c == ')'){
                validPar.push(c);
            }
        }
            if(!validPar.empty()){
                return 0;
            }
            return 1;
    };
    vector<string> glob;

    void generator(int n , int index , string temp){
        if(temp.size() == 2*n && isValid(temp)){
            glob.push_back(temp);
            return;
        }
        if(temp.size() > 2*n){
            return;
        }
        string temptemp = temp;
        temp += "(";

        generator(n,index+1,temp);
        temptemp += ")";

        generator(n,index+1,temptemp);
    } 
    
    vector<string> generateParenthesis(int n) {
        string temp = "";
        glob.clear();
        generator(n,0,temp);
        return glob;
    }
};