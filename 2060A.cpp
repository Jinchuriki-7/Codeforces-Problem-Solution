#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;
    while(t--){
    int a1,a2,a4,a5;
    cin>>a1>>a2>>a4>>a5;

    int x=a1+a2;
    int y=a4-a2;
    int z=a5-a4;

    int ans=1;

    if(x==y && y==z){
        ans=3;
    }
    else if(x==y || y==z || x==z){
        ans=2;
    }

    cout<<ans<<endl;
}
}

int main(){
    sami();

    ami();

    return 0;
}