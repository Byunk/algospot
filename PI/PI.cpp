#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <string>
	
using namespace std;

/* 모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1 */
/* 숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2 */
/* 두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4 */
/* 숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5 */
/* 그 외의 경우 난이도: 10 */

int C, N, L;
int num[10000];
int cache[10000];

int level(int start, int end) {
	vector<int> diff;

	int p = start;
	while (p < end-1) {
		diff.push_back(num[p+1] - num[p]);
		++p;
	}

	bool isLevel1 = true;
	bool isLevel2 = true;
	bool isLevel4 = true;
	bool isLevel5 = true;


	int prev;
	int pprev;
	for (int i = 0; i < diff.size(); ++i) {
		int d = diff[i];
		if (d != 0) isLevel1 = false;
		if (i > 0 && (prev != d || (d != 1 && d != -1))) isLevel2 = false;
		if ((i > 0 && prev + d != 0) || (i > 1 && pprev != d)) isLevel4 = false;
		if (i > 0 && prev != d) isLevel5 = false;
		pprev = prev;
		prev = d;
	}

	if (isLevel1) return 1;
	if (isLevel2) return 2;
	if (isLevel4) return 4;
	if (isLevel5) return 5;
	return 10;
}

int minLevel(int start) {
	if (start == L) return 0;
	if (L - start < 3) return INT_MAX;

	int& ret = cache[start];
	if (ret > 0) return ret;

	ret = INT_MAX;
	for (int i = 0; i < 3; ++i) {
		int size = i + 3;
		if (start + size > L) continue;

		int currentLevel = level(start, start + size) + minLevel(start + size);
		if (currentLevel < 0) continue;

		ret = min(ret, currentLevel);
	}
	return ret;
}

void solve() {
	cin >> C;
	for (int i = 0; i < C; ++i) {
		memset(cache, 0, sizeof(cache));

		string s;
		cin >> s;
		L = s.size();

		for (int j = L-1; j >=0; --j) {
			num[j] = int(s[j]);
		}

		cout << minLevel(0) << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}
