#include <bits/stdc++.h>
using namespace std;

const int N = 220;
const int P = 1e9 + 7;

int a[N], b[N], c[N], d[N], e[N], dp[N];
long long s[N];

void solve(int *c, int m, long long n, int *a) {
    static int b[N + N];
    memset(a, 0, sizeof(a[0]) * m);
    a[0] = 1;
    for (int i = 59; i >= 0; i--) {
        if (n >> i < 1) continue;
        memset(b, 0, sizeof(b[0]) * 2 * m);
        int l = n >> i & 1;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                b[j + k + l] = (b[j + k + l] + a[j] * 1LL * a[k]) % P;
            }
        }
        for (int j = 2 * m - 1; j >= m; j--) if (b[j]) {
            for (int k = 1; k <= m; k++) b[j - k] = (b[j - k] + c[k] * 1LL * b[j]) % P;
            b[j] = 0;
        }
        memcpy(a, b, sizeof(b[0]) * m);
    }
}

void multiply(int *a, int *b, int *c, int m) {
    static int d[N + N];
    memset(d, 0, sizeof(d[0]) * (m + m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            d[i + j] = (d[i + j] + a[i] * 1LL * b[j]) % P;
        }
    }
    for (int j = 2 * m - 2; j >= m; j--) if (d[j]) {
        for (int k = 1; k <= m; k++) d[j - k] = (d[j - k] + c[k] * 1LL * d[j]) % P;
        d[j] = 0;
    }
    memcpy(a, d, sizeof(a[0]) * m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x, k, m; long long n; cin >> x >> k >> m >> n;
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
        if (n == s[i]) return cout << 0 << "\n", 0;
    }
    s[k + 1] = n;
    sort(s, s + k + 2);
    k = unique(s, s + k + 2) - s - 1;
    for (int i = 1; i <= m; i++) cin >> a[i];
    a[m] = (a[m] + 1) % P;
    b[0] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= i; j++) {
            b[i] = (b[i] + b[i - j] * 1LL * a[j]) % P;
        }
    }
    dp[0] = 1;
    d[0] = 1;
    for (int i = 1; i <= k; i++) {
        if (s[i] - s[i - 1] >= m) {
            memcpy(e, d, sizeof(e[0]) * m);
            solve(a, m, s[i] - s[i - 1] - m, c);
            multiply(e, c, a, m);
            solve(a, m, s[i] - s[i - 1], c);
            multiply(d, c, a, m);
        } else {
            solve(a, m, s[i] - s[i - 1], c);
            multiply(d, c, a, m);
            long long add = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (s[i - 1] - s[j] >= m) break;
                if (s[i] - s[j] < m) continue;
                add = min(add, s[i - 1] - s[j] - m);
            }
            if (add) {
                for (int i = 0; i < m; i++) c[i] = i == -add;
                multiply(e, c, a, m);
                for (int j = i - 1; j >= 0; j--) {
                    if (s[i - 1] - s[j] >= m) break;
                    if (s[i] - s[j] < m) continue;
                    int &ret = e[s[i - 1] - add - s[j] - m];
                    if (j == 0) ret = (ret + dp[j]) % P;
                    else ret = (ret + P - dp[j]) % P;
                }
                solve(a, m, s[i] - s[i - 1] + add, c);
            }
            multiply(e, c, a, m);
        }
        for (int j = 0; j < m; j++) {
            dp[i] = (dp[i] + 1LL * b[j] * (d[j] + P - e[j])) % P;
        }
        d[0] = (d[0] + P - dp[i]) % P;
        if (s[i] == n) {
            cout << dp[i] * 1LL * x % P << "\n";
        }
    }
    return 0;
}
