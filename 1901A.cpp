#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void ami(){
    int n,x;
    cin>>n>>x;

    vector<int>a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans=a[0];

    for(int i=1;i<n;i++){
        ans=max(ans,a[i]-a[i-1]);
    }

    ans=max(ans,2*(x-a[n-1]));

    cout<<ans<<"\n";
}

#define ll long long

int main(){
    sami();

     int t;
    cin>>t;

    while(t--){
        ami();
    }
    return 0;
}