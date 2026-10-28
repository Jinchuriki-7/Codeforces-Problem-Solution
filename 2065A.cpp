#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;
    string s;
    string u;
    while(n--){
        cin>>s;
        
        s.pop_back();
        s.pop_back();

        s+='i';
       
        cout<<s<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}