#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){
    int x;
    cin>>x;
    int a[1001];

    int b[1001],i;
    for( i=0;i<x;i++){
        cin>>a[i];
       
    }   
    b[0]=a[0]-1;
    for(i=1;i<x;i++){
        
          b[i]=max(a[i]-(i+1),b[i-1]+1);
    }

     for(i=0;i<x;i++){
        cout<<b[i]<<endl;
       
    } 
   
}

int main(){
    sami();

    ami();

    return 0;
}
