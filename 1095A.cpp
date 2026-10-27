#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    int i=0;
    int cnt=1;

    while(i<n){
        cout<<s[i];
        i+=cnt;
        cnt++;
    }
}

int main(){
    sami();

    ami();

    return 0;
}