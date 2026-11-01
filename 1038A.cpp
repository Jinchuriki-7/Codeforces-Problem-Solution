#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
       int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt[26]={0};
    for(int i=0;i<n;i++){
        cnt[s[i]-'A']++;
    }
    int mn=INT_MAX;
    for(int i=0;i<k;i++){
        mn=min(mn,cnt[i]);
    }
    cout<<mn*k<<endl;
}



int main(){
    sami();

    ami();

    return 0;
}