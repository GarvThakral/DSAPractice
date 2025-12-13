class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s1;
        for(int i:asteroids){
            if(s1.empty()){
                s1.push(i);                
            }else if(i < 0){
                if(s1.top() < 0){
                    s1.push(i);
                    continue;
                }
                if(s1.top() > abs(i)){
                    continue;
                }else{
                    int last = -1;
                    while(!s1.empty() && s1.top() > 0 && s1.top() < abs(i)){
                        last = s1.top();
                        s1.pop();
                    }
                    if (!s1.empty() && s1.top() == abs(i)) {
                        s1.pop(); 
                        continue;
                    }
                    if(last != abs(i)){
                        if (s1.empty() || s1.top() < 0) {
                            s1.push(i);
                        }
                    }
                }
            }else{
                s1.push(i);
                continue;
            }
        }
        vector<int> answer;
        while(!s1.empty()){
            answer.push_back(s1.top());
            s1.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};