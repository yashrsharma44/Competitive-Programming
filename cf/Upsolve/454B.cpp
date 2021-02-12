#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

    int n; cin>>n;
    vector<int> a;
    int nn = n;
    while(nn--){
        int u; cin>>u;
        a.push_back(u);
    }

    int invert = -1;
    for(int i=0;i<n-1;i++){
        if(a[i] > a[i+1]){
            if(invert == -1){
                invert = i;
            } else {
                cout<<-1<<endl;
                return;
            }
        }
    }
    if(a.back() > a[0] && invert != -1){
        cout<<-1<<endl;
        return;
    }
    if(invert == -1){
        cout<<0<<endl;
    } else {
        cout<<n - invert - 1<<endl;
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