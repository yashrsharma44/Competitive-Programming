#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

bool comp(pair<ll,ll> p1, pair<ll,ll> p2){

	if(p1.second != p2.second){
		return p1.first < p2.first;
	}
	
	return p1.second > p2.second;
}

void solve(){

	ll n;
	cin>>n;

	vector<ll> a;

	ll nn = n;
	ll maxPowerMonster=0;
	ll maxPowerHero = 0;
	while(nn--){
		ll vl;
		cin>>vl;
		maxPowerMonster = max(maxPowerMonster, vl);
		a.push_back(vl);
	}

	vector< pair<ll,ll> > ps;
	ll m;
	cin>>m;

	ll mm = m;
	while(mm--){
		ll pp,ss;
		cin>>pp>>ss;

		maxPowerHero = max(maxPowerHero, pp);

		ps.push_back(make_pair(pp, ss));
	}

	if(maxPowerHero < maxPowerMonster){
		cout<<-1<<endl;
		return;
	}

	sort(a.begin(), a.end());
	sort(ps.begin(), ps.end(), comp);


	ll totalDays = 0;
	ll currHero = 0;

	ll currDay = 0;

	for(ll i=0;i<n;i++){

		if(a[i] <= ps[currHero].first){
			currDay+=1;
		} else {
			while(a[i] > ps[currHero].second){
				currHero++;
			}
			currDay  = 1;
		}

		if(currDay == ps[currHero].second){
			totalDays += 1;
			currDay = 1;
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