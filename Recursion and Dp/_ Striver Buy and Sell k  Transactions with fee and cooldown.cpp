int maxProfit(int transactions, vector<int>& prices, int fee) {
        
        vector<vector<int>>buy (transactions,vector<int>(prices.size(),0);// For 1 transaction : buy[1][n]=buy[n]
        vector<vector<int>>sell (transactions,vector<int>(prices.size(),0);                 
        for(int i=0; i<transactions;i++) buy[i][0] = -prices[0];      
        
        for(int i=1; i<prices.size(); i++) {                           
            int prevInvestment = 0;                                     // For 1 transaction : no meaning wheather u write or not  
            for(int j=0; j<transactions; j++) {                         // For 1 transaction : for(i=0 to 0) = 1 times so you can ignore this loop
                buy[j][i] = max(buy[j][i-1], prevInvestment-prices[i]); // gives negative max  : means lowest price to buy
                sell[j][i] = max(sell[j][i-1], buy[j][i-1] + prices[i]-fee);
                prevInvestment = i-cooldown>0?sell[j][i-cooldown]:0;    // Stores previous sell, For 1 transaction : no meaning wheather u write or not                    
            }
        }
        int ans = 0;
        for(int i=0; i<transactions; i++) ans = max(ans,sell[i][prices.size()-1]);
        return ans;
}

