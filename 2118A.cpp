#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    int n,k;
    while(x--){
        cin>>n>>k;

        string ans(k,'1');
        ans+=string(n-k,'0');

        cout<<ans<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}