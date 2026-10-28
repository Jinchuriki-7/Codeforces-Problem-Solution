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
    reverse(v.begin(),v.end());

    int count=0;
    for(int i=0;i<n;i++){

        if(v[i]%7==0){
        cout<<v[i]<<" ";
        count++;
        
    }
    }
        
    if(count==0){
        cout<<"-1"<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}