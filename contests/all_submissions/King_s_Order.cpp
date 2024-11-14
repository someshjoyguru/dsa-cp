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
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

int main() {
    in(N) in(M)
    vector<int> group_id(N);
    for (int i = 0; i < N; i++) {
        cin >> group_id[i];
    }

    vector<vector<int>> adj(N);
    vector<int> in_degree(N, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        adj[A].push_back(B);
        in_degree[B]++;
    }

    auto cmp = [&](int a, int b) {
        if (group_id[a] == group_id[b]) return a > b;
        return group_id[a] > group_id[b];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u + 1);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                pq.push(v);
            }
        }
    }

    if (result.size() == N) {
        for (int proj : result) {
            cout << proj << " ";
        }
    } else {
        cout << -1;
    }

    return 0;
}
