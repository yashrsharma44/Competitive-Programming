#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int a,b,c; cin>>a>>b>>c;
	vector< multiset<int> > ar(3, multiset<int>());
	int nn = a;
	while(nn--){
		int u; cin>>u;
		ar[0].insert(u);
	}
	nn = b;
	while(nn--){
		int u; cin>>u;
		ar[1].insert(u);
	}
	nn = c;
	while(nn--){
		int u; cin>>u;
		ar[2].insert(u);
	}

	while(ar[0].size() > 0 && ar[1].size() > 0 && ar[2].size() > 0){
		int ae = *(ar[0].begin()) - *(ar[1].rbegin());
		int af = *(ar[0].begin()) - *(ar[2].rbegin());

		int bd = *(ar[1].begin()) - *(ar[0].rbegin());
		int bf = *(ar[1].begin()) - *(ar[2].rbegin());

		int cd = *(ar[2].begin()) - *(ar[0].rbegin());
		int ce = *(ar[2].begin()) - *(ar[1].rbegin());

		set<int> mnn;
		mnn.insert({ae,af,bd,bf,cd,ce});

		if(ae == *mnn.begin()){
			ar[0].erase(ar[0].begin());
			ar[0].insert(ae);
			ar[1].erase(std::prev(ar[1].end()));
		} else if(af == *mnn.begin()){
			ar[0].erase(ar[0].begin());
			ar[0].insert(af);
			ar[2].erase(std::prev(ar[2].end()));
		} else if(bd == *mnn.begin()){
			ar[1].erase(ar[1].begin());
			ar[1].insert(bd);
			ar[0].erase(std::prev(ar[0].end()));
		} else if(bf == *mnn.begin()){
			ar[1].erase(ar[1].begin());
			ar[1].insert(bf);
			ar[2].erase(std::prev(ar[2].end()));
		} else if(cd == *mnn.begin()){
			ar[2].erase(ar[2].begin());
			ar[2].insert(cd);
			ar[0].erase((std::prev(ar[0].end())));
		} else if(ce == *mnn.begin()){
			ar[2].erase(ar[2].begin());
			ar[2].insert(ce);
			ar[1].erase(std::prev(ar[1].end()));
		}
	}	

	multiset<int> mins, maxs;
	if(ar[0].size() == 0){
		if(*(ar[1].begin()) < *(ar[2].begin())){
			mins = ar[1];
			maxs = ar[2];
		} else {
			mins = ar[2];
			maxs = ar[1];
		}
	}  else if(ar[1].size() == 0){
		if(*(ar[0].begin()) < *(ar[2].begin())){
			mins = ar[0];
			maxs = ar[2];
		} else {
			mins = ar[2];
			maxs = ar[0];
		}
	} else if(ar[2].size() == 0){
		if(*(ar[0].begin()) < *(ar[1].begin())){
			mins = ar[0];
			maxs = ar[1];
		} else {
			mins = ar[1];
			maxs = ar[0];
		}
	}

	while(maxs.size() > 1){
		int nm = *(mins.begin());
		mins.erase(mins.begin());

		mins.insert(nm - *(maxs.rbegin()));
		maxs.erase(std::prev(maxs.end()));
	}

	int ans = abs(*(mins.begin())) + abs(*(maxs.begin()) - *(mins.rbegin()));

	cout<<ans<<endl;


}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
