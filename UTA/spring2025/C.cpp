#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    long long n;
    cin>>n;
    long long a,b;
    cin>>a>>b;
    int e,f;
    cin>>e>>f;

    long long ans=(a/e)*(b/f);
    long long qsn=(a/f)*(b/e);

    long long sol=min(ans,qsn);
   
    cout<<sol<<endl;
}

int main(){
    sami();

    ami();

    return 0;
}