// Replaced all occurences of double with long double
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 64;

struct matrix {
    long double m[MAXN][MAXN];

    matrix() {
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                m[i][j] = 0;
    }

    matrix operator*(const matrix& other) const {
        matrix res = matrix();
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                for (int k = 0; k < MAXN; k++)
                    res.m[i][j] += m[i][k] * other.m[k][j];
        return res;
    }
};

matrix matrix_pow(int n, matrix m) {
    if (n == 1) return m;
    matrix m2 = matrix_pow(n / 2, m);
    return n % 2 ? m * m2 * m2 : m2 * m2;
}

int r, c, n;
long double p;

int main() {
    cin >> r >> c >> n >> p;
    matrix dice;
    for (int i = 0; i < r * c; i++) {
        for (int j = i + 1; j <= i + 6; j++)
            dice.m[i][min(j, r * c - 1)] += 1.0l / 6.0l;
    }

    matrix ladder;
    for (int i = 0; i < r * c; i++)
        ladder.m[i][i] = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ladder.m[a][a] = 0;
        ladder.m[a][b] = 1;
    }

    matrix mat = dice * ladder;

    int a = 1, b = 100000000;
    while (a < b) {
        int m = (a + b) / 2;
        if (matrix_pow(m, mat).m[0][r * c - 1] >= p) b = m;
        else a = m + 1;
    }
    cout << a << endl;
}

