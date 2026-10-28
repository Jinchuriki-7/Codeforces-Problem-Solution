#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

//cin.tie(0);cout.tie(0); etuku kete dile ekta test case check kore 

int main(){
    sami();

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        string s;
        char c;
        cin>>c;
        //dhor ami 3 dilm t te ekhn eta 3ta input prjntoi colbe 
        //to sejnno eta (3)je age input niyeci otakeo
        //input hisebe dhre nibe so basically 3 soho 
        //ar duita input nibe tai char c diye
        //agei ekta input niye nibo
        
        getline(cin,s);
        s=c+s;

        cout<<"Case"<<i<<" "<<s<<endl;
    }

    return 0;
}