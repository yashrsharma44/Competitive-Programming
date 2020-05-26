#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,x;
	cin>>n>>x;

	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	ll maxSum = 0;
	vector<ll> lst;

	int weal = 0;

	for(ll i=0;i<n;i++){
		if(a[i] >= x){
			maxSum += (a[i] - x);
			a[i] = x;
			weal+=1; 
		} else {
			lst.push_back(a[i]);
		}
	}

	sort(lst.begin(), lst.end(), greater<ll>());

	for(ll el : lst){
		if(maxSum >= (x - el)){
			weal+=1;
			maxSum -= (x - el);
		} else {
			break;
		}
	}

	cout<<weal<<endl;


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