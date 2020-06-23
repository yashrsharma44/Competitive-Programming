#include <bits/stdc++.h>
#define int long long

using namespace std;


void solve(){

	int n;
	cin>>n;
	vector<int> a;
	int nn = 2*n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	for(int i=2;i<=1000;i++){


		map<int,vector<int> > mp;
		set<int> elems;
		set<int> choose;
		int ctr = 1;
		for(int el : a){
			mp[el%i].push_back(ctr++);
			elems.insert(el%i);
		}

		vector< pair<int,int> > ans;
		if(mp.count(0) > 0){
			elems.erase(0);
			for(int j=1;j<mp[0].size();j+=2){
				ans.push_back(make_pair(mp[0][j], mp[0][j-1]));
			}
		}
		set<int> visited;
		for(auto el : elems){

			if(elems.find(i - el) != elems.end() && visited.find(el) == visited.end() && visited.find(i - el) == visited.end()){
				
				vector<int> f1 = mp[el], f2 = mp[i - el];

				if(el == i - el){
					for(int j=1;j<mp[el].size();j+=2){
						ans.push_back(make_pair(mp[el][j], mp[el][j-1]));
					}
				} else {
					for(int j=0;j <min(f1.size(), f2.size());j++){
						ans.push_back(make_pair(f1[j], f2[j]));
					}
				}
				

				visited.insert(el);
				visited.insert(i - el);
			}
		}

		if(ans.size() >= (n - 1)){

			for(int j=0;j<(n-1);j++){
				cout<<ans[j].first<<" "<<ans[j].second<<endl;
			}

			return;
		}
	}
}



int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
