#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    int x;
    cin>>x;
    string s;
    while(x--){

        sami();
        cin>>s;
        if(s.size() > 2 && s[0]=='1' && s[1]=='0'){
            int a=stoi(s.substr(2));

            if(a>=2 && s[2]!='0'){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}