class Solution {
public:
    bool checkIfPangram(string sentence) {
        int numUnique = 0;
        unordered_map<char , int> newMap;
        for(char c :sentence){
            if(newMap.find(c)!=newMap.end()){

            }else{
                newMap[c] = 1;
                numUnique++;
            }
        }
        return numUnique == 26;
    }
};