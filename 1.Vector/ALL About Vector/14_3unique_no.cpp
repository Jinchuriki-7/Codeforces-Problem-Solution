#include<bits/stdc++.h>
using namespace std;
int main(){
    
    vector<int>v={2,3,5,5,7,7,1};

    vector<int>::iterator it=max_element(v.begin(),v.end());
    cout<<*it<<endl;

    /*
    kon index a ache setar jnno
    vector<int>v={2,3,5,5,7,7,1};
    int n=max_element(v.begin(),v.end()-v.begin());
   or min_element
    cout<<n<<endl;

    */
}