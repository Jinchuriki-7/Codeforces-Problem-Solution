#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(v[i]==v[i+1]){
                cnt++;
        }
    }
    if(cnt>0){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
 }
}

int main(){
    sami();

    ami();

    return 0;
}