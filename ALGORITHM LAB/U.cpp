#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    string s,t;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]!='+'){
            t+=s[i];
        }
    }
    sort(t.begin(),t.end());
    for(int i=0;i<t.size();i++){
        cout<<t[i];
        if(i!=t.size()-1){
            cout<<"+";
        }
    }
    cout<<endl;
    
}


int main(){
    sami();

    ami();

    return 0;
}