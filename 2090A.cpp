#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int n;
    cin>>n;
    int x,y,a;
    while(n--){
        cin>>x>>y>>a;
        int sum=x+y;

        int ss=a%sum;
        if(ss<x){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
    }



    }
}

int main(){
    sami();

    ami();

    return 0;
}