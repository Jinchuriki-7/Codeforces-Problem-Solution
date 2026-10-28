//lexicographically largest to smallest

#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    sami();

    string s="Abcedf";

    sort(s.rbegin(),s.rend());
    cout<<s<<endl;

    return 0;
}