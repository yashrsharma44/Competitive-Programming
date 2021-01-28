#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	string s; cin>>s;
	string ss="";
	int p1 = 0;
	stack<char> st;
	while(p1 < s.length()){

		if(st.size() >= 3){
			char top1 = st.top(); st.pop();
			char top2 = st.top(); st.pop();
			char top3 = st.top(); st.pop();
			
			if(top1 == top2 && top2 == top3){
				st.push(top1);
				st.push(top2);
			} else {
				st.push(top3);
				st.push(top2);
				st.push(top1);
			}			
		} 

		st.push(s[p1]);
		p1++;
	}

	if(st.size() >= 3){
		char top1 = st.top(); st.pop();
		char top2 = st.top(); st.pop();
		char top3 = st.top(); st.pop();
		
		if(top1 == top2 && top2 == top3){
			st.push(top1);
			st.push(top2);
		} else {
			st.push(top3);
			st.push(top2);
			st.push(top1);
		}			
	} 


	// for(auto el : st){
	// 	cout<<el<<endl;
	// }

	p1 = 0;
	s = "";
	while(st.size() > 0){
		if(st.size() >= 4){
			char top1 = st.top(); st.pop();
			char top2 = st.top(); st.pop();		
			char top3 = st.top(); st.pop();
			char top4 = st.top(); st.pop();
			
			if(top1 == top2 && top3 == top4){
				if(top2 == top3){
					s += top3;
					s += top4;
					st.push(top3);
					st.push(top3);
				} else {
					s += top1;
					s += top2;
					st.push(top4);
					// st.push(top3);
				}
				continue;
			} else {
				st.push(top4);
				st.push(top3);
				st.push(top2);
				s += top1;
			}
		} else {
			char top = st.top(); st.pop();
			s += top;
		}
	}
	reverse(s.begin(), s.end());
	cout<<s<<endl;

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
