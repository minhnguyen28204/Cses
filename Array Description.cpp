//Nguyen Huu Hoang Minh
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100005
#define remain(x) if (x > MOD) x -= MOD
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< ii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "test"
#define int long long

using namespace std;

typedef long double ld;
const int Mod = 1e9+7;

int n,m;
int a[N];

void readfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen(Task".inp","r"))
    {
        freopen(Task".inp","r",stdin);
        //freopen(Task".out","w",stdout);
    }
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m+1,0));
    int a0;
    cin >> a0;
    if (a0 == 0) fill(dp[0].begin(),dp[0].end(),1);
    else dp[0][a0]=1;
    for(int i=1; i<n; i++)
    {
        int x;
        cin >> x;
        if (x==0){
            for(int j=1; j<=m; j++)
            {
                for(int k : {j-1, j, j+1}){
                    if (k >= 1 && k <= m) (dp[i][j] += dp[i-1][k]) %= Mod;
                }
            }
        }
        else{
            for(int k : {x-1, x, x+1}){
                if (k >= 1 && k <= m) (dp[i][x] += dp[i-1][k]) %= Mod;
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=m; i++) (ans += dp[n-1][i])%=Mod;
    cout << ans;
}

signed main()
{
    readfile();
    return 0;
}
