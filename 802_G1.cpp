#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    string s;
    cin>>s;

    string t="heidi";
    int j=0;

    for(int i=0;i<s.length();i++){
        if(s[i]==t[j]){
            j++;
        }

    }
    if(j==5){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}