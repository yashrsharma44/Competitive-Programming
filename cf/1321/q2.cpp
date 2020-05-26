#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll n;
	cin>>n;

	vector<ll> b;

	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		b.push_back(vl);
	}

	vector< pair<ll,ll> > c(n,make_pair(0,0));
	for(ll i=0;i<n;i++){
		c[i].first = b[i] - i;
		c[i].second = i;
	}

	sort(c.begin(),c.end());
	ll maxSum = b[c[0].second];
	ll localSum = maxSum;
	ll maxCount = 1;
	ll localCount = 1;
	for(ll i=1;i<n;i++){

		if(c[i].first == c[i-1].first){
			localSum += (b[c[i].second]);
			// localCount+=1;
		} else {
			
			if(maxSum < localSum){
				// maxCount = localCount;
				maxSum = localSum;
			}	

			localSum = b[c[i].second];
			// localCount = 1;
		} 
	}

	if(maxSum < localSum){
		maxSum = localSum;
	}

	cout<<maxSum<<endl;
}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}