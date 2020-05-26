#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n;
	cin>>n;

	string s,m;
	cin>>s>>m;

	string spy = s, mpy = m;
	sort(spy.begin(), spy.end());
	sort(mpy.begin(), mpy.end());

	ll less=0, eql=0, grt=0;

	ll p1=0,p2=0;

	while(p1<n && p2<n){

		if((spy[p1] - mpy[p2]) < 0){
			grt++;
		} else if((spy[p1] - mpy[p2]) >= 0){

			p2++;
			continue;
		} 
		p1++;
		p2++;
	}

	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){

			char c = mpy[j];
			if(c!='#' && c>=s[i]){
				mpy[j] = '#';
				less++;
				break;
			}
		}
	}

	cout<<(n - less)<<endl;
	cout<<grt<<endl;
}

int main(){

	ll t;
	// cin>>t;
	t=1;

	while(t--){
		solve();
	}

}