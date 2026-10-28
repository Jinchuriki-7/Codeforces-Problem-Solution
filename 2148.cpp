#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    int t,n;
    while(x--){
       cin>>t>>n;
       if(n%2==0){
        cout<<0<<endl;
       }
       else{
        cout<<t<<endl;
       }
    }

}

int main(){
    sami();

    ami();
    
    return 0;
}