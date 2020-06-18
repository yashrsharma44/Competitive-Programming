#include <bits/stdc++.h>
#define int long long 
#define MOD 1000000007
using namespace std;

void solve(){

	int t,k;
	cin>>t>>k;

	vector< pair<int,int> > q;
	while(t--){
		int a,b;
		cin>>a>>b;
		q.push_back(make_pair(a,b));
	}

	vector<int> count(100000+10, 0);
	count[0] = 1;
	for(int i=1;i<=(100000+10);i++){
		if(i < k){
			count[i] = 1;
		} else 
		count[i] = (count[i-1] + count[i-k]) % MOD ;
	}
		
	vector<int> sum(100000+10, 0);
	for(int i=1;i<=(100000+10);i++){
		sum[i] = (sum[i-1] + count[i]) % MOD;
	}

	for(auto el : q){
		cout<<((sum[el.second] - sum[el.first-1] + MOD) % MOD)<<endl;
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
