//Decreasing Order(boro thke chto)
//Lexicographically
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,3,4,5,6};

    sort(v.begin(),v.end(),greater<int>());

    for(auto u:v){
        cout<<u<<endl;
    }
}

//Another Way
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={2,3,4,5,6};

    sort(v.rbegin(),v.rend());

    for(auto u:v){
        cout<<u<<endl;
    }
}

/*For array
int a[]={2,3,4,5}
sort(a,a+3,greater<int>());
for(int i=0;i<3;i++){
cout<<a[i]<<i++
}*/
