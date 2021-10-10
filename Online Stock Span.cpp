//https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        pair<int, int> p(price,1);
        
        if(st.size()==0 || (st.size()>0 && st.top().first>price)){
            st.push(p);
            return 1;
        }
        else{
            while(st.size()>0 && st.top().first<=price){
                p.second+=st.top().second ;
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
