//Non Decreasing Order
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,3,4,5,6};

    cout<<v.back()<<endl;//last el print//O(1)

    v.pop_back();//last el dlt//O(1)

    cout<<v.back()<<endl;

    cout<<*v.begin()<<endl;//1st el print

    //1st el dlt
    v.erase(v.begin());
    for(auto u:v){
        cout<<u<<endl;

    }
    
}

