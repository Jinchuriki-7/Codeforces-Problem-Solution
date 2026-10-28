#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;

        vector<int> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());

        int cnt=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            cnt++;

            if(cnt*a[i]>=x){
                ans++;
                cnt=0;
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