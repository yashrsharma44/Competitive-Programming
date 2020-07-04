#include <bits/stdc++.h>
#define int long long 

using namespace std;

bool check(string &s, vector<int> &a){

	int p1 = 0, p2 = s.length()-1;
	while(p1 < p2){
		
		if(s[p1] == '('){
			while(s[p2] != ')'){
				p2--;
			}
			if(p2 < p1){
				break;
			}
			s[p1] = '^';
			s[p2] = '*';
			a.push_back(p1+1);
			a.push_back(p2+1);
			p1++;
			p2--;
		} else {
			p1++;
		}
	}
	sort(a.begin(), a.end());
	return a.size() != 0;

}

void solve(){

	string s;
	cin>>s;
	vector<vector<int> > ans;
	for(int i=1;i<=1000;i++){

		vector<int> a;
		if(!check(s, a)){
			break;
		} else {
			a.insert(a.begin(), (int)a.size());
		}
		ans.push_back(a);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i][0]<<endl;
		for(int j=1;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
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
