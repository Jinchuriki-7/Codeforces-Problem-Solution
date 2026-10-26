#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}