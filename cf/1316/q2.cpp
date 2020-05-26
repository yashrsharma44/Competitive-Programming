#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool comp(pair<string, ll> &p1, pair<string, ll> &p2){

	if(p1.first != p2.first){
		return p1.first < p2.first;
	}

	return p1.second < p2.second;

}

string getRotate(string s, ll k){

	// Rotate the string depending on the k

	ll diff_len = s.length() - k;

	string ans = "";
	string p1 = s.substr(0, k-1);
	string p2 = s.substr(k-1);
	if(diff_len % 2 == 0){
		// Reverse the substring
		reverse(p1.begin(), p1.end());
		ans = p2 + p1;
	} else {
		ans = p2 + p1;
	}

	return ans;
}

void solve(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	vector< pair<string, ll> > modified;

	for(ll i=1;i<=n;i++){

		string res =  getRotate(s, i);
		modified.push_back(make_pair(res, i));
	}

	sort(modified.begin(), modified.end(), comp);

	cout<<modified[0].first<<endl;
	cout<<modified[0].second<<endl;
	
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}