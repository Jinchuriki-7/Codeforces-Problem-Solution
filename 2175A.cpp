#include<bits/stdc++.h>
using namespace std;

#define sami() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void ami(){
    int t;
    cin >> t;
    
    int n;
    while(t--){

    cin >> n;

    vector<int> a(n);
    set<int> st;

    for(int i=0;i<n;i++){
        cin >> a[i];
        st.insert(a[i]);
    }

    int cur = st.size();

    while(true){
        if(st.count(cur)){
            break;
        }

        st.insert(cur);
        cur = st.size();
    }

    cout << cur << endl;
}
}

int main(){

    sami();
    ami();
    
}
