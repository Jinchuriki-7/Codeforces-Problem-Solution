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

    ll x;
    cin>>x;
    vector<ll>c(x);
    for(int j=0;j<x;j++){
        cin>>c[j];
    }
    ll ans=0;
    ll cnt=0;
   /* for(int i=0;i<n;i++){
        for(int j=0;j<x;j++){
        ans=v[i]+c[j];
        if(ans!=v[i] && ans!=c[i]){
            cout<<v[i]<<" "<<c[j]<<endl;
            return;
 
        }//lol
      }
    }
}*/
   for(int i=0;i<n;i++){
    for(int j=0;j<x;j++){
        ans=v[i]+c[j];
        cnt=0;

        for(int i=0;i<n;i++){
            if(ans==v[i]){
                cnt++;
            }
        }
        for(int j=0;j<x;j++){
            if(ans==c[j]){
                cnt++;
            }
        }
        if(cnt==0){
            cout<<v[i]<<" "<<c[j]<<endl;
            return;
        }
    }
   }

}

int main(){
    sami();

    ami();

    return 0;
}