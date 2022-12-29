// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/23424862#overview

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int n, k;
    unordered_map<int, int> left, right;
    vector<int> arr;
    cin >> n >> k;
    int num;
    while (cin >> num)
    {
        arr.push_back(num);
        right[num]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        right[arr[i]]--;
        if (arr[i] % k == 0)
        {
            ans += (right[arr[i] * k] * left[arr[i] / k]);
        }

        left[arr[i]]++;
    }
    cout << ans << endl;
    return 0;
}