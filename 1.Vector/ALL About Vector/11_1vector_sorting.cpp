//Non Decreasing Order(chto thke boro)
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,3,4,5,6};

    sort(v.begin()+2,v.begin()+3);

    for(auto u:v){
        cout<<u<<endl;
    }
}