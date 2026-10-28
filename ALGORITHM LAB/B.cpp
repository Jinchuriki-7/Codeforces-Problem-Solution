#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;

    while(t--){
        ll n,x,y,d;
        cin>>n>>x>>y>>d;

        ll ans=-1;
        if(abs(x-y)%d==0){
            ans=abs(x-y)/d;
        }
        if((y-1)%d==0){
            ll a=(x-1+d-1)/d+(y-1)/d;

            if(ans==-1||a<ans){
                ans=a;
            }
        }
        if((n-y)%d==0){
            ll a=(n-x+d-1)/d+(n-y)/d;

            if(ans==-1||a<ans){
                ans=a;
            }
        }

        cout<<ans<<endl;
    }
}

int main(){
    sami();
    ami();
    return 0;
}