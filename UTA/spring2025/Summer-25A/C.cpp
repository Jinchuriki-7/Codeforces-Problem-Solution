#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;
    int k,m;
    cin>>k>>m;

    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans=0;
    sort(v.begin(),v.end());

    for(int i=0;i<m;i++){
        cout<<v[i]<<" ";
        ans+=v[i];
    }
    for(int i=n-k;i<n;i++){
        cout<<v[i]<<" ";
        ans+=v[i];
    }
   cout<<endl;
    cout<<ans<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}