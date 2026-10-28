//Lexicographically smallest to largest sorting 
//Using Vector

#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    sami();

    vector<string>v;

    v.push_back("Shahriar");
    v.push_back("Mubarrat");
    v.push_back("emon");
    v.push_back("Nishan");
    v.push_back("momo");
    v.push_back("Prity");

    sort(v.begin(),v.end());

    //largest to smallest--(v.rbegin(),v.rend());

    for(auto u:v){
        cout<<u<<endl;
    }

    

    return 0;
}