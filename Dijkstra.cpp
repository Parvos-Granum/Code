#include<bits/stdc++.h>
using namespace std;
const N=1e5+5;
int n,m,s;//n:结点数 m:边数  s:起点 
int tot=0,head[N],ver[N<<1],nxt[N<<1],edge[N<<1];
int dis[N];//dis[i]:s到i最短路
bool vis[N];//i节点是否在A集合中 
priority_queue<pair<int,int> > q;//pair<i,dis[i]>
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
void add(int x,int y,int z)
{
	tot++;
	ver[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
	edge[tot]=z;
}
void Dijkstra(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(make_pair(s,dis[s]));
	while(!q.empty())
	{
		int x=q.top().first;
		q.pop();
		if(vis[x]==true) continue;
		vis[x]=true;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			if(vis[y]==true) continue;
			if(dis[y]>dis[x]+edge[i])
			{
				dis[y]=dis[x]+edge[i];
				q.push(make_pair(y,-dis[y]));
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
}
int main()
{
	n=read(),m=read(),s=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);	
	} 
	Dijkstra(s);
	return 0;	
} 
//Dijkstra 单源最短路 
