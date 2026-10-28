#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    sami();

    string s="deacbbaaa";

    sort(s.begin(),s.end());
    int x=unique(s.begin(),s.end())-s.begin();
    
    for(int i=0;i<x;i++){
        cout<<s[i];//ekhne endl dile poti ta chrt niche niche print hbe

    }
    cout<<endl;

    return 0;
}