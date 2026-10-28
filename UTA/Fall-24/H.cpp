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
    for(int i=0;i<n;i++){
        if(v[i]==x){
           cout<<"YES"<<endl;
             return;
    }
   }
    cout<<"NO"<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}