//minimum bars: Given a string without spaces & a list of words. Write a function that finds min bars to be added the string, so that all resulting words are found in the list
//DSA levelup course problem:'minimum jump fox'
#include <bits/stdc++.h>

using namespace std;
bool findWord(string words[], int n, string s)
{
    for (int i = 0; i < n; i++)
    {
        if (words[i] == s)
        {
            return true;
        }
    }
    return false;
}
int min_bars(string s, string words[], int n)
{
    //Complete this function return the min bars
    // n is number of words
    cout<<s<<endl;
    if (s == "")
    {
        return 0;
    }
    int ans = INT_MAX;
    int s_size = s.size();
    for (int j = 0; j < s_size; j++)
    {
        string t1 = s.substr(0, j + 1);
        if (findWord(words, n, t1))
        {
            string t2 = s.substr(j+1,s_size- (j + 1));
            if(t2==""){
                ans = min(ans, min_bars(t2,words,n));
            }
            ans = min(ans, 1+min_bars(t2,words,n));
        }
    }
    return ans;
}

int main()
{
    // string s = "helloworldhi";
    // string words[] = {"world", "hi", "hello", "helloworld", "batman"};
    //correct output: 1
    // string s = "codingminutes";
    // string words[] = {"coding", "minute", "hours", "s", "code", "cod", "ing"};
    //correct output: 2
    string s ="thequickbrownfoxjumpsoverthehighbridge";

string words[] = {"the","fox","thequickbrownfox", "jumps","lazy","lazyfox",

					"highbridge","the","over", "bridge","high","tall",

					"quick","brown"};
  //correct output: 4
    int n = sizeof(words) / sizeof(words[0]);
    cout << min_bars(s, words, n)<<endl;
    
    return 0;
}
