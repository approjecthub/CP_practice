//https://leetcode.com/problems/minimum-window-substring/

//#################################### solution-1 ###################################################
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int ns = s.length();
        int nt = t.length();

        if (ns < nt)
        {
            return "";
        }
        if (ns == nt)
        {
            string ans = s;
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if (s == t)
            {
                return ans;
            }
            return "";
        }

        string ans = "";

        unordered_map<char, int> umapt, umaps;

        for (int i = 0; i < nt; i++)
        {
            if (umapt.find(t[i]) == umapt.end())
            {
                umapt[t[i]] = 1;
            }
            else
            {
                umapt[t[i]]++;
            }
        }

        int cnt = 0, len = INT_MAX, strt_idx = 0;

        for (int i = 0; i < ns; i++)
        {
            if (umapt.find(s[i]) != umapt.end())
            {
                if (umaps.find(s[i]) == umaps.end())
                {
                    umaps[s[i]] = 1;
                }
                else
                {
                    umaps[s[i]]++;
                }
                if (umapt[s[i]] == umaps[s[i]])
                {
                    cnt += umapt[s[i]];
                }
            }

            if (cnt == nt)
            {
                while (strt_idx < i)
                {
                    if (umapt.find(s[strt_idx]) != umapt.end())
                    {
                        umaps[s[strt_idx]]--;
                        if (umaps[s[strt_idx]] < umapt[s[strt_idx]])
                        {
                            cnt -= umapt[s[strt_idx]];
                            break;
                        }
                    }
                    strt_idx++;
                }

                if (len > i - strt_idx)
                {
                    ans = s.substr(strt_idx, i - strt_idx + 1);
                    len = i - strt_idx;
                }

                strt_idx++;
            }
        }
        return ans;
    }
};

//#################################### solution-2 ###################################################
class Solution {
public:
    void printMap(unordered_map<char, int> &umap){
        cout<<"###############################"<<endl;
        for(auto it: umap){
            if(it.second>0)
            cout<<it.first<<" : "<<it.second<<endl;
        }
        cout<<"###############################"<<endl;
    }
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
};