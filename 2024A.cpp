#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    int a,b;
    while(x--){
        cin>>a>>b;

        if(a<b){

            int req=2*a-b;

            if(req>=0){
                cout<<req<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            cout<<a<<endl;
        }
    }
}

int main(){
    sami();

    ami();

    return 0;
}