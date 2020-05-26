#include <bits/stdc++.h>
#define ll int

using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	vector<ll> countZero;
	for(ll i=0;i<n;i++){

		if(s[i] == '0'){
			countZero.push_back(i);
		}
	}
	ll i = 0;
	while(k > 0 && i < countZero.size()){

		if(k - countZero[i] + i > 0){
			swap(s[i], s[countZero[i]]);
			k -= (countZero[i] - i);
		} else {
			swap(s[countZero[i]], s[countZero[i] - k - 1]);
			break;
		}
		i++;
	}
	cout<<s<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	// t=1;

	while(t--){
		solve();
	}

}