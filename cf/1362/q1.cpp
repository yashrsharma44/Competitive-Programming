#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string bin(ll n){

	string ans="";
	while(n > 0){
		if(n%2==0){
			ans = "0" + ans;
		} else {
			ans = "1" + ans;
		}
		n = n / 2;
	}

	return ans;

}

void solve(){

	ll a,b;
	cin>>a>>b;

	if(a  == b){
		cout<<0<<endl;
		return;
	}

	if(a < b){
		swap(a,b);
	}

	ll total=0;
	while(a > b && (a % 2 == 0)){
		a = a >> 1;
		total += 1;
	}

	if(a == b){
		cout<<(total / 3 + (total % 3 != 0 ? 1 : 0))<<endl;
	} else {
		cout<<-1<<endl;
	}

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
