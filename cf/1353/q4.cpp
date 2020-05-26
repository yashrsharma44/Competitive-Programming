#include <bits/stdc++.h>
#define ll long long int

using namespace std;


void solve(){

	ll n;
	cin>>n;
	vector<ll> arr(n,0);

	queue< pair<ll,ll> > q;
	q.push(make_pair(0,n-1));
	ll k=1;
	while(!q.empty()){

			pair<ll,ll> p = q.front();
			q.pop();

			ll mid = (p.first + p.second) >> 1;
			arr[mid] = k++;

			ll l1 = p.first;
			ll r1 = mid-1;

			ll l2 = mid+1;
			ll r2 = p.second;

			if(l1 < r1 && l2 < r2){
				
				if(abs(l1-r1) >= abs(l2-r2)){
					q.push(make_pair(l1,r1));
					q.push(make_pair(l2,r2));
				} else {
					q.push(make_pair(l2,r2));
					q.push(make_pair(l1,r1));
				}
			} else {

				if(l1 < r1){
					q.push(make_pair(l1,r1));
				}
				if(l2 < r2){
					q.push(make_pair(l2,r2));
				}
			}
		// }

	}

	for(ll i=0;i<n;i++){
		if(arr[i] == 0){
			arr[i] = k++;
		}
	}

	for(ll el : arr){
		cout<<el<<" ";
	}
	cout<<endl;
	
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
