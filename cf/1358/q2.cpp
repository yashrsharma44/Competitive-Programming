#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	sort(a.begin(), a.end());
	ll p1=n-1;
	
	while(p1 >= 0){

		ll idx = p1 + 1;
		if(idx >= a[p1]){
			cout<<idx+1<<endl;
			return;
		} else {
			p1--;
		}
	}

	cout<<1<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
