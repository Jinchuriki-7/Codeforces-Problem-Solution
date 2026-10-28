#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;

        int lift=abs(a-b)*4;
        int grnd=lift+(a*4)+3+3+3+5+5;
        
        cout<<"Case "<<i<<": "<<grnd<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}