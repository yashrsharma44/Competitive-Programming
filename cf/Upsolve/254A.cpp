#include <bits/stdc++.h>
#define int int

using namespace std;


void solve(){

    int n;
    cin>>n;
    int nn = 2*n;
    int k = 1;
    vector<pair<int,int> > a;

    while(nn--){
        int vl;
        cin>>vl;
        a.push_back(make_pair(vl,k++));
    }
    sort(a.begin(), a.end());
    vector<pair<int,int> > ans;
    for(int i=0;i<2*n;i+=2){
        if(a[i].first == a[i+1].first){
            ans.push_back(make_pair(a[i].second, a[i+1].second));
        } else {
            cout<<-1<<endl;
            return;
        }
    }

    for(auto el : ans){
        cout<<el.first<<" "<<el.second<<endl;
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
