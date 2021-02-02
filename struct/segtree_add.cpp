#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t, int64_t>

/* Segment tree with range add query and range maximum query */
template <typename T>
class SegTree {
    int n;
    const int NEG_INF = -1e9;
    vector<T> tree;
    vector<T> add;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _build(a, v*2, tl, tmid);
        _build(a, v*2+1, tmid+1, tr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
    void _push(int v) {
        tree[v*2  ] += add[v];
        tree[v*2+1] += add[v];
        add[v*2  ] += add[v];
        add[v*2+1] += add[v];
        add[v] = 0;
    }
    void _update(int v, int tl, int tr, int l, int r, T val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            tree[v] += val;
            add[v] += val;
            return;
        }
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, l, min(r, tmid), val);
        _update(v*2+1, tmid+1, tr, max(l, tmid+1), r, val);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
    T _query(int v, int tl, int tr, int l, int r) {
        assert(v < 4*n);
        if (l > r)
            return NEG_INF;
        if (l <= tl && r >= tr)
            return tree[v];
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        return max(_query(v*2, tl, tmid, l, min(r, tmid)),
                   _query(v*2+1, tmid+1, tr, max(l, tmid+1), r));
    }
    T _get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return tree[v];
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(int n_) : n(n_) {
        tree.assign(4*n, 0);
        add.assign(4*n, 0);
        vector<T> a (n, 0);
        _build(a, 1, 0, n-1);
    }
    SegTree(vector<T>& a) : n(a.size()) {
        tree.assign(4*n, 0);
        add.assign(4*n, 0);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, const SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)   { _build(a, 1, 0, n-1); }
    void update(T val, int l, int r) { _update(1, 0, n-1, l,   r,   val); }
    void update(T val, int pos)      { _update(1, 0, n-1, pos, pos, val); }
    T query(int l, int r)            { return _query(1, 0, n-1, l, r); }
    T get(int pos)                   { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)            { return get(pos); }
};

int t = 1, n, m, k, q;

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
