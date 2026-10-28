#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;

    for(int i=1;i<=t;i++){
        int n;
        string s;
        cin>>n>>s;

        int cnt=0;

        for(int j=1;j<=n;){
            if(s[j-1]=='.'){
                cnt++;
                j+=3;
            }
            else{
                j++;
            }
        }

        cout<<"Case "<<i<<": "<<cnt<<endl;
    }
}

int main(){
    sami();
    ami();
    return 0;
}