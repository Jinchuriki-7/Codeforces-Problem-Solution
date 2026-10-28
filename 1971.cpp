#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;

    while(x--){
        vector<int>v(2);
        for(int i=0;i<2;i++){
            cin>>v[i];
        }

       sort(v.begin(),v.end());
       
       for(auto u:v){
        cout<<u<<" ";
       }
       cout<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}