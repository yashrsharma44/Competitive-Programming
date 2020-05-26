#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector < pair<ll,ll> >ans;
	ll nn = n;

	while(nn--){
		ll u,v;
		cin>>u>>v;
		ans.push_back(make_pair(u,v));
	}

	vector<ll> prefixSum(n, 0);
	for(ll i=1;i<n;i++){
		prefixSum[i] = ans[i].first - ans[i-1].second;
	}


	prefixSum[0] = ans[0].first - ans[n-1].second;

	ll bullets = 0;
	ll countPos = 0;
	vector<ll> choose(n, 0);
	for(ll i=0;i<n;i++){
		if(prefixSum[i] <= 0){
			choose[i] = 1;
			countPos+=1;
		}
	}

	ll sum = 0;
	for(ll el : prefixSum){
		if(el >=0){
			sum+=el;
		}
	}

	ll minBullet = LLONG_MAX;
	for(ll i=0;i<n;i++){
		if(prefixSum[i] <= 0){
			minBullet = min(minBullet, sum + ans[i].first);
		} else {
			ll val = sum - prefixSum[i] + ans[i].first;
			minBullet = min(minBullet, val);
		}
	}


	// if(countPos != n){

	// 	for(ll i=0;i<n;i++){
	// 		if(choose[i] == 1 && choose[(n + i-1) % n] == 0){
	// 			bullets += ans[(n+i-1)%n].first; 
	// 			choose[(n+i-1)%n] = 1;
	// 		} else if(choose[i] == 1 && choose[(i+1)%n] == 0){
	// 			ans[(i+1)%n].first -= ans[i].second;
	// 		}
	// 	}
	// 	for(ll i=0;i<n;i++){
	// 		if(choose[i] == 0){
	// 			bullets += ans[i].first;
	// 			ans[(i+1) % n].first -= ans[i].second;
	// 		}
	// 	}
	// } else {

	// 	for(ll i=0;i<n;i++){
	// 		bullets = min(bullets, ans[i].first);
	// 	}
	// }

	cout<<minBullet<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	
	while(t--){
		solve();
	}

}