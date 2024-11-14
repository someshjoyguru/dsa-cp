#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegmentTree {
    int n;
    vector<ll> salaryTree, happinessTree, lazySet, lazyAdd,prevSalary;
    vector<bool> lazyFlag;

    SegmentTree(int size) {
        n = size;
        salaryTree.assign(4 * n, 0);
        happinessTree.assign(4 * n, 0);
        lazySet.assign(4 * n, 0);
        lazyAdd.assign(4 * n, 0);
        lazyFlag.assign(4 * n, false);
        prevSalary.resize(n, 0);
    }

    void build(const vector<ll> &salaries, int v, int tl, int tr) {
        if (tl == tr) {
            salaryTree[v] = salaries[tl];
            happinessTree[v] = 0;
        } else {
            int tm = (tl + tr) / 2;
            build(salaries, v * 2, tl, tm);
            build(salaries, v * 2 + 1, tm + 1, tr);
            salaryTree[v] = salaryTree[v * 2] + salaryTree[v * 2 + 1];
        }
    }

    void push(int v, int tl, int tr) {
        if (lazyFlag[v]) {
            int tm = (tl + tr) / 2;
            applySet(v * 2, tl, tm, lazySet[v]);
            applySet(v * 2 + 1, tm + 1, tr, lazySet[v]);
            lazyFlag[v] = false;
            lazySet[v] = 0;
        }
        if (lazyAdd[v] != 0) {
            int tm = (tl + tr) / 2;
            applyAdd(v * 2, tl, tm, lazyAdd[v]);
            applyAdd(v * 2 + 1, tm + 1, tr, lazyAdd[v]);
            lazyAdd[v] = 0;
        }
    }

    void applySet(int v, int tl, int tr, ll value) {
        salaryTree[v] = value * (tr - tl + 1);
        happinessTree[v] = 0;
        lazyFlag[v] = true;
        lazySet[v] = value;
        lazyAdd[v] = 0;
    }

    void applyAdd(int v, int tl, int tr, ll value) {
        salaryTree[v] += value * (tr - tl + 1);
        happinessTree[v] += (value > 0 ? tr - tl + 1 : -(tr - tl + 1));
        if (lazyFlag[v]) {
            lazySet[v] += value;
        } else {
            lazyAdd[v] += value;
        }
    }

    void updateSet(int v, int tl, int tr, int l, int r, ll value) {
        if (l > r) return;
        if (l == tl && r == tr) {
            applySet(v, tl, tr, value);
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            updateSet(v * 2, tl, tm, l, min(r, tm), value);
            updateSet(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, value);
            salaryTree[v] = salaryTree[v * 2] + salaryTree[v * 2 + 1];
            happinessTree[v] = happinessTree[v * 2] + happinessTree[v * 2 + 1];
        }
    }

    void updateAdd(int v, int tl, int tr, int l, int r, ll value) {
        if (l > r) return;
        if (l == tl && r == tr) {
            applyAdd(v, tl, tr, value);
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            updateAdd(v * 2, tl, tm, l, min(r, tm), value);
            updateAdd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, value);
            salaryTree[v] = salaryTree[v * 2] + salaryTree[v * 2 + 1];
            happinessTree[v] = happinessTree[v * 2] + happinessTree[v * 2 + 1];
        }
    }

    ll querySum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l <= tl && tr <= r) return salaryTree[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return querySum(v * 2, tl, tm, l, min(r, tm))
             + querySum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    ll queryHappiness(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l <= tl && tr <= r) return happinessTree[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return queryHappiness(v * 2, tl, tm, l, min(r, tm))
             + queryHappiness(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void printFraction(ll num, ll den) {
    ll g = gcd(abs(num), abs(den));
    num /= g;
    den /= g;
    if (den < 0) {
        num = -num;
        den = -den;
    }
    cout << num << '/' << den << '\n';
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> salaries(n);
    for (int i = 0; i < n; i++) {
        cin >> salaries[i];
    }
    
    SegmentTree segTree(n);
    segTree.build(salaries, 1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        l--, r--;
        if (type == 0) {
            ll c;
            cin >> c;
            segTree.updateSet(1, 0, n - 1, l, r, c);
        } else if (type == 1) {
            ll c;
            cin >> c;
            segTree.updateAdd(1, 0, n - 1, l, r, c);
        } else if (type == 2) {
            ll sum = segTree.querySum(1, 0, n - 1, l, r);
            printFraction(sum, r - l + 1);
        } else if (type == 3) {
            ll happiness = segTree.queryHappiness(1, 0, n - 1, l, r);
            printFraction(happiness, r - l + 1);
        }
    }
    return 0;
}
