#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        string t="",o="";

        for(char c:s){
            if(c=='T'){
                t+=c;
            }
            else{
                o+=c;
            }
        }

        cout<<t+o<<endl;
    }

}


int main(){
    sami();

    ami();

    return 0;
}