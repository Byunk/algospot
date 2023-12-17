#include <algorithm>
#include <iostream>
#include <vector>
	
using namespace std;

int C, N, D, P, T;
int A[51][51];
int Q[51];
int deg[51];
double cache[51][101];

void preCalc () {
	for (int r = 0; r < N; ++r) {
		int sum = 0;
		for (int c = 0; c < N; ++c) {
			if (A[r][c] == 1) sum += 1;
		}
		deg[r] = sum;
	}
}

double search (int here, int days) {
	// output: a conditional probabililty that doctor Dunibal stays at 'there' in day 'days'
	if (days == 0) return (here == P ? 1.0 : 0.0);

	double& ret = cache[here][days];
	if (ret > -0.5) return ret;

	ret = 0.0;
	for (int there = 0; there < N; ++there) {
		if (A[here][there] == 1) {
			ret += search(there, days-1) / deg[there];
		}
	}
	return ret;
}

void solve() {
	cin >> C;
	for (int c = 0; c < C; ++c) {
		cin >> N >> D >> P;
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				cin >> A[r][c];
			}
		}
		cin >> T;
		for (int t = 0; t < T; ++t) {
			cin >> Q[t];
		}

		// initialize cache
		for (int r = 0; r < 51; ++r) {
			for (int c = 0; c < 101; ++c) {
				cache[r][c] = -1.0;
			}
		}
		preCalc();

		cout << fixed;
		cout.precision(8);
		for (int t = 0; t < T; ++t) {
			cout << search(Q[t], D) << " ";
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
}
