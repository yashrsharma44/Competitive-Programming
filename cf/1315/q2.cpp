
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll binSearch(vector<ll> arr, ll el){

	ll lb = 0;
	ll ub = arr.size()-1;

	while(lb < ub){

		ll mid = (lb+ub) / 2;
		if(el < arr[mid]){
			ub = mid;
		} else {
			lb = mid+1;
		}

	}

	return lb-1;

}

void solve(){

	ll a,b,p;
	cin>>a>>b>>p;

	string s;
	cin>>s;

	vector<ll> cost(s.length(),0);

	char prev = s[0];
	cost[0] = (s[0] == 'A') ? a : b;
	for(ll i=1;i<s.length()-1;i++){

		if(prev == s[i]){
			cost[i] = cost[i-1];
		} else {
			cost[i] = cost[i-1] + ((s[i] == 'A') ? a : b);
			prev = s[i];
		}
	}

	cost[s.length()-1] = cost[s.length()-2];
	cost.insert(cost.begin(),0);

	ll start = 0;
	ll endInd = -1;
	for(ll i=0;i<cost.size();i++){

		if(cost[cost.size() - 1] - cost[i] <= p){
			
			endInd = i;
			while(cost[endInd] == cost[i]){
				endInd++;
			}

			// endInd -= 1;

			break;
		}

	}
	if(endInd > s.length()){
		endInd = s.length();
	}

	if(endInd == 0){
		endInd +=1;
	}
	cout<<endInd<<endl;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}