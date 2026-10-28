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
    vector<ll>ans(n);
    for(int i=0;i<n;i++){
        ans[i]=v[i]*c[i];
    }
    sort(ans.rbegin(),ans.rend());
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}    

int main(){
    sami();

    ami();

    return 0;
}