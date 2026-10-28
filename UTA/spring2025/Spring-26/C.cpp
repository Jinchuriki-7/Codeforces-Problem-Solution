#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    ll n;
    cin>>n;

    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    
    ll bob=0,alo=0;
    for(int i=0;i<n/2;i++){
        if(i%2==0){
            bob+=v.back();
            v.pop_back();

            alo+=v.front();
            v.erase(v.begin());
        }
        else{
            alo+=v.back();
            v.pop_back();

            bob+=v.front();
            v.erase(v.begin());
        }
    }
    cout<<bob<<" "<<alo<<endl;

    
}

int main(){
    sami();

    ami();

    return 0;
}