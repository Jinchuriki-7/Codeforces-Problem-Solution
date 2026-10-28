#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    ll n;
    cin>>n;

    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll ans=INT_MAX;
    ll cnt=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,v[i]);

    }
    v.erase(remove(v.begin(),v.end(),ans),v.end());
    for(int i=0;i<n;i++){
        cnt=min(cnt,v[i]);
    
    }
    cout<<cnt<<endl;
    
}

int main(){
    sami();

    ami();

    return 0;
}