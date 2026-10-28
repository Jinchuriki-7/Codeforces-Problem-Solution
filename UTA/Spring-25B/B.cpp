#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    ll n;
    cin>>n;

    ll a;
    cin>>a;
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        if(v[i]==a){
           cout<<i+1<<endl;
           return;
        }
    }
}

int main(){
    sami();

    ami();

    return 0;
}