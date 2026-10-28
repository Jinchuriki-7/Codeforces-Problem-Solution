#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n,k;
    while(cin>>n>>k){
        int ans=n;
        while(n>=k){
            int x=n/k;
            ans+=x;
            n=n%k+x;
        }
        cout<<ans<<endl;
    }
}

int main(){
    sami();
    ami();
    return 0;
}