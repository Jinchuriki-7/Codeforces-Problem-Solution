#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin >> t;

    while(t--){
        int m,a,b,c;
        cin>>m>>a>>b>>c;

        int r1=min(a,m);
        int r2=min(b,m);

        int empty=(m-r1)+(m-r2);

        int ans=r1+r2+min(c,empty);

        cout<<ans<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}