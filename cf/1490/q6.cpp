#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	map<int,int> cnt;
	for(auto el : a) cnt[el]++;

	map<int,int> vmap;
	for(auto el : cnt){
		vmap[el.second]++;
	}

	vector<int> post({0});
	for(auto it=vmap.begin();it!=vmap.end();it++){
		post.push_back(post.back() + it->first * it->second);
	}
	reverse(post.begin(), post.end());

	int ans = post[0];
	int pre = 0;
	int lastVal = vmap.rbegin()->first;
	int i = 1;
	int lastCount = 0;

	for(auto it=vmap.rbegin();it!=vmap.rend();it++){
		
		int steps = lastVal - it->first;
		pre += steps * lastCount;

		ans = min(ans, post[i] + pre);

		it->second += lastCount;
	
		lastVal = it->first;
		lastCount = it->second;
		i++;
	}	

	// ans = min(ans, post.back() + pre)
	// for(auto el : vmap){
	// 	ans = min(ans, post[i] + pre);
	// 	pre += el.second;
	// 	i++;
	// }

	// ans = min(ans, post[i] + pre);

	cout<<ans<<endl;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}