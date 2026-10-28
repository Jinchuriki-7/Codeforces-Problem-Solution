#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    string s;
    cin>>s;
    if(s=="abc"||s=="acb"||s=="bac"||s=="cba"){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}