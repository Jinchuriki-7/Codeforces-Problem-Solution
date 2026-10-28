#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int a[1000];

        for(int i=0;i<2*n;i++){
            cin>>a[i];
        }

        sort(a,a+2*n);
        int ok=1;

        for(int i=0;i<n;i++){
            if(a[i]+x>a[i+n]){
                ok=0;
            }
        }

        if(ok==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}

int main(){
    sami();

    ami();

    return 0;
}