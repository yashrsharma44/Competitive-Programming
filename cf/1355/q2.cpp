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
	ll cnt = 0;
	
	ll p1=0, p2=0;
	while(p1 < n && p2 < n){

		if(a[p2] == p2 - p1 + 1){
			cnt+=1;
			p1 = p2+1;
		}
		p2++;
	}

	cout<<cnt<<endl;

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
