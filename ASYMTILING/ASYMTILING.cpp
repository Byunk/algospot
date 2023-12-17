#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
	
using namespace std;

const int MOD = 1000000007;
int C, N;
int cache[101];

int count(int width) {
	// count all cases for given width without considering symmetry
	if (width <= 1) return 1;

	int& ret = cache[width];
	if (ret != -1) return ret;

	return ret = (count(width-1) + count(width-2)) % MOD;
}

int countSym(int width) {
	if (width % 2 == 0) {
		return (count (width / 2) + count (width / 2 - 1)) % MOD;
	} else {
		return count (width / 2);
	}
}

void solve() {
	cin >> C;
	for (int c = 0; c < C; ++c) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		
		cout << (count(N) - countSym(N) + MOD) % MOD << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}
