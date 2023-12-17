#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int INF = 987654321;

int C, N, K, M, L;
// 선수 과목을 저장한 비트마스크
int prior[12];
// 각 학기에 열리는 과목을 저장한 비트마스크
int semesters[10];
int cache[10][1 << 12];

int bitCount(int n) {
    if (n == 0) return 0;
    return n % 2 + bitCount(n/2);
}

int calMinSemester(int semester, int taken) {
	if (bitCount(taken) >= K) return 0;
    if (semester == M) return INF;
    
    int& ret = cache[semester][taken];
    if (ret != -1) return ret;
    ret = INF;
    
    // 이번 학기에 들을 수 있는 과목 중, 아직 듣지 않은 과목
    int canTake = (semesters[semester] & ~taken);
    
    // 선행 과목을 듣지 않은 경우 제외
	for (int n = 0; n < N; ++n) {
        if ((canTake & (1 << n)) && ((prior[n] & taken) != prior[n])) {
            canTake &= ~(1 << n);
        }
	}

    for (int s = canTake; s; s = ((s-1) & canTake)) {
        if (bitCount(s) > L) continue;
        ret = min(ret, 1 + calMinSemester(semester+1, (taken | s)));
    }
    // 공집합의 경우
    ret = min(ret, calMinSemester(semester+1, taken));
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> C;
    for (int c = 0; c < C; ++c) {
        cin >> N >> K >> M >> L;
        memset(prior, 0, sizeof(prior));
        memset(semesters, 0, sizeof(semesters));
        
		for (int n = 0; n < N; ++n) {
			int R; cin >> R;
			for (int r = 0; r < R; ++r) {
				int nPrior; cin >> nPrior;
				prior[n] |= (1 << nPrior);
			}
		}

		for (int m = 0; m < M; ++m) {
			int Ci; cin >> Ci;
			for (int ci = 0; ci < Ci; ++ci) {
				int opened; cin >> opened;
				semesters[m] |= (1 <<opened);
			}
		}
        
        memset(cache, -1, sizeof(cache));
        
		int minSemester = calMinSemester(0, 0);
		if (minSemester >= INF) {
			cout << "IMPOSSIBLE" << "\n";
		} else { 
			cout << minSemester << "\n";
		}
    }
}
