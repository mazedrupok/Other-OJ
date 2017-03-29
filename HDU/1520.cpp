#include <bits/stdc++.h>
using namespace std;
#define MX 100005
vector <int> g[MX];
int dp[MX][2];
int ara[MX];
int par[MX];
int dfs (int u, int par, bool t) {
    int &ret = dp[u][t];
    if (ret != -1) return ret;
    ret = 0;
    if (t == 0) ret = ara[u];
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (t == 0) ret += dfs (v, u, 1);
        else ret += max (dfs (v, u, 0), dfs (v, u, 1));
    }
    return ret;
}
int main()
{

    int n, u, v, x;
    while (scanf (" %d", &n) == 1) {
        ara[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf (" %d", &ara[i]);
            ara[i] = max (0, ara[i]);
        }
        memset (dp, -1, sizeof (dp));
        memset (par, -1, sizeof (par));
        while (scanf (" %d %d", &u, &v) == 2) {
            if (u == 0 && v == 0) break;
            g[v].push_back (u);
            par[u] = v;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (par[i] == -1) {
                ans += max(dfs (i, -1, 0), dfs(i, -1, 1));
            }
        }
        printf ("%d\n", ans);
        vector <int> tt[MX]; swap (g, tt);
    }
    return 0;
}
