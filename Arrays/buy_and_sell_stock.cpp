class Solution {
public:
    int maxProfit(vector<int>& prices)
    {      
     int minimum=INT_MAX;
    int profit=0;
        
        for(int i=0;i<prices.size();i++)
        {
            minimum=min(minimum,prices[i]); //It will give the minimum on the left side
            int val=prices[i]-minimum;
            profit=max(val,profit);
        }
        
        return profit;
    }
};