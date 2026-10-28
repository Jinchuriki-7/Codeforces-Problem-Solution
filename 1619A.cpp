#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    sami();

    int x;
    cin>>x;
    string s;
    while(x--){
        cin>>s;
        
        int n=s.size();
        
        if(n%2!=0){
            cout<<"No"<<endl;
        }

        else{
        string a=s.substr(0,n/2);
        string b=s.substr(n/2,n/2);

        if(a==b){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

    return 0;
}