#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
int N;
string S[200000];
using st = array<int, 3>;
int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> S[i];

    vector<st> v(N);
    for (int i = 0; i < N; ++i) {
        v[i][0] = i;
        for (char c : S[i])
            if (c == 'X') ++v[i][1];
            else v[i][2] += c - '0';
    }

    sort(v.begin(), v.end(), [](st &x, st &y) { return (ll)x[1] * y[2] > (ll)x[2] * y[1]; });
    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        for (char c : S[v[i][0]])
            if (c == 'X') ++cnt;
            else ans += cnt * (c - '0');
    cout << ans << '\n';
}
