#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    int x;
    cin>>x;

    int mn=x,mx=x;
    for(int i=1;i<n;i++){
        cin>>x;
        mn=min(mn,x);
        mx=max(mx,x);
    }

    cout<<mx-mn+1-n<<endl;
}


int main(){
    sami();

    ami();

    return 0;
}