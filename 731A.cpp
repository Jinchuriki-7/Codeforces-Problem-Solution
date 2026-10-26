#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    string s;
    cin>>s;
    char in='a';
    int ans=0;
    int x;
    for(int i=0;i<s.size();i++){

        x=min(abs(in-s[i]),26-abs(in-s[i]));
        ans+=x;
        in=s[i];
    }
    cout<<ans<<endl;
    

}

int main(){
    sami();

    ami();

    return 0;
}