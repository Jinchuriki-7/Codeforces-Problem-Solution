#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    while(x--){
        int a,b,c,d;
        int count=0;
        cin>>a>>b>>c>>d;

        if(a<b){
            count++;
        }
        if(a<c){
            count++;
        }
        if(a<d){
            count++;
        }
        cout<<count<<endl;
    }
}

int main(){
    sami();

    ami();

    return 0;
}