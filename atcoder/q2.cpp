#include <bits/stdc++.h>
#define ll long long int  

using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	vector<ll> a;
	ll nn = n;
	ll sum = 0;
	while(nn--){
		ll vl;
		cin>>vl;
		sum+=vl;
		a.push_back(vl);
	}

	sort(a.begin(), a.end(),greater<ll>());
	ll i=0;
	double frac = sum / (4 * m);
	while(i<m){

		if((a[i] * 4 * m) < sum){
			cout<<"No"<<endl;
			return;
		}
		i++;
	}

	cout<<"Yes"<<endl;
	return;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	// cin>>t;
		t=1;

	while(t--){
		solve();
	}

}