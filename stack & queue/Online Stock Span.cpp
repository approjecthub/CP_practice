// https://leetcode.com/problems/online-stock-span/

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        pair<int, int> p(price, 1);

        if (st.size() == 0 || (st.size() > 0 && st.top().first > price))
        {
            st.push(p);
            return 1;
        }
        else
        {
            while (st.size() > 0 && st.top().first <= price)
            {
                p.second += st.top().second;
                st.pop();
            }
            st.push(p);
            return p.second;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/

vector<int> calculateSpan(int price[], int n)
{
    // Your code here
    stack<pair<int, int>> s1;
    vector<int> ans;
    s1.push({price[0], 0});
    for (int i = 0; i < n; i++)
    {
        //   cout<<price[i]<<" , "<<s1.size()<<endl;
        if (s1.size() > 0 && price[i] >= s1.top().first)
        {
            while (s1.size() > 0 && price[i] >= s1.top().first)
            {
                s1.pop();
            }
            if (s1.size() > 0)
            {
                ans.push_back(i - s1.top().second);
            }
            else
            {
                ans.push_back(i + 1);
            }
        }
        else
        {
            ans.push_back(1);
        }
        s1.push({price[i], i});
    }
    return ans;
}
