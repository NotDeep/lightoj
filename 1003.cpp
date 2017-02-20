#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 20010;
struct Edge{
	int to, next;
};
Edge edge[MAXN >> 1];
int head[MAXN], ind[MAXN];
void addEdge(int u, int v, int k){
	edge[k].to = v;
	edge[k].next = head[u];
	head[u] = k;
}
int main(){
	int t, m, CASE(0);
	string str1, str2;
	//freopen("in.cpp", "r", stdin);
	scanf("%d", &t);
	while(t--){
		int NUM(0), cnt(0);
		map<string, int>mp;
		memset(ind, 0,  sizeof ind);
		memset(head, -1, sizeof head);
		scanf("%d", &m);
		for(int i = 0;i < m;i ++){
			int u, v;
			cin >> str1 >> str2;
			map<string, int>::iterator it = mp.find(str1);
			if(it == mp.end()) mp.insert(pair<string, int>(str1, ++NUM)), u = NUM;
			else u = it->second;
			it = mp.find(str2);
			if(it == mp.end()) mp.insert(pair<string, int>(str2, ++NUM)), v = NUM;
			else v = it->second;
			ind[u]++;
			addEdge(v, u, i+1);
		}
		while(cnt < NUM){
			int pos = 0;
			for(int i = 1;i <= NUM;i ++){
				if(ind[i] == 0){
					cnt++;
					ind[i]--;
					pos = i;
					break;
				}
			}
			if(!pos) break;
			for(int i = head[pos]; ~i; i = edge[i].next){
				int v = edge[i].to;
				ind[v]--;
			}
		}
		if(cnt == NUM) printf("Case %d: Yes\n", ++CASE);
		else printf("Case %d: No\n", ++CASE);
	}
	return 0;
}
