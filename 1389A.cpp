#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;

    while(t--){
        long long l,r;
        cin>>l>>r;

        if(2*l<=r){
            cout<<l<<" "<<2*l<<endl;
        }
        else{
            cout<<-1<<" "<<-1<<endl;
        }
    }

}


int main(){
    sami();

    ami();

    return 0;
}