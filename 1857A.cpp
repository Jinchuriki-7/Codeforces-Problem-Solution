#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    int a;
    while(x--){
        cin>>a;
        int n;
        int ans=0;
        for(int i=0;i<a;i++){
            cin>>n;
            if(n%2){
            ans++;
        }
    } 
        if(ans%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

int main(){
    sami();

    ami();

    return 0;
}