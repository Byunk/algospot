#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
	
using namespace std;

int C, N;
string W, S;

// -1: no cache, 0: unmatched, 1: matched
int cache[101][101];

bool match(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;

	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) {
		return ret = match(w+1, s+1);
	}

	if (w == W.size()) {
		return ret = (s == S.size());
	}
	
	if (W[w] == '*') {
		if (match(w+1, s) || (s < S.size() && match(w, s+1))) {
			return ret = 1;
		}
	}
	return ret = 0;
}

void solve() {
	cin >> C;

	for (int i = 0; i < C; ++i) {
		vector<string> ret;
		cin >> W >> N;
		for (int j = 0; j < N; ++j) {
			cin >> S;
			
			memset(cache, -1, sizeof(cache));

			if (match(0, 0) == 1) {
				ret.push_back(S);
			}
		}
		sort(ret.begin(), ret.end());
		for (auto s : ret) {
			cout << s << endl; 
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}

