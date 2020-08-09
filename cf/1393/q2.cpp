#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){

	int n;
	cin>>n;
	vector<int> a(n);
	map<int,int>mp;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}

	
	set<pair<int,int> > sp;
	for(auto el : mp){
		sp.insert({el.second, el.first});
	}

	int q;
	cin>>q;
	while(q--){
		string s;
		int num;
		cin>>s;
		cin>>num;
		if(s[0] == '+'){
			// int num = stoi(s.substr(2));
			if(mp[num] != 0){
				sp.erase({mp[num], num});
			}
			mp[num]++;
			sp.insert({mp[num], num});
		} else {
			// int num = stoi(s.substr(2));
			sp.erase({mp[num], num});
			mp[num]--;
			if(mp[num] != 0){
				sp.insert({mp[num], num});
			}
		}
		if(sp.size() == 0){
			cout<<"NO"<<endl;
		} else if(sp.size() == 1){
			auto el = sp.rbegin();
			if(el->first >= 8){
				cout<<"YES"<<endl;
			} else {
				cout<<"NO"<<endl;
			}	
		} else {
			auto it = sp.end();
			auto p1 = --it;
			auto p2 = --it;
			int l1 = max(p1->first, p2->first), l2 = min(p1->first, p2->first);

			if((l1>=8) || (l1 >= 6 && l2 >= 2) || (l1>=4 && l2>=4)){
				cout<<"YES"<<endl;
			} else {
				if(sp.size() >= 3){
					auto it = sp.end();
					auto p1 = --it;
					auto p2 = --it;
					auto p3 = --it;

					if(p1->first >= 4 && p2->first >= 2 && p3->first >= 2){
						cout<<"YES"<<endl;
					} else {
						cout<<"NO"<<endl;
					}
				} else {
					cout<<"NO"<<endl;
				}
			}
		} 

	}

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
