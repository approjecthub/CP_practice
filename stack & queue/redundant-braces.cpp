// https://www.interviewbit.com/problems/redundant-braces/
#include <bits/stdc++.h>
using namespace std;

int braces(string A)
{
    stack<pair<char, bool>> st;
    for (auto it : A)
    {
        // cout<<it<<endl;
        if (it == '(' || it == '{' || it == '[')
        {
            st.push({it, false});
        }
        else if (it == '+' || it == '-' || it == '*' || it == '/')
        {
            if (st.size() > 0 && st.top().second == false)
            {
                pair<char, bool> p = st.top();
                p.second = true;
                st.pop();
                st.push(p);
            }
        }
        else if (it == ')' || it == '}' || it == ']')
        {
            if (st.top().second == false)
                return 1;
            st.pop();
        }
    }

    return 0;
}
