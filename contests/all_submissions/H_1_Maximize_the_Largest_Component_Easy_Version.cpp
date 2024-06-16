#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;

class DisjointSet {

public:
    vector<ll> rank, parent, size;
    DisjointSet(ll n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (ll i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    ll findUPar(ll node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(ll u, ll v) {
        ll ulp_u = findUPar(u);
        ll ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool isValid(ll newr, ll newc, ll n, ll m) {
    return newr >= 0 && newr < n && newc >= 0 && newc < m;
}

ll MaxConnection(vector<vector<ll>>& grid, vll& rowcc, vll& colcc) {
    ll n = grid.size();
    ll m = grid[0].size();
    DisjointSet ds(n * m);
    // step - 1
    for (ll row = 0; row < n; row++) {
        for (ll col = 0; col < m; col++) {
            if (grid[row][col] == 0) continue;
            ll dr[] = { -1, 0, 1, 0 };
            ll dc[] = { 0, -1, 0, 1 };
            for (ll ind = 0; ind < 4; ind++) {
                ll newr = row + dr[ind];
                ll newc = col + dc[ind];
                if (isValid(newr, newc, n, m) && grid[newr][newc] == 1) {
                    ll nodeNo = row * m + col;
                    ll adjNodeNo = newr * m + newc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }

    // step 2
    ll mx = 0;
    for (ll row = 0; row < n; row++) {
        set<ll> components;
        for (ll col = 0; col < m; col++) {
            if (grid[row][col] == 1) components.insert(ds.findUPar(row * m + col));
            ll dr[] = { -1, 1};
            for (ll ind = 0; ind < 2; ind++) {
                ll newr = row + dr[ind];
                if (isValid(newr, col, n, m)) {
                    if (grid[newr][col] == 1) components.insert(ds.findUPar(newr * m + col));
                }
            }
        }
        ll sizeTotal = 0;
        for (auto it : components) {
            sizeTotal += ds.size[it];
        }
        mx = max(mx, sizeTotal + rowcc[row]);
    }

    for (ll col = 0; col < m; col++) {
        set<ll> components;
        for (ll row = 0; row < n; row++) {
            if (grid[row][col] == 1) components.insert(ds.findUPar(row * m + col));
            ll dc[] = { -1, 1};
            for (ll ind = 0; ind < 2; ind++) {
                ll newc = col + dc[ind];
                if (isValid(row, newc, n, m)) {
                    if (grid[row][newc] == 1) components.insert(ds.findUPar(row * m + newc));
                }
            }
        }
        ll sizeTotal = 0;
        for (auto it : components) {
            sizeTotal += ds.size[it];
        }
        mx = max(mx, sizeTotal + colcc[col]);
    }

    for (ll cellNo = 0; cellNo < n * m; cellNo++) {
        mx = max(mx, ds.size[ds.findUPar(cellNo)]);
    }
    return mx;
}

void solve() {
    in(n) in(m)
    vector<vector<ll>> grid;
    f(i, 0, n) {
        sin(s)
        vll temp;
        f(j, 0, m) {
            if (s[j] == '#') temp.push_back(1);
            else temp.push_back(0);
        }
        grid.push_back(temp);
    }
    vll rowcc(n, 0);
    vll colcc(m, 0);
    f(i, 0, n) {
        f(j, 0, m) {
            if (grid[i][j] == 0) rowcc[i]++;
        }
    }
    f(i, 0, m) {
        f(j, 0, n) {
            if (grid[j][i] == 0) colcc[i]++;
        }
    }
    cout << MaxConnection(grid, rowcc, colcc) << endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();
}
