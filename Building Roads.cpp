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

int n, m;
vector<int> a[N];
vector<int> represent;
vector<bool> d(N,false);

void readfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen("test_input.txt","r"))
    {
        freopen("test_input.txt","r",stdin);
        //freopen(Task".out","w",stdout);
    }
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
}

void dfs(int u)
{
    d[u] = 1;
    for(int i=0; i<a[u].size(); i++)
    {
        int v = a[u][i];
        if (!d[v])
        {
            dfs(v);
        }
    }
}

void proc()
{
    for(int i=1; i<=n; i++)
    {
        if (!d[i]){
            represent.pb(i);
            dfs(i);
        }
    }
    cout << represent.size()-1 << '\n';
    for(int i=1; i<represent.size(); i++)
    {
        cout << represent[0] << ' ' << represent[i] << '\n';
    }
}

signed main()
{
    readfile();
    proc();
    return 0;
}
