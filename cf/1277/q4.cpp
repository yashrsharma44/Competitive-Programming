#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	ll nn = n;
	
	vector<string> a;

	ll s01 = 0, s10 = 0, s00 = 0, s11 = 0;
	set <string> ss01, ss10;
	while(nn--){
		string vl;
		cin>>vl;
			

		if(vl[0] == '1' && vl.back() == '1'){
			s11+=1;
		}

		if(vl[0] == '0' && vl.back() == '0'){
			s00+=1;
		}

		if(vl[0] == '1' && vl.back() == '0'){
			s10+=1;
			ss10.insert(vl);
		}

		if(vl[0] == '0' && vl.back() == '1'){
			s01+=1;
			ss01.insert(vl);
		}
		
		a.push_back(vl);
	}

	if(s11!=0 && s00!=0 && s10==0 && s01==0){
		cout<<-1<<endl;
		return;
	}

	vector<ll> res;

	if(s01 > s10 + 1){

		for(ll i=0;i<a.size();i++){

			if(a[i][0] == '0' && a[i].back() == '1'){
				string ss = a[i];
				reverse(ss.begin(), ss.end());
				if(ss10.count(ss) == 0){
					res.push_back(i);
				}
			}
		}
	} else if(s10 > s01 + 1){

		for(ll i=0;i<a.size();i++){

			if(a[i][0] == '1' && a[i].back() == '0'){
				string ss = a[i];
				reverse(ss.begin(), ss.end());

				if(ss01.count(ss) == 0){
					res.push_back(i);
				}
			}
		}
	}
	ll mx  = max(ss01.size(), ss10.size());
	ll mn  = min(ss01.size(), ss10.size());

	ll ans = max(0ll, abs(mx - mn) /2);

	cout<<ans<<endl;
	for(ll i=0;i<ans;i++){
		cout<<res[i]+1<<" ";
	}
	cout<<endl;


}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}