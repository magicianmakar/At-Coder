#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PII pair<int , int>
#define PLI pair<LL  , int>
#define PLL pair<LL , LL>
#define bit(x) (1<<x)
#define bitl(x) (1LL<<x)
#define cnti(x) (__builtin_ctz(x))
#define cntl(x) (__builtin_ctzll(x))
#define clzi(x) (__builtin_clz(x))
#define clzll(x) (__builtin_clzll(x))

#define Error(x) cerr<<#x<<" = "<<x<<endl;

int N, Q;

map<int , int > Y , R;

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>N>>Q;
	while(Q--){
		int a , b;
		cin>>a>>b;
		if(a == 1) Y[b]++;
		else if(a == 2) R[b]++;
		else{
			if(R[b]) cout<<"Yes\n";
			else if(Y[b] >= 2) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}

