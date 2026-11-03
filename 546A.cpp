#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int k,n,w;
    cin>>k>>n>>w;

    int ans=k*w*(w+1)/2;

    if(ans>n){
        cout<<ans-n<<endl;
    }
    else{
        cout<<0<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}