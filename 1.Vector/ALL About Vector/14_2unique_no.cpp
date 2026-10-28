#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,3,4,5,5,6,6,6,1};

    sort(v.begin(),v.end());//O(nlog2(n))
   int sz= unique(v.begin(),v.end())- v.begin();//O(n)

   cout<<sz<<endl;//size
    for(int i=0;i<sz;i++){
        cout<<v[i]<<endl;
    }
}

