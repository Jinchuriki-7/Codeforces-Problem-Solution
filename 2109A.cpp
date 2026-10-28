#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;
    
    int x;
    while(n--){
        cin>>x;

        vector<int>v(x);
        for(int i=0;i<x;i++){
            cin>>v[i];

        }

        int cnt=0;
        for(int i=0;i<x-1;i++){
          if(v[i]==0 && v[i+1]==0){
           cnt++;
          }
        }
        if(cnt>0){
            cout<<"YES"<<endl;
        }
        else if(x==2 && v[0]==1 && v[1]==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}

int main(){
    sami();

    ami();

    return 0;
}