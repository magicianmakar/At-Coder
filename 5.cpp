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

#define MAX 1000000000
#define mx 2005

int n , m;
int dist[mx][mx];
vector< int > con[mx];

void dijkstra(int st){
	priority_queue< int , vector< int > , greater<int> > que;
	while(!que.empty()) que.pop();
	for(int i =  0 ; i < n ; i++ ) dist[st][i] = MAX;
	dist[st][st] = 0;
	que.push(st);
	while(!que.empty()){
		int u = que.top();que.pop();
		for(int i = con[u].size() - 1 ; ~i ; i-- ){
			int v = con[u][i];
			if(dist[st][u] + 1 < dist[st][v]){
				dist[st][v] = dist[st][u] + 1;
				que.push(v);
			}
		}
	}
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++ ){
		int u , v;
		cin>>u>>v;
		u-- , v--;
		con[u].push_back(v);
	}
	for(int i=0 ;i  < n ; i++ ) dijkstra(i);
	int ans = 0;
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < n ; j++ ) if(dist[i][j] > 1 && dist[i][j] < MAX){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

