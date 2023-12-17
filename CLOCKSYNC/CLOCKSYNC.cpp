#include <iostream>
#include <vector>
#include <algorithm>

const int N_CLOCK = 16;

using namespace std;

int C;
int clocks[N_CLOCK];
const char linked[10][N_CLOCK+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

int solve(vector<int>& clocks, int swtch);
void push(vector<int>& clocks, int swtch);
bool areAligned(vector<int> &clocks);

int main() {
    freopen("input.txt", "r", stdin);

    cin >> C;
    for (int i = 0; i < C; ++i) {
        vector<int> clocks;
        for (int j = 0; j < N_CLOCK; ++j) {
            int clock; cin >> clock;
            clocks.push_back(clock);
        }

        int ret = solve(clocks, 0);
        if (ret == 1000) {
            cout << -1 << endl;
        } else {
            cout << ret << endl;
        }
    }
}

int solve(vector<int>& clocks, int swtch) {
    if (swtch == 10) return areAligned(clocks) ? 0 : 1000;

    int ret = 1000;
    for (int cnt = 0; cnt < 4; ++cnt) {
        ret = min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}

void push(vector<int>& clocks, int swtch) {
    for (int i = 0; i < N_CLOCK; ++i) {
        if (linked[swtch][i] == 'x') {
            if (clocks[i] == 12) {
                clocks[i] = 3;
            } else {
                clocks[i] += 3;
            }
        }
    }
}

bool areAligned(vector<int> &clocks) {
    for (int i = 0; i < N_CLOCK; ++i) {
        if (clocks[i] != 12) {
            return false;
        }
    }
    return true;
}