#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    while(n--){
        int s;
        cin>>s;
        
        vector<int>v(s);
        for(int i=0;i<s;i++){
            cin>>v[i];
        }

        int ans=INT_MIN;
        int mn=v[s-1];

        for(int i=s-2;i>=0;i--){
            ans=max(ans,v[i]-mn);
            mn=min(mn,v[i]);
        }
        cout<<ans<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}