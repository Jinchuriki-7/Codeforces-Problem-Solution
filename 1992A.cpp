#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    while(x--){

        vector<int>v(3);
        for(int i=0;i<3;i++){
            cin>>v[i];
        }
        for(int i=0;i<5;i++){
            sort(v.begin(),v.end());
            v[0]++;
            }
            cout<<v[0]*v[1]*v[2]<<endl;
        }
    }


int main(){
    sami();

    ami();

    return 0;
}