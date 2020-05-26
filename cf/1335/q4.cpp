#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	vector < vector<ll> > grid(9, vector<ll>(9,0));
	string ss;
	for(ll i=0;i<9;i++){
		string s;
		cin>>s;
		for(ll j=0;j<9;j++){
			grid[i][j] = s[j] - '0';
			if(i == j){
				ss+=s[j];
			}
		}
	}

	vector < pair<ll,ll> > sp;
	sp.push_back(make_pair(0,0));
	sp.push_back(make_pair(1,4));
	sp.push_back(make_pair(2,8));

	sp.push_back(make_pair(3,1));
	sp.push_back(make_pair(4,3));
	sp.push_back(make_pair(5,6));
	
	sp.push_back(make_pair(6,2));
	sp.push_back(make_pair(7,5));
	sp.push_back(make_pair(8,7));

	ll valrow = grid[0][0];
	// ll valcol = grid

	for(ll i=0;i<9;i++){
		
		ll l1 = sp[i].first;
		ll r1 = sp[i].second;

		if(grid[l1][r1] != 2){
			grid[l1][r1] = 2;
		} else {
			grid[l1][r1] = 3;
		}

	}

	for(ll i=0;i<9;i++){
		for(ll j=0;j<9;j++){
			cout<<grid[i][j];
		}
		cout<<endl;
	}

	// for(ll i=0;i<9;i++){
	// 	set<ll> st;
	// 	for(ll j=0;j<9;j++){
	// 		st.insert(grid[i][j]);
	// 	}
	// 	cout<<"Row : "<<i<<" "<<st.size()<<endl;
	// }

	// for(ll i=0;i<9;i++){
	// 	set<ll> st;
	// 	for(ll j=0;j<9;j++){
	// 		st.insert(grid[j][i]);
	// 	}
	// 	cout<<"Col : "<<i<<" "<<st.size()<<endl;
	// }

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	ll t;
	cin>>t;
	// t=1;
	while(t--){
		solve();
	}
}