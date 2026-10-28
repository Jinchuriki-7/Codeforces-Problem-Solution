#include<bits/stdc++.h>
using namespace std;

#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void ami(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;

        vector<int>a(n),b(n);

        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int i;
        for(i=0;i<n;i++){
            if(a[i] + b[n-1-i] > x){
                cout<<"No\n";
                break;
            }
        }

        if(i==n){
            cout<<"Yes\n";
        }
    }
}

int main(){
    sami();
    ami();
    return 0;
}