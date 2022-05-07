/*
tokenization:
ip => "It is good"
op =>["It", "is", "good"], if delimeter is " "
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    getline(cin, input);
    
    //create a string stream object
    stringstream ss(input);
    
    string token;
    while(getline(ss, token, ' ')){
        cout<<token<<endl;
    }
    return 0;
}

int main()
{
    char c[1000];
    cin.getline(c, 1000);
    // cout<<strtok(c, " ")<<endl; //internally maintains the state of the string
    // that you passed in the last function call
    char *token = strtok(c, " ");
    while(token != NULL){
        cout<<token<<endl;
        token = strtok(NULL, " ");
    }
    return 0;
}