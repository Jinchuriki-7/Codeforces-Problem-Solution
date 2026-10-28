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

        vector<ll>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        sort(a.begin(),a.end());

        ll ans=0;

        for(int i=0;i<n;i+=2){
            ll diff=a[i+1]-a[i];
            if(diff>ans){
                ans=diff;
            }
        }

        cout<<ans<<"\n";
    }

}


int main(){
    sami();

    ami();

    return 0;
}