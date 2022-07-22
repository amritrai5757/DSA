int maxProfit(vector<int>& prices, int cooldown,int fee) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            buy[i]=max(buy[i-1],sell[i-1]-prices[i]);
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]-fee);                             
        }
        return sell[n-1];   
}
// If cooldown asked with ∞ transactions then solution will be o(n^2) with assuming transactions=n-1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/1167126/C%2B%2B-Solution-to-all-the-Stock-Problems-using-Dynamic-Programming
