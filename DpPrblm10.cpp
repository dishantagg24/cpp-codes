//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Those who cannot remember the past are condemned to repeat it ~DP

//*Buy & Sell Stocks Problems (max profit)
// buy & sell stocks only once
// buy & sell stocks multiple times (imp.)
// buy & sell stocks at most 2 times (imp.)
// buy & sell stocks at most k times (similar as prev ques.)
// buy & sell stocks with cooldown i.e. you can not buy on next day after selling stocks(only a minor change)
// buy & sell stocks with transaction fee (a transaction fee will be charged when u sell the stocks)

//*Buy & Sell stocks only once
// Time Complexity:- O(n)
// Space Complexity:- O(n)
int buySellOnce(vector<int> &prices)
{
    int buy_price = prices[0];
    int profit = INT_MIN;
    for (int i = 1; i < prices.size(); i++)
    {
        profit = max(profit, prices[i] - buy_price);
        buy_price = min(buy_price, prices[i]);
    }
    if (profit < 0)
    {
        return 0;
    }
    return profit;
}

//*Buy & Sell Stocks Multiple Times
// recursive
// Time Complexity:- O(2^n)
// Space Complexity:- O(n)
int buySellMultiple(int idx, int buy, vector<int> &prices, int n)
{
    if (idx == n)
    {
        return 0;
    }
    if (buy)
    {
        int not_buy_stocks = buySellMultiple(idx + 1, 1, prices, n);
        int buy_stocks = -prices[idx] + buySellMultiple(idx + 1, 0, prices, n);
        return max(not_buy_stocks, buy_stocks);
    }
    int not_sell_stocks = buySellMultiple(idx + 1, 0, prices, n);
    int sell_stocks = prices[idx] + buySellMultiple(idx + 1, 1, prices, n);
    return max(not_sell_stocks, sell_stocks);
}

// bottom up
// Time Complexity:- O(n)
// Space Complexity:- O(n)
int buySellMultiple1(vector<int> &prices, int n)
{
    int dp[n + 1][2];
    dp[n][0] = dp[n][1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                dp[i][j] = max(dp[i + 1][j], -prices[i] + dp[i + 1][0]);
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], prices[i] + dp[i + 1][1]);
            }
        }
    }
    return dp[0][1];
}

// bottom up with space optimisation
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int buySellMultiple2(vector<int> &prices, int n)
{
    int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
    aheadNotBuy = aheadBuy = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        curBuy = max(aheadBuy, -prices[i] + aheadNotBuy);
        curNotBuy = max(aheadNotBuy, prices[i] + aheadBuy);
        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }
    return aheadBuy;
}

//*Buy & Sell Stocks at most 2 times
// recursive
// Time Complexity:- O(2^n)
// Space Complexity:- O(n)
int buySellTwoTimes(int idx, int buy, vector<int> &prices, int n, int cap)
{
    if (idx == n || cap == 0)
    {
        return 0;
    }
    if (buy)
    {
        int not_buy_stocks = buySellTwoTimes(idx + 1, 1, prices, n, cap);
        int buy_stocks = -prices[idx] + buySellTwoTimes(idx + 1, 0, prices, n, cap);
        return max(not_buy_stocks, buy_stocks);
    }
    int not_sell_stocks = buySellTwoTimes(idx + 1, 0, prices, n, cap);
    int sell_stocks = prices[idx] + buySellTwoTimes(idx + 1, 1, prices, n, cap - 1);
    return max(not_sell_stocks, sell_stocks);
}

// bottom up
// Time Complexity:- O(n*2*3)
// Space Complexity:- O(n*2*3)
int buySellTwoTimes1(vector<int> &prices, int n)
{
    int dp[n + 1][2][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[i][j][0] = 0;
        }
    }
    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            dp[n][j][k] = 0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 1; k < 3; k++)
            {
                if (j == 1)
                {
                    dp[i][j][k] = max(dp[i + 1][j][k], -prices[i] + dp[i + 1][0][k]);
                }
                else
                {
                    dp[i][j][k] = max(dp[i + 1][j][k], prices[i] + dp[i + 1][1][k - 1]);
                }
            }
        }
    }
    return dp[0][1][2];
}

// bottom up with space optimisation
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int buySellTwoTimes2(vector<int> &prices, int n)
{
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 1; k < 3; k++)
            {
                if (j == 1)
                {
                    curr[j][k] = max(after[j][k], -prices[i] + after[0][k]);
                }
                else
                {
                    curr[j][k] = max(after[j][k], prices[i] + after[1][k - 1]);
                }
            }
        }
        after = curr;
    }
    return after[1][2];
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << buySellOnce(prices);
    return 0;
}