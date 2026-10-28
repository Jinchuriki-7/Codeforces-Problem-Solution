#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,3,4,5};
    vector<int>tmp;

    tmp=v;

    cout<<tmp.size()<<endl;
    for(int i=0;i<tmp.size();i++){
        cout<<tmp[i]<<endl;
    }

    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }


}