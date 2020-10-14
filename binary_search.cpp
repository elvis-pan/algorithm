#include <bits/stdc++.h>
using namespace std;

// Standard binary search for some integer
int binary_search(vector<int> a, int k) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        //@loop_invariant A[0:lo) < k, A[hi, n) > k
        int mid = lo + (hi - lo) / 2; // avoid overflow
        if (a[mid] == k) return mid;
        else if (a[mid] < k) lo = mid+1;
        else hi = mid;
    }
    return -1;
}

// Binary search to find boundary of monotonic function
bool check(int k) {
    return 1;
}

// Find minimum true
int binary_search_true(int n) {
    int lo = 0, hi = n;
    if (check(lo)) return lo;
    if (!check(hi)) return -1; // no solution
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    return hi;
}

// Find maximum false
int binary_search_false(int n) {
    int lo = 0, hi = n;
    if (check(lo)) return -1;
    if (!check(hi)) return hi;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}
