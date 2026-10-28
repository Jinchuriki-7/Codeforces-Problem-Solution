#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int a,b,c;
    cin>>a>>b>>c;

    int m=max({a,b,c});
    int n=min({a,b,c});

    int ans=m-n;

    cout<<ans<<endl;

}

int main(){
    sami();

    ami();

    return 0;
}