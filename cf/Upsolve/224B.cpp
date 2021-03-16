#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

class MS {
public:
	map<int, int> mp;
	MS(){}
	void add(int el){
		mp[el]+=1;
	}

	void remove(int el){
		mp[el]-=1;
		if(mp[el] == 0) mp.erase(el);
	}

	int size(){
		return mp.size();
	}
};

void solve(){

	int n,k; cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	int l = -1, r = -1;
	MS *ms = new MS();
	int ll = 0;
	for(int i=0;i<n;i++){
		ms->add(a[i]);
		while(ms->size() >= k){
			l = ll+1; r = i+1;
			ms->remove(a[ll]);
			ll++;
		}
	}

	cout<<l<<" "<<r<<endl;


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