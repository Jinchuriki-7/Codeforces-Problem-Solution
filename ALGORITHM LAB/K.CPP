#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        int n;
        cin>>n;

        vector<int>a(n);

        for(int j=0;j<n;j++){
            cin>>a[j];
        }

        int mx=a[0];

        for(int j=1;j<n;j++){
            mx=max(mx,a[j]);
        }

        cout<<"Case "<<i<<": "<<mx<<endl;
    }
}

int main(){
    sami();
    ami();
    return 0;
}