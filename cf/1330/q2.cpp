#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;

		a.push_back(vl);
	}

	bool fromLeft=true;
	bool checkRight = true;
	set<ll> seen1, seen2;
	ll max1=-1, max2=-1;
	for(ll i=0;i<n;i++){

		ll el = a[i];

		if(checkRight){
			max1 = max(max1, el);
			if(seen1.find(el) == seen1.end()){
				seen1.insert(el);
				
			} else {

				if(seen1.size() != max1){
					fromLeft = false;
					break;
				} else {
					checkRight = false;
				}
				seen2.insert(el);
				max2 = el;
			}	
		} else {
				max2 = max(max2, el);
			if(seen2.find(el) == seen2.end()){
				seen2.insert(el);

			} else {

				if(seen2.size() != max2){
					fromLeft = false;
				}
				// break;
			}
		}
	}

	if(seen2.size() != max2 || seen1.size()+seen2.size()!=n){
		fromLeft=false;
	}

	set< pair<ll,ll> >ans;

	if(fromLeft){
		ans.insert({seen1.size(), seen2.size()});
	}



	bool fromRight=true;
	bool checkleft = true;
	set<ll> seen3, seen4;
	ll max3=-1, max4=-1;
	for(ll i=n-1;i>=0;i--){

		ll el = a[i];

		if(checkleft){
			max3 = max(max3, el);
			if(seen3.find(el) == seen3.end()){
				seen3.insert(el);
				
			} else {

				if(seen3.size() != max3){
					fromRight = false;
					break;
				} else {
					checkleft = false;
				}
				seen4.insert(el);
				max4=el;
			}	
		} else {
			max4 = max(max4, el);
			if(seen4.find(el) == seen4.end()){
				seen4.insert(el);
				
			} else {

				if(seen4.size() != max4){
					fromRight = false;
				}
				// break;
			}
		}
	}

	if(seen4.size() != max4 || seen4.size()+seen3.size()!=n){
		fromRight = false;
	}
	if(fromRight){
		ans.insert({seen4.size(), seen3.size()});
	}

	cout<<ans.size()<<endl;
	for(pair<ll,ll> el : ans){
		cout<<el.first<<" "<<el.second<<endl;
	}

}

int main(){


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}