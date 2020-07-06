#include <bits/stdc++.h>
#define int long long

using namespace std;

void insert(string &s, int n){

    int p1 = s.length()-1;
    while(p1 > 0){
        if(s[p1] == s[p1-1] && s[p1]-'0' != n){
            s.insert(p1,to_string(n));
            return;
        }
        p1--;
    }

}

void solve(){
    
    int a,b,x;
    cin>>a>>b>>x;

    if(a> b){
        string ans = "";
        for(int i=0;i<a;i++){
            ans+="0";
        }
        if(x%2==1){
            ans+="1";
            x-=1;
            b-=1;
        }
        
        while(x>0){
            insert(ans,1);
            b-=1;
            x-=2;
        }
        for(int i=0;i<b;i++){
            ans+="1";
        }
        cout<<ans<<endl;

    }else{

        string ans = "";
        for(int i=0;i<b;i++){
            ans+="1";
        }
        if(x%2==1){
            ans+="0";
            x-=1;
            a-=1;
        }
        
        while(x>0){
            insert(ans,0);
            a-=1;
            x-=2;
        }
        for(int i=0;i<a;i++){
            ans+="0";
        }
        cout<<ans<<endl;
    }
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while(t--){
        solve();
    }
}
