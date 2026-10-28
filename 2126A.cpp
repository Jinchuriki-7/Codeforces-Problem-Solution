#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        char mn='9';

        for(int i=0;i<s.size();i++){
            mn=min(mn,s[i]);
        }

        cout<<mn<<endl;
    }
}


int main(){
    sami();

    ami();

    return 0;
}