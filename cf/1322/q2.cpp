#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll getLength(vector<ll> a, vector<ll> b, ll len, ll bred){

	ll totalLen1 = 0;
	ll totalBred1 = 0;
	ll prevVal = a[0];
	ll count = 0;
	for(ll i=0;i<a.size();i++){

		if(a[i] == 1){
			count++;
		} else {
			if(count >= len || count >= bred){
				if(count >= len){
					totalLen1 += (count - len + 1);
				}

				if(count >= bred){
					totalBred1 += (count - bred + 1);
				}
			} 

			count = 0;
		}
	}

	if(count >= len || count >= bred){
		if(count >= len){
			totalLen1 += (count - len + 1);
		}

		if(count >= bred){
			totalBred1 += (count - bred + 1);
		}
	}

	ll totalLen2 = 0;
	ll totalBred2 = 0;
	count = 0;

	for(ll i=0;i<b.size();i++){

		if(b[i] == 1){
			count++;
		} else {
			if(count >= len || count >= bred){
				if(count >= len){
					totalLen2 += (count - len + 1);
				}

				if(count >= bred){
					totalBred2 += (count - bred + 1);
				}
			} 
			
			count = 0;
			
		}
	}

	if(count >= len || count >= bred){
		if(count >= len){
			totalLen2 += (count - len + 1);
		}

		if(count >= bred){
			totalBred2 += (count - bred + 1);
		}
	}

	ll ans = (totalLen1 * totalBred2) + (totalLen2 * totalBred1);	

	if(len == bred){
		ans = ans / 2;
	}

	return ans;


}

void solve(){
	
	ll n,m,k;
	cin>>n>>m>>k;

	vector<ll> a,b;

	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;

		a.push_back(vl);
	}

	ll mm = m;
	while(mm--){
		ll vl;
		cin>>vl;

		b.push_back(vl);
	}

	vector< pair<ll,ll> > rects;
	for(ll i=1;i<k;i++){
		if(k % i == 0){
			rects.push_back(make_pair(i, k/i));
		}
	}

	if(k == 1){
		rects.push_back(make_pair(1,1));
	}

	ll totalSum = 0;
	for(ll i=0;i<rects.size();i++){

		ll sum = getLength(a,b,rects[i].first, rects[i].second);
		totalSum += sum;

	}

	if(k  == (n * m)){
		totalSum = 1;
	}

	cout<<totalSum<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}
}