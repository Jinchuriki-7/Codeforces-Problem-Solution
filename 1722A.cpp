#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n!=5){
            cout<<"NO"<<endl;
            continue;
        }
        sort(s.begin(),s.end());
        string t="Timur";

        sort(t.begin(),t.end());
        if(s==t){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
}


int main(){
    sami();

    ami();

    return 0;
}