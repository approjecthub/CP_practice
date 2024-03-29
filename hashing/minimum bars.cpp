//minimum bars: Given a string without spaces & a list of words. Write a function that finds min bars to be added the string, so that all resulting words are found in the list
//DSA levelup course problem:'minimum jump fox'

#include<bits/stdc++.h>
using namespace std;

int solve(string s, unordered_set<string> &uset){
    int n = s.size();
    if(n==0) return 0;
    else{
        if(uset.find(s) != uset.end()){
            return 0;
        }
        int ans = -1;
        for(int i=0; i<n; i++){
            string ss1 = s.substr(0, i+1);
            if(uset.find(ss1) != uset.end()){
                // cout<<ss1<<" , "<<s.substr(i+1, n-i-1)<<endl;
                
                int tempAns = solve(s.substr(i+1, n-i-1), uset);
                // cout<<tempAns<<endl;
                if(tempAns!=-1){
                    if(ans==-1){
                        ans = 1+tempAns;
                    }
                    else{
                        ans = min(ans, 1+tempAns);
                    }
                }
            }
        }
        
        return ans;
    }
}

int min_bars(string s, string words[], int n){
    //Complete this function return the min bars 
    // n is number of words
    unordered_set<string> uset;
    
    for(int i=0; i<n; i++){
        uset.insert(words[i]);
    }
    return solve(s, uset);
    
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
