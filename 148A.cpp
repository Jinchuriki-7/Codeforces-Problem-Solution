#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;

    int count=0;

    for (int i=1;i<=d;i++){
        if (i%k==0 || i%l==0 || i%m==0 || i%n == 0){
            count++;
        }
    }
    cout<<count<<endl;

}


int main(){
    sami();

    ami();

    return 0;
}