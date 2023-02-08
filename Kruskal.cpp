#include<bits/stdc++.h>
using namespace std;
const int N=105;
int fa[N];
struct Edge
{
	int u,v,w;
}edge[N*N];
int findfa(int x) 
{
	if(x==fa[x]) return x;
	return findfa(fa[x]);
}
int n,m;
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
bool cmp(Edge x,Edge y) {
	return x.w<y.w;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	
	//kruskal
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int fax=findfa(edge[i].u);
		int fay=findfa(edge[i].v);
		if(fax==fay) continue;
		fa[fax]=fay;
		ans+=edge[i].w;
	}
	printf("%d\n",ans);
	return 0;
} 
