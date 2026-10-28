//Non Decreasing Order
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,3,4,5,6};

    reverse(v.begin(),v.end());

    for(auto u:v){
        cout<<u<<endl;
    }
}

