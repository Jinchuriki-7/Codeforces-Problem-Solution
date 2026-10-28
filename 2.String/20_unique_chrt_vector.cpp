//Using vector
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
    v.push_back("Shahriar");
    v.push_back("emon");
    v.push_back("emon");
    v.push_back("momo");
    v.push_back("momo");

    sort(v.begin(),v.end());

   int x=unique(v.begin(),v.end())-v.begin();

   cout<<x<<endl;
   for(int i=0;i<x;i++){
    cout<<v[i]<<endl;
   }
    

    return 0;
}