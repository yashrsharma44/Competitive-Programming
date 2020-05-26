#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a,b;
	ll nn=n;
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

	if(n==1){

		if(b[0] >= a[0]){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		return;
	}

	vector<ll> diff(n,0);
	// bool isPos = true;
	set<ll> check;
	bool isNeg = false;
	for(ll i=0;i<n;i++){
		if(b[i] - a[i] < 0){
			isNeg=true;
		}
		if(b[i] - a[i]!=0){
			check.insert(b[i]-a[i]);
		}
		diff[i] = (b[i] - a[i]);
	}

	if(check.size() > 1 || isNeg){
		cout<<"NO"<<endl;
	} else {

		bool isPos = true;

		ll start=-1, end=-1;
		diff.insert(diff.begin(), 0);
		diff.insert(diff.begin()+diff.size(), 0);
		for(ll i=0;i<diff.size();i++){

			if(diff[i] != 0 && end!=-1){
				isPos = false;
				break;
			}

			if(diff[i]!=0 && start==-1){
				start = i;
			} else if(start!=-1 && diff[i] == 0){
				end = i-1;
			}
		}
		// cout<<start<<" "<<end<<endl;		
		if(isPos){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}


}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}