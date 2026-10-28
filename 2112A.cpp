#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;

    while(n--){
        int a;
        cin>>a;//alice

        int x,y;
        cin>>x>>y;

        if(a<x && a<y){
            cout<<"YES"<<endl;
        }
        else if(a>x && a>y){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }


    }
}

int main(){
    sami();

    ami();

    return 0;
}