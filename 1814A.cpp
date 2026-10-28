#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){

    int t;
    cin>>t;

    while(t--){

    ll n,k;
    cin>>n>>k;

    if(k%2==1){
        cout<<"YES"<<endl;
    }
    else{
        if(n%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

}

int main(){
    sami();

    ami();

    return 0;
}