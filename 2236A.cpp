#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mn=100,mx=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mn=min(mn,x);
            mx=max(mx,x);
        }
        cout<<mx-mn+1<<endl;
    }

}

int main(){
    sami();

    ami();

    return 0;
}