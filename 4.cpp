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

#define mx 200010

int N , M;
vector< int > con[mx];
int vis[mx] ,  comp[mx] , edge[mx] , cnt = 0;

void dfs(int u){
	comp[cnt]++;
	vis[u] = cnt;
	for(int i = con[u].size() - 1 ; ~i ; i-- ){
		int v = con[u][i];edge[cnt]++;
		if(vis[v]) continue;
		vis[v] = cnt;
		dfs(v);
	}
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>N>>M;
	for(int i = 0 ; i < M ; i++ ){
		int u , v;
		cin>>u>>v;
		con[u].push_back(v) , con[v].push_back(u);
	}
	for(int i = 0 ; i < N ; i++ ){
		if(vis[i+1]) continue;
		cnt++;
		dfs(i+1);
	}
	for(int i = 1 ; i <= cnt ; i++ ){
		if(2*comp[i] != edge[i]) return cout<<"No"<<endl , 0;
	}
	cout<<"Yes"<<endl;
	return 0;
}

