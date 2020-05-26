#include <bits/stdc++.h>
#define ll int

using namespace std;


void solve(){

	ll n,x;
	cin>>n>>x;

	string s;
	cin>>s;

	if(x == 0){

		ll bal = 0;
		ll count = 0;
		for(char c : s){
			if(c == '0'){
				bal+=1;
			} else {
				bal-=1;
			}

			if(bal == x){
				count+=1;
			}
		}

		if(bal == 0 && n>1){
			cout<<-1<<endl;
			return;
		}

		if(n == 1){
			cout<<1<<endl;
			return;
		}

		for(char c : s){
			if(c == '0'){
				bal+=1;
			} else {
				bal-=1;
			}

			if(bal == x){
				count+=1;
			}
		}

		cout<<count<<endl;
		return;
	}

	if(x == 1 || x == -1){

		ll bal = 0;
		ll count = 0;
		for(char c : s){
			if(c == '0'){
				bal+=1;
			} else {
				bal-=1;
			}

			if(bal == x){
				count+=1;
			}
		}

		if(bal == 0 && count != 0){
			cout<<-1<<endl;
			return;
		}
		
		for(char c : s){
			if(c == '0'){
				bal+=1;
			} else {
				bal-=1;
			}

			if(bal == x){
				count+=1;
			}
		}

		cout<<count<<endl;
		
		return;

	}


	set<ll> fct;
	for(ll i=2;i*i<=x;i++){
		if(x%i == 0){
			fct.insert(i);
			fct.insert(x / i);
		}
	}

	if(x < 0){
		ll xx = abs(x);
		for(ll i=2;i*i<=xx;i++){
			if(xx%i == 0){
				fct.insert(-i);
				fct.insert(x / i);
			}
		}
	}

	ll count=0;
	ll bal = 0;
	for(char c : s){
		if(c == '0'){
			bal+=1;
		} else {
			bal-=1;
		}

		if(fct.find(bal) != fct.end()){
			count+=1;
		}
	}

	if(bal == 0 || fct.size() == 0){
		if(fct.size() > 0){
			cout<<-1<<endl;
		} else {
			cout<<0<<endl;
		}
		return;
	}

	for(char c : s){
		if(c == '0'){
			bal+=1;
		} else {
			bal-=1;
		}

		if(fct.find(bal) != fct.end()){
			count+=1;
		}
	}	

	

	cout<<count<<endl;
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