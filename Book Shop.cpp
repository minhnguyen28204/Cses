//Nguyen Huu Hoang Minh
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 1005
#define remain(x) if (x > MOD) x -= MOD
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< ii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "test"

using namespace std;

typedef long double ld;

int n,x;
int h[N], s[N];
int dp[N][100005];

void readfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen(Task".inp","r"))
    {
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    cin >> n >> x;
    for(int i=1; i<=n; i++) cin >> h[i];
    for(int i=1; i<=n; i++) cin >> s[i];
}

void proc()
{
    dp[0][0] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=x; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (h[i] <= j) dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]]+s[i]);
        }
    }
    cout << dp[n][x];
}

signed main()
{
    readfile();
    proc();
    return 0;
}
