#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	set < pair<ll,ll> > prev;
	map < pair<ll,ll>, ll> pos;
	ll currX = 0, currY = 0;
	ll minLen = 1000000000+7;

	ll minStart = -1, minEnd = -1;
	// ll end = -1;
	prev.insert(make_pair(0, 0));
	pos[make_pair(0,0)] = 0;
	for(ll i=0;i<n;i++){

		if(s[i] == 'L'){
			currX -= 1;
		}

		if(s[i] == 'R'){
			currX += 1;
		}

		if(s[i] == 'U'){
			currY += 1;
		}

		if(s[i] == 'D'){
			currY -= 1;
		}

		pair<ll,ll> point = make_pair(currX, currY);
		if(prev.find(point) != prev.end()){

			ll start = pos[point];
			ll end = i+1;
			if((end - start + 1) < minLen){

				minStart = start+1;
				minEnd = end;
				minLen = (end - start + 1);

			}
			pos[point] = i+1;
		} else {

			prev.insert(point);
			pos[point] = i+1;

		}

	}


	if(prev.size() == n+1){
		cout<<-1<<endl;
		return;
	}


	cout<<minStart<<" "<<minEnd<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}