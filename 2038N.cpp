#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    string s;
    while(x--){
        cin>>s;

        if(s[0]>s[2]){
            s[1]='>';
        }
        else if(s[0]<s[2]){
            s[1]='<';
        }
        else{
            s[1]='=';
        }
        cout<<s[0]<<s[1]<<s[2]<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}