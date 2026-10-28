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
      vector<ll>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
      }
      vector<ll>x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
      }
    ll mx=LLONG_MIN;
    for(int i=0;i<n;i++){
        
        mx=max(mx,v[i]);
    }
    ll ans=LLONG_MIN;
    for(int i=0;i<n;i++){
        
        ans=max(ans,c[i]);
    }
    ll cnt=LLONG_MIN;
    for(int i=0;i<n;i++){
        
        cnt=max(cnt,x[i]);
    }
    cout<<mx+ans+cnt<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}