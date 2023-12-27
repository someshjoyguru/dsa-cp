#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{

    int v0, v1, v2;
    std::cin >> v0 >> v1 >> v2;

    int v3 = 1;
    int v4 = v3 - v3;
    int v5 = v4 - v3;
    int v6 = v3;
    int v7 = v4 - v1;
    int v8 = v0;
    int v9 = v0 + v1;
    int v10 = v4;
    int v11 = v4;
    int v12 = v3;

    goto l0;
l1:
    v11 += v1;
    v10 += v0;
    int v13 = v10;
    int v14 = v4;
    int v15 = v4;

l1_inner:
    int v16 = v13 + v13;

    if (v16 <= v1) {
        v13 -= v1;
        v14 += v3;
        v15 += v1;
        goto l1_inner;
    }

    if (v13 > v4) {
        v13 = v4 - v13;
    }

    goto l2;

l2:
    if (v13 > v4) {
        goto l3;
    }

    v13 = v4 - v13;

l3:
    int v17 = v4;
    int v18 = v3;

l4:
    if (v18 > v6) {
        goto l6;
    }

    if (v17 < 0 || v17 >= v0 || v18 >= v2) {
        goto l5;
    }

    if (v17 >= 0 && (v18 + 1) * v0 - (v17 + 1) * v1 <= 0) {
        goto l5;
    }

    --v17;
    ++v18;
    goto l4;

l5:
    if (v18 > 0 && (v17 + 1) * v0 - (v18 - 1) * v1 >= 0 && (v17 + 1) * v0 - (v18 + 1) * v1 <= 0 && !(v17 >= v0)) {
        std::cout << v6 << std::endl;
        return 0;
    }

l6:
    ++v12;

    if (v12 <= v2) {
        goto l0;
    }

    return;

l0:
    goto l1;
}



int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}