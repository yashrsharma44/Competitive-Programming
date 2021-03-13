#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

void next(string &s, int h, int m){
	int hh = stoi(s.substr(0, 2)), mm = stoi(s.substr(3, 2));
	mm += 1;
	if(mm == m){
		s[3] = '0';
		s[4] = '0';
		hh+=1;
		if(hh == h){
			s[0] = '0';
			s[1] = '0';
		} else {
			s[0] = (char)(48 + hh / 10);
			s[1] = (char)(48 + hh % 10); 
		}
	} else {
		s[3] = (char)(48 + mm / 10);
		s[4] = (char)(48 + mm % 10);
	}
	// cout<<s<<endl;
}

bool same(string &s1, int h, int m, map<char,char> &mp){


	string nw = "";
	for(char c : s1){
		if(mp.count(c) > 0){
			nw += mp[c];
			continue;
		}
		return false;
	}
	reverse(nw.begin(), nw.end());
	int hh = stoi(nw.substr(0, 2)), mm = stoi(nw.substr(3, 2));
	if(hh>=0 && hh<h && mm>=0&&mm<m) return true;
	return false;
}

void solve()
{	
	map<char,char> mp;
	mp['1'] = '1';
	mp['2'] = '5';
	mp['5'] = '2';
	mp['8'] = '8';
	mp['0'] = '0';
	mp[':'] = ':';

	int h,m; cin>>h>>m;
	string s; cin>>s;
	string s1 = s;
	bool isPos = true;
	for(int i=0;i<(2*h*m);i++){
		isPos = false;
		
		if(same(s1, h, m, mp)){
			cout<<s1<<endl;
			return;
		}
		// cout<<s1<<endl;
		next(s1, h, m);
	}
	assert(0);
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	// t = 1;

	while (t--)
	{
		solve();
	}
}
