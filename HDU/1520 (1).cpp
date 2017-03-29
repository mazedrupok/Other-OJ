#include <bits/stdc++.h>
using namespace std;
#define MX 100005
vector <int> g[MX];
int dp[MX][2];
int ara[MX];
int par[MX];
void dfs (int u) {
    dp[u][1] = ara[u];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs (v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max (dp[v][0], dp[v][1]);
    }
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
        memset (dp, 0, sizeof (dp));
        memset (par, -1, sizeof (par));
        while (scanf (" %d %d", &u, &v) == 2) {
            if (u == 0 && v == 0) break;
            g[v].push_back (u);
            par[u] = v;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (par[i] == -1) {
                dfs (i);
                ans += max (dp[i][0], dp[i][1]);
            }
        }
        printf ("%d\n", ans);
        vector <int> tt[MX]; swap (g, tt);
    }
    return 0;
}
