#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void printVal(vector<string> &res, ll dx, ll dy){

	if(dx >= 0){
		while(dx > 0){
			res.push_back("D");
			dx--;
		}
	} else {
		while(dx < 0){
			res.push_back("U");
			dx++;
		}
	}

	if(dy>=0){
		while(dy>0){
			res.push_back("R");
			dy--;
		}
	} else {
		while(dy<0){
			res.push_back("L");
			dy++;
		}
	}


}

void solve(){
	
	ll n,m,k;
	cin>>n>>m>>k;

	vector < pair<ll,ll> > points;
	ll nn = k;
	
	ll maxX = -1, maxY = -1;

	while(nn--){
		ll u,v;
		cin>>u>>v;
		maxX = max(maxX, u);
		maxY = max(maxY, v);
		points.push_back(make_pair(u,v));
	}

	vector< pair<ll,ll> > finalPoint;
	nn = k;

	while(nn--){
		ll u,v;
		cin>>u>>v;

		finalPoint.push_back(make_pair(u,v));
	}
	vector<string> res;
	for(ll i=0;i<n-1;i++){
		res.push_back("U");
	}

	for(ll i=0;i<m-1;i++){
		res.push_back("L");
	}
	
	
	for(ll i=0;i<n;i++){

		if(i%2 == 0){
			for(ll j=0;j<m-1;j++){
				res.push_back("R");
			}
		} else {
			for(ll j=0;j<m-1;j++){
				res.push_back("L");
			}
		}
		res.push_back("D");

	}
	cout<<res.size()<<endl;
	for(string el : res){
		cout<<el;
	}

	cout<<endl;
}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}

}