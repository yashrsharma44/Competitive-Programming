#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;

	string num;
	cin>>num;

	if(k==0){
		cout<<num<<endl;
		return;
	}

	if(n==1 && k==1){
		cout<<0<<endl;
		return;
	}

	string ans = "";

	ll ctr = 0;
	while(true){

		if(ctr == 0){
			if(num[ctr] != '1'){
				break;
			} else {
				ans +="1";
			}
		} else {
			if(num[ctr] != '0'){
				break;
			} else {
				ans+="0";
			}
		}
		ctr++;
	}

	ll count = 0;
	if(ans.length() == 0){
		ans+="1";
		count++;
		ctr++;
	}

	for(;ctr<n;ctr++){

		if(count == k){
			break;
		}

		if(num[ctr] != '0'){
			ans += "0";
			count++;
		} else {
			ans += "0";
		}
	}

	ans += num.substr(ctr);
	cout<<ans<<endl;
}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}
}