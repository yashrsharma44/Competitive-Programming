#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPalin(string s){
	ll p1=0, p2 = s.length() - 1;

	while(p1 < p2){
		if(s[p1] != s[p2]){
			return false;
		}
		p1++;
		p2--;
	}

	return true;
}

void solve(){

	ll n,m;
	cin>>n>>m;

	vector<string> ans;
	ll nn = n;
	while(nn--){
		string s;
		cin>>s;

		ans.push_back(s);
	}

	// Choose a big palindrome
	string palin = "";
	ll idx = 0;
	ll ctr = 0;
	for(string word : ans){
		if(isPalin(word)){
			palin = word;
			idx  =  ctr;
			break;
		}
		ctr++;
	}

	vector < pair <string, string> >palinPair;
	vector <bool> visited(ans.size(), false);
	for(ll i=0;i<n;i++){

		for(ll j=0;j<n;j++){

			if(i!=j && (i!=idx || j!=idx) && (visited[i] == false &&  visited[j] == false)){
				string cpy = ans[j];
				reverse(cpy.begin(), cpy.end());
				if(ans[i] == cpy){
					palinPair.push_back(make_pair(ans[i], ans[j]));
					visited[i] = true;
					visited[j] = true;
				}
			}
		}
	}

	string ann = palin;
	for(ll i=0;i<palinPair.size();i++){

		ann = palinPair[i].first + ann;
		ann = ann + palinPair[i].second;
	}

	cout<<ann.length()<<endl;
	cout<<ann<<endl;


}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}

}