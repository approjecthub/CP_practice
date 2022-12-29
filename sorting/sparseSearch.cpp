// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/24012216#learning-tools

// worst TC: O(n), but still it does better than linear search

#include <bits/stdc++.h>
using namespace std;

int sparseSearch(vector<string> word, string k)
{
    int l = 0, h = word.size() - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (word[mid] == "")
        {
            int lMid = mid - 1, rMid = mid + 1;
            while (lMid > l && word[lMid] == "")
            {
                lMid--;
            }
            while (rMid < h && word[rMid] == "")
            {
                rMid++;
            }
            if (word[lMid] == k)
            {
                return lMid;
            }
            else if (word[rMid] == k)
            {
                return rMid;
            }
            else if (word[lMid] < k && word[rMid] > k)
            {
                return -1;
            }
            else if (word[lMid] < k)
            {
                l = rMid + 1;
            }
            else if (word[rMid] > k)
            {
                h = lMid - 1;
            }
        }
        else
        {
            if (k > word[mid])
            {
                l = mid + 1;
            }
            else if (k < word[mid])
            {
                h = mid - 1;
            }
            else
            {
                return mid;
            }
        }
    }
    return -1;
}

int main()
{
    // vector<string> words = {"ai","","","bat", "","", "car", "", "", "dog", ""};
    // string k="bat";

    // vector<string> words = {"for", "geeks", "", "", "", "", "ide",
    //                   "practice", "", "", "", "quiz"};
    // string k="geeks";

    vector<string> words = {"for", "geeks", "", "", "", "", "ide",
                            "practice", "", "", "", "quiz"};
    string k = "ds";
    int ans = sparseSearch(words, k);
    cout << ans << endl;
    return 0;
}