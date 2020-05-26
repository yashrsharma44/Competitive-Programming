#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(vector<ll> arr){

	int countZero = 0;
	for(int el : arr){
		if(el == 0){
			countZero++;
		}
	}

	return (countZero <= 1);
}

void solve(){

	ll n;
	cin>>n;

	vector<ll> arr;

	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		arr.push_back(vl);
	}

	ll maxEl = -1;

	for(ll el : arr){

		maxEl = max(maxEl, el);
	}

	bool isPos = true;

	for(ll el : arr){

		if((maxEl - el) % 2 == 1){
			isPos = false;
			break;
		}
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