#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){

    string s;
    cin>>s;
    string temp=s;

    reverse(temp.begin(),temp.end());

    if(s==temp){
        cout<<"Case "<<i<<": Yes"<<endl;
    }
    else{
        cout<<"Case "<<i<<": No"<<endl;
    }
}
}

int main(){
    sami();

    ami();

    return 0;
}