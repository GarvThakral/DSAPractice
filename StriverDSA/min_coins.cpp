#include <iostream>
class Solution{
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
		int numCoins = 0;
		for(int i = coins.size()-1 ; i >= 0 ; i--){
			if(amount < coins[i]){
				continue;
			}
			numCoins += amount/coins[i];
			amount %= coins[i];
		}
		if(amount > 0){
			return -1;
		}
		return numCoins;
    }
};