#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

map<int,multiset<int> > mp;

void erase(multiset<int> &s1, multiset<int> &s2, multiset<int> &s3, int val){
	auto it1 = s1.find(val);
	if(it1!=s1.end())
	s1.erase(it1);

	auto it2 = s2.find(val);
	if(it2!=s2.end())
	s2.erase(it2);

	auto it3 = s3.find(val);
	if(it3!=s3.end())
	s3.erase(it3);
}

int get(multiset<int> &s){
	if(s.size() == 0) return -1;
	return *s.rbegin();
}

pair<int,int> getMax(multiset<int> &rr, multiset<int> &gg, multiset<int> &bb, int idx){
	vector<pair<int,int> > m({{get(rr),0}, {get(gg),1}, {get(bb),2}});
	if(idx != -1){
		m.erase(m.begin()+idx);
	}
	sort(m.begin(), m.end());
	auto max_ = m[m.size()-1];
	int id = max_.second;
	auto it = mp[id].find(max_.first);
	if(it!=mp[id].end()){
		mp[id].erase(it);
	}
	rr = mp[0]; gg = mp[1]; bb = mp[2];

	return max_;
}

void solve(){

	int r,g,b;
	cin>>r>>g>>b;
	multiset<int> rr,gg,bb;
	for(int i=0;i<r;i++){
		int vl;
		cin>>vl;
		rr.insert(vl);
	}

	for(int i=0;i<g;i++){
		int vl;
		cin>>vl;
		gg.insert(vl);
	}

	for(int i=0;i<b;i++){
		int vl;
		cin>>vl;
		bb.insert(vl);
	}
	mp[0] = rr; mp[1] = gg; mp[2] = bb;

	int ans = 0;
	while(true){

		int s1 = rr.size(), s2 = gg.size(), s3 = bb.size();
		if(s1 == 0 && s2 == 0 || s3 == 0 && s2 == 0 || s1 == 0 && s3 == 0){
			break;
		}

		if(s1 != 0 && s2 != 0 && s3 != 0){
			auto m1 = getMax(rr,gg,bb,-1);
			auto m2 = getMax(rr,gg,bb, m1.second);
			ans += (m1.first*m2.first);
		} else {
			auto m1 = getMax(rr,gg,bb,-1);
			auto m2 = getMax(rr,gg,bb, m1.second);
			if(m1.first == -1 || m2.first == -1) break;
			ans += (m1.first*m2.first);
		}
	}

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
