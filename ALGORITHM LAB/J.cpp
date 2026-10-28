#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){

    int n;
    cin>>n;
    vector<int>v={4,7,44,77,47,74,444,777,447,474,744,747,774,477};
    for(int i=0;i<v.size();i++){
        if(n%v[i]==0){
            cout<<"YES"<<endl;
            return;
        }
        
    }
    cout<<"NO"<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}