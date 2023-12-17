#include <iostream>
#include <vector>
#include <cassert>
#include <string.h>
	
using namespace std;

const int MOD = 10000000;
int C, N;
int cache[101][101];

int _poly(int n, int first) {
	// output: the number of polynomio with 'first' number of first squares
	assert (first <= n);
	if (n == first) return 1;

	int& ret = cache[n][first];
	if (ret != -1) return ret;

	ret = 0;
	for (int f = 1; f <= n-first; ++f) {
		ret += ((first + f - 1) * _poly(n-first, f)) % MOD;
	}
	return ret %= MOD;
}

int poly(int n) {
	int ret = 0;
	for (int f = 1; f <= n; ++f) {
		ret += _poly(n, f);
	}
	return ret % MOD;
}

void solve() {
	cin >> C;
	for (int c = 0; c < C; ++c) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		
		cout << poly(N) << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}
