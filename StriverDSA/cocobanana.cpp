#include <bits/stdc++.h>
using namespace std;

long long int calcHours(const vector<int>& nums, long long int speed) {
    long long int hours = 0;
    for (int i = 0; i < nums.size(); i++) {
        hours += ceil((double)nums[i] / speed);
    }
    return hours;
}

int minEatingSpeed(vector<int>& piles, int h) {
    long long int maxi = 0;
    for (int x : piles) {
        if (x > maxi) {
            maxi = x;
        }
    }
    int ans = 0;
    long long int low = 1;
    long long int high = maxi;
    while (low <= high) {
        long long int mid = low + (high - low) / 2;
        long long int hours = calcHours(piles, mid);
        if (hours > h) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> piles = {805306368, 805306368, 805306368};
    int h = 1000000000;

    cout << minEatingSpeed(piles, h) << endl;

    return 0;
}
