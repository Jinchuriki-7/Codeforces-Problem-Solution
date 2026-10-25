#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    while(n--){
        int x;
        cin>>x;

        int cnt=0;
        
        while(x>0){
            int d=x%10;
            if(d==4||d==7){
                cnt++;
            }
            x/=10;
        }
        if(cnt<=k){
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}