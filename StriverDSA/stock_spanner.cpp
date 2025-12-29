class StockSpanner {
public:
    stack<pair<int,int>> s1;
    int index=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int pgeIndex = 0;
        if(s1.empty()){
            pgeIndex = -1;
            s1.push({price,index});
        }else{
            if(s1.top().first > price){
                pgeIndex = s1.top().second;
                s1.push({price,index});
            }else{
                while(!s1.empty() && s1.top().first <= price){
                    s1.pop();
                }
                if(s1.empty()){
                    pgeIndex = -1;
                    s1.push({price,index});
                }else{
                    pgeIndex = s1.top().second;
                    s1.push({price,index});
                }
            }
        }
        int count = index - pgeIndex; 
        index++;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */