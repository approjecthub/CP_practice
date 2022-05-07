//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5212530#overview
#include <bits/stdc++.h>

using namespace std;

// string normalizeWord(string word){
//     word[0] = toupper(word[0]);
//     for(int i=1; i<word.size(); i++){
//         word[i] = tolower(word[i]);
//     }
    
//     return word;
// }
// string normalize(const string &sentence) {
//     string copy = sentence;
    
//     char *token = strtok((char *)copy.c_str(), " ");
//     string ans = "";
//     while(token!=NULL){
//         if(ans.size()==0){
//             ans += normalizeWord((string)token);
//         }
//         else{
//             ans += " "+normalizeWord((string)token);
//         }
//         token = strtok(NULL, " ");
//     }

//     return ans;
// }

string normalize(const string &sentence) {
    string copy = sentence;
    
    for(int i=0; i<copy.size(); i++){
        if(copy[i]!=' '){
            if((i>0 && copy[i-1] == ' ') || i==0){
                copy[i] = toupper(copy[i]);
            }
            else{
                copy[i] = tolower(copy[i]);
            }
        }
    }

    return copy;
}

int main()
{
    cout<<normalize("  this IS gooD");
    return 0;
}
