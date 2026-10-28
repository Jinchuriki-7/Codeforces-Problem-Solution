#include<bits/stdc++.h>
using namespace std;
#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

void ami(){

    int n;
    cin>>n;
    
    int c500=n/500;
    n=n%500;
    int c100=n/100;
    n=n%100;
    int c50=n/50;
    n=n%50;
    int c10=n/10;
    n=n%10;
    int c5=n/5;
    n=n%5;
    
    int c1=n;

    while(c1--){
        cout<<"1"<<" ";
    }
     while(c5--){
        cout<<"5"<<" ";
    }
  while(c10--){
        cout<<"10"<<" ";
    }
 while(c50--){
        cout<<"50"<<" ";
    }
 while(c100--){
        cout<<"100"<<" ";
    }
 while(c500--){
        cout<<"500"<<" ";
    }


}
int main(){
    sami();

    ami();

    return 0;
}

