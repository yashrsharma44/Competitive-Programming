#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int y,k,n; cin>>y>>k>>n;
	int start = (y + k) / k;
	int posx = start * k;
	vector<int> ans;
	while(posx <= n){
		int val = posx - y;
		ans.push_back(val);
		posx += k;
	}
	if(ans.size() == 0){
		cout<<-1<<endl;
		return;
	}
	for(int el : ans){
		cout<<el<<" ";
	}
	cout<<endl;

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
