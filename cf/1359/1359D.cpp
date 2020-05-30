#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
		
	ll n;
	cin>>n;
	vector<ll>a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	deque<ll> d;
	bool start=true;
	ll sum=0;
	ll maxSum = INT_MIN;
	for(ll el : a){

		if(sum <= 0 && !start){
			d.clear();
			sum = 0;
		} 
	
		start = false;
		sum+=el;

		while(d.size() > 0 && d.back() < el){
			d.pop_back();
		}
		d.push_back(el);

		if(sum - d.front()> maxSum){
			maxSum = sum - d.front();
		}
		
	}

	cout<<maxSum<<endl;

}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
