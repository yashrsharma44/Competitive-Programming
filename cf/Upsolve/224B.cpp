#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

class MS{
public:
	map<int,int> mp;
	MS(){
	}

	void add(int k){
		mp[k] += 1;
	}

	int count(int k){
		return mp[k];
	}

	void erase(int k){
		mp[k] -= 1;
		if(mp[k] == 0){
			mp.erase(k);
		}
	}

	int size(){
		return mp.size();
	}
};

void solve(){

	int n,k; cin>>n>>k;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	MS *ms= new MS();
	
	for(auto el : a){
		ms->add(el);
	}

	if(ms->size() < k){
		cout<<-1<<" "<<-1<<endl;
		return;
	}

	int p1 = n-1;
	while(ms->size() >= k){
		ms->erase(a[p1]);
		p1--;
	}

	p1++; ms->add(a[p1]);
	int r = p1;

	int p2 = 0;
	while(ms->size() >= k){
		ms->erase(a[p2]);
		p2++;
	}
	p2--;ms->add(a[p2]);
	int l = p2;

	cout<<l+1<<" "<<r+1<<endl;
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



// 8,9,7 cur date cur year pehl 2100 mein nhi chalega,