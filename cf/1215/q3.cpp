#include <bits/stdc++.h>
#define ll long long int 

using namespace std;

bool comp(pair<ll,char> &p1, pair<ll,char> &p2){

	return p1.second < p2.second;
}

void solve(){
	
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	ll n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;

	vector< pair<char, ll> > strab, strba;

	for(ll i=0;i<n;i++){

		if(s1[i] != s2[i]){

			if(s1[i] == 'a'){
				strab.push_back(make_pair('a', i));
			} else {
				strba.push_back(make_pair('b', i));
			}
		}
	}

	if(strab.size() == 0 && strba.size() == 0){
		cout<<0<<endl;
		return;
	}

	if((strab.size() + strba.size())%2==1){
		cout<<-1<<endl;
		return;
	}

	vector < pair<ll,ll> > ans;

	if(strab.size() % 2 != 0){
		
		ll idx = strab[0].second;
		ans.push_back(make_pair(idx+1, idx+1));

		strab.erase(strab.begin());
		strba.push_back(make_pair('b', idx));
	}

	if(strab.size()!=0){
		for(ll i=0;i<strab.size()-1;i+=2){
			ans.push_back(make_pair(strab[i].second+1, strab[i+1].second+1));
		}
	}
	if(strba.size()!=0){
		for(ll i=0;i<strba.size()-1;i+=2){
			ans.push_back(make_pair(strba[i].second+1, strba[i+1].second+1));
		}
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
	// cin>>t;
	t=1;

	while(t--){
		solve();
	}

}