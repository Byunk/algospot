#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int C;
int cache[100][100];

string solve(vector<vector<int> >& board, int x, int y);

int main() {
    freopen("input.txt", "r", stdin);
    cin >> C;
    for (int i = 0; i < C; ++i) {
        memset(cache, -1, sizeof(cache));

        int N; cin >> N;
        vector<vector<int> > board;
        for (int j = 0; j < N; ++j) {
            vector<int> row;
            for (int k = 0; k < N; ++k) {
                int n; cin >> n;
                row.push_back(n);
            }
            board.push_back(row);
        }

        string ret = solve(board, 0, 0);
        cout << ret << endl;
    }
}

string solve(vector<vector<int> >& board, int x, int y) {
    if (x == board[0].size()-1 && y == board.size()-1) {
        return "YES";
    }

    if (x > board[0].size()-1 || y > board.size()-1) {
        return "NO";
    }

    int& ret = cache[x][y];
    if (ret == 1) {
        return "YES";
    } else if (ret == 0) {
        return "NO";
    }

    if (solve(board, x + board[x][y], y) == "YES" || solve(board, x, y + board[x][y]) == "YES") {
        ret = 1;
        return "YES";
    } else {
        ret = 0;
        return "NO";
    }
}