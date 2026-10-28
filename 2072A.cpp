#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    int n,k,p;
    while(x--){

        cin>>n>>k>>p;
        if(abs(k)>p*n){
            cout<<"-1"<<endl;
        }
        else{
            int ans=(abs(k)+p-1)/p;
            cout<<ans<<endl;
        }
    }
}

int main(){
    sami();

    ami();

    return 0;
}