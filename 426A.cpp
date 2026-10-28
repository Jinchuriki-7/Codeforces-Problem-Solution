#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
     int n,s;
    cin>>n>>s;
    int sum=0,mx=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        mx=max(mx,x);
    }
    if(sum-mx<=s){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}

int main(){
    sami();

    ami();

    return 0;
}