#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){

    ll n;
    cin>>n;

    double ans=0;
    while(n--){
        ll a;
        cin>>a;

        ans=(4*a*a)/25;

        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    
}

int main(){
    sami();

     ami();

    return 0;
}