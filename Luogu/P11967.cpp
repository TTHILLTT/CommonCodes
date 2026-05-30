#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a, bu, bv, d[1000005], f[1000005][25], s[1000005], s1[1000005];
vector<int> e[1000005];
void dfs(int x, int fa)
{
	d[x] = d[fa] + 1;
	f[x][0] = fa;
	for (int i = 1;i <= 19;i++)
        f[x][i] = f[f[x][i - 1]][i - 1];
	for(auto y : e[x])
	{
		if(y == fa)
			continue;
		dfs(y, x);
	}
}
void dfs1(int x, int fa)
{
	for(auto y : e[x])
	{
		if(y == fa)
			continue;
		dfs1(y, x);
		s[x] += s[y];
	}
}
void dfs2(int x, int fa)
{
	for(auto y : e[x])
	{
		if(y == fa)
			continue;
		dfs2(y, x);
		s1[x] += s1[y];
	}
}
int lca(int x, int y) {
    if (d[x] < d[y])
        swap(x, y);
    for (int i = 19;i >= 0;i--)
        if (d[f[x][i]] >= d[y])
            x = f[x][i];
    if (x == y)
        return x;
    for (int i = 19;i >= 0;i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}
signed main() {
    cin >> n >> a;
    for(int i = 1;i < n;i++)
    {
    	int x, y;
    	cin >> x >> y;
    	e[x].push_back(y);
    	e[y].push_back(x);
	}
	dfs(1, 0);
	for(int i = 1;i <= a;i++)
	{
		int u, v;
		cin >> u >> v;
		int l = lca(u, v);
		s[u]++, s[v]++, s[l]--, s[f[l][0]]--;
	}
	dfs1(1, 0);
	cin >> bu >> bv;
	int l = lca(bu, bv);
	s1[bu]++, s1[bv]++, s1[l]--, s1[f[l][0]]--;
	dfs2(1, 0);
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(s1[i] > 0 && s[i] <= 0)
			ans++;
	}
	cout << ans;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/