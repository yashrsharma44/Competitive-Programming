#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005

bool check(string &s, int i, int j, int k, string &t){
	string ss="";
	for(int z=0;z<s.length();z++){
		if(s[z] == 'A'){
			ss += t[i];
		} else if(s[z] == 'B'){
			ss += t[j];
		} else {
			ss += t[k];
		}
	}

	stack<char> st;
	for(auto ch : ss){
		if(!st.empty() && ch == ')' && st.top() == '('){
			st.pop();
		} else {
			st.push(ch);
		}
	}
	return st.empty();
}

void solve()
{
	string s; cin>>s;
	string t = "()";
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				if(check(s, i, j, k, t)){
					cout<<"YES"<<endl;
					return;
				}
			}
		}
	}
	cout<<"NO"<<endl;

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
