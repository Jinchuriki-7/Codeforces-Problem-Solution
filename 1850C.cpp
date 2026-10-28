#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;
    while(n--){

        vector<string>v(8);
        for(int i=0;i<8;i++){
            cin>>v[i];
        }

        string s="";
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(v[i][j]!='.'){
                    s+=v[i][j];
                }
            }
        }
        cout<<s<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}