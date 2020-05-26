#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;

	vector<ll> a,b;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}
	nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		b.push_back(vl);
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll p1=0,p2 = n-1;
	while(k>0){

		if(a[p1] < b[p2]){
			swap(a[p1],b[p2]);
		} else {
			break;
		}
		k--;
		p1++;
		p2--;
	}
	ll ans=0;
	for(ll el : a){
		ans+=el;
	}
	cout<<ans<<endl;

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
