#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n;
	cin>>n;
	ll nn = n;
	
	// Our problem can be reduced to a graph problem by considering the fact that the permutation is 
	// infact a cyclic group. We can form numerous isolated cyclic groups, and we need to fill in the missing 
	// edges. We can first create a list of all isolated vertices and make a cyclic group out of it.
	// Then we find a the starting and ending edge whose in / out count is zero and join them.
	// This results our modified permutation
	
	vector<ll> f(n);
	vector<ll> in(n), out(n);
	for(ll i=0;i<n;i++){

		cin>>f[i];
		--f[i];
		if(f[i] != -1){
			++out[i];
			++in[f[i]];
		}
	}

	// Count the number of isolated vertices
	vector<ll> loops;
	for(ll i=0;i<n;i++){

		if(out[i] == 0 && in[i] == 0){
			loops.push_back(i);
		}
	}

	// Join the isolated vertices
	if(loops.size() == 1){

		ll idx = loops[0];
		for(ll i=0;i<n;i++){

			if(in[i] == 0 && i!=idx){

				f[idx] = i;
				++in[f[idx]];
				++out[idx];
				break;
			}
		}

	} else if(loops.size() > 1) {

		for(ll i=0;i<loops.size();i++){

			ll curr = loops[i];
			ll nxt = loops[(i+1) % loops.size()];

			f[curr] = nxt;

			++out[curr];
			++in[nxt];
		
		}
	}
	// List out the vertex which is only the starting and end points of different groups
	vector<ll> ins, outs;
	for(ll i=0;i<n;i++){

		if(out[i] == 0) outs.push_back(i);
		if(in[i] == 0) ins.push_back(i);
	}

	for(ll i=0;i<outs.size();i++){
		f[outs[i]] = ins[i];
	}

	for(ll el : f){
		cout<<(el+1)<<" ";
	}
	cout<<endl;
}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}
}