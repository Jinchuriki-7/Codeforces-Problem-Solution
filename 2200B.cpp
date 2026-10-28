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

        int a[n];
        int ans=n;

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                ans=1;
                break;
            }
        }
        cout<<ans<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}