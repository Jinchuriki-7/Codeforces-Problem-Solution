#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n,f;
    cin>>n>>f;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    int ans=0;
    for(int i=0;i<n;i++){
        ans=v[i]*10;
        
    }
}

int main(){
    sami();

    ami();

    return 0;
}