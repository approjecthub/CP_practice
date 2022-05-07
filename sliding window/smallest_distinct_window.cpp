//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5212642#overview

/*
Given a string, find the smallest window (substring) which contains all distinct characters of the given input string.

I/P1: aabcbcdbcaaad,    O/P1: dbca
I/P2: aaaa,    O/P1: a
*/


#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t) {
        unordered_map<char, int> smap, tmap;
        
        for(char c: t){
            tmap[c]++;
        }
        
        int sn = s.size(), tn = t.size(), i = 0, j=0, track = 0, ansStrtIdx = 0, ansSize = 0;
        
        while(i<sn){
            smap[s[i]]++;
            if(tmap[s[i]]>0 && smap[s[i]] == tmap[s[i]]){
                track+= tmap[s[i]];
            }
            // cout<<s[i]<<" , "<<tmap[s[i]]<<" , "<< smap[s[i]]<<" , "<<track<<endl;
            if(track==tn){
                // cout<<"before"<<endl;
                // printMap(smap);
                while(j<=i && track==tn){
                    // cout<<s[j]<<" , "<<tmap[s[j]]<<" , "<<smap[s[j]]<<endl;
                    if(tmap[s[j]]==0 || smap[s[j]]>tmap[s[j]]){
                        smap[s[j]]--;
                        j++;
                    }
                    else{
                        break;
                    }
                }
                int currAnsSize = i-j+1;
                string currAns = s.substr(j, currAnsSize);
                // cout<<currAns<<endl;
                if(ansSize == 0 || ansSize> currAnsSize){
                    ansSize = currAnsSize;
                    ansStrtIdx = j;
                }
                
                smap[s[j]]--;
                track -= tmap[s[j]];
                j++;
                // cout<<j<<endl;
                // cout<<"after"<<endl;
                // printMap(smap);
            }
            i++;
        }
        
        return s.substr(ansStrtIdx, ansSize);
    }
string smallestWindow(string str){
    //Complete this method
    int n = str.size();
    unordered_set<char> uset;
    for(int i=0; i<n; i++){
        uset.insert(str[i]);
    }
    
    string t = "";
    for(auto it: uset){
        t+= it;
    }
    
    return minWindow(str, t);
}
int main()
{
    cout<<smallestWindow("aaaaa");
    return 0;
}
