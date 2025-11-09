#include<bits/stdc++.h>
using namespace std;
// Brute Force Approach - TC-O(n2) and SC-O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Time Complexity : O(n2) and Space Complexity : O(1)
        int profit = 0;
        for(int i = 0; i < prices.size(); i++) {
            int buy = prices[i];
            for(int j = i+1; j < prices.size(); j++) {
                int sell = prices[j];
                profit = max(profit, sell-buy);
            }
        }
        return profit;
    }
};

// Optimal Approach - TC-O(n) and SC-O(1)
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else profit = max(profit, prices[i] - minPrice);
        }
        return profit;
    }
};
int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Maximum Profit (Brute Force): " << s.maxProfit(prices) << endl;
    Solution1 s1;
    cout << "Maximum Profit (Optimal): " << s1.maxProfit(prices) << endl;
    return 0;
}