#include<bits/stdc++.h>
using namespace std;

void replace_space(char *str){
    int spaceCount = 0, n = strlen(str);
    for(int i=0;i<n;i++ ){
        if(str[i]==' '){
            spaceCount++;
        }
    }

    int endIdx = n-1+spaceCount*(3-1);//' ' will be replaced with '%20'
    for(int i=n-1; i>=0;i--){
        if(str[i]==' '){
            str[endIdx] = '0';
            str[endIdx-1] = '2';
            str[endIdx-2] = '%';
            endIdx -= 3;
        }
        else{
            str[endIdx] = str[i];
            endIdx--;
        }
    }
}

int main(){
    char input[10000];
    cin.getline(input, 1000);
    replace_space(input);
    cout<<input<<endl;
    return 0;
}
