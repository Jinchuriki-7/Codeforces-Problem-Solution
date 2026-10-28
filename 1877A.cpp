#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;
    while(t--){
       
    int n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n-1;i++){
        ll x;
        cin>>x;
        sum+=x;
    }
    cout<<-sum<<endl;
}
}

int main(){
    sami();

    ami();

    return 0;
}