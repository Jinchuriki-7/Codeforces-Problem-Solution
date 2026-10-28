#include<bits/stdc++.h>
using namespace std;
int main(){

    string s="aabaa";
    string temp=s;

    
    reverse(temp.begin(),temp.end());//O(n)
    
    if(s==temp){
        cout<<"pallindrom"<<endl;
    }
    else{
        cout<<"Not Pallindrom"<<endl;
    }
}