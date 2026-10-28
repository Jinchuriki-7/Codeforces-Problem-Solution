#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    int ans=0;
    for(int i=0;i<n-2;i++){

        if(v[i]<v[i+1] && v[i+1]>v[i+2]){
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