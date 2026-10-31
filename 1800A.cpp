#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            s[i]=tolower(s[i]);
        }
        string x="";
        x+=s[0];
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                x+=s[i];
            }
        }
        if(x=="meow"){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}

int main(){
    sami();

    ami();

    return 0;
}