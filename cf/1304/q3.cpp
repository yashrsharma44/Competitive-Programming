#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	vector< pair<ll,ll> > range;
	vector <ll> time;
	ll nn = n;
	while(nn--){
		ll t,l,h;
		cin>>t>>l>>h;

		range.push_back(make_pair(l,h));
		time.push_back(t);
	}
	bool isPos =  true;

	ll mn = m, mx = m;
	ll prevTime = 0;

	for(ll i=0;i<n;i++){

		ll k = time[i] - prevTime;

		if(((mx + k) >= range[i].first) && ((mn - k) <= range[i].second)){
			mx = min(mx+k, range[i].second);
			mn = max(mn-k, range[i].first);
		} else {
			isPos = false;
			break;
		}

		prevTime = time[i];
	}

	if(isPos){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}


}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}