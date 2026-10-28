#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int>a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        
        if(a[n-1]<=d){
            cout<<"YES\n";
        } 
        else if(a[0]+a[1]<=d){
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