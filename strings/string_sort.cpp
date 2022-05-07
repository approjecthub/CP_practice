
/*
https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/23915474#overview
** sort strings based on col number, where sort nature can be either numeric or lexicographical.
Input :
3
92 022
82 12
77 13
2 false numeric //col-2, reversal-false, sortType-numeric

Output :
82 12
77 13
92 022
*/

#include <bits/stdc++.h>

using namespace std;

string
getKeys(string line, int col)
{
    char *token = strtok((char *)line.c_str(), " ");
    while (col > 1 && token != NULL)
    {
        token = strtok(NULL, " ");
        col--;
    }
    return (string)token;
}

bool compNumerically(pair<string, string> p1, pair<string, string> p2)
{
    int num1 = stoi(p1.second);
    int num2 = stoi(p2.second);

    return num1 < num2;
}

bool complexicographically(pair<string, string> p1, pair<string, string> p2)
{
    return p1.second < p2.second;
}

int main()
{
    int n;
    cin >> n;
    cin.get(); // consume a line
    vector<string> lines;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        lines.push_back(s);
    }

    int col;
    string sortType, reversal;

    cin >> col >> reversal >> sortType;

    // 1.get keys
    vector<pair<string, string>> pairs;
    for (int i = 0; i < n; i++)
    {
        pairs.push_back(
            {lines[i], getKeys(lines[i], col)});
    }

    // 2.sort the array based on keys
    if (sortType == "numeric")
    {
        sort(pairs.begin(), pairs.end(), compNumerically);
    }
    else
    {
        sort(pairs.begin(), pairs.end(), complexicographically);
    }

    // 3. reverse the array
    if (reversal == "true")
    {
        reverse(pairs.begin(), pairs.end());
    }

    for (int i = 0; i < n; i++)
    {
        cout << pairs[i].first << endl;
    }
    return 0;
}
