#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;
    int b;
    cin>>b;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++){
        if(b>=v[i]){
            b-=v[i];
            ans++;
        }
        else{
            break;
        }

    }
    cout<<ans<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}