#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
     int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;

        if(a%2!=0){
            cout<<"NO\n";
        }
        else{
            if(a==0&&b%2!=0){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
}

int main(){
    sami();

    ami();

    return 0;
}