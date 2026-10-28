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

    int m=n+n;

    vector<int>a(m);

    for(int i=0;i<m;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    int ans=0;

    for(int i=0;i<m;i+=2){
        ans+=a[i];
    }

    cout<<ans<<"\n";
}

}


int main(){
    sami();

    ami();

    return 0;
}