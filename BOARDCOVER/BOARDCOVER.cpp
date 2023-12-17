#include <iostream>

using namespace std;

int C, H, W;
bool board[20][20];

// four cases: (x, y) is a middle block
// eight cases: (x, y) is a end block
int dx[12] = {0, 1, 0, -1, 0, 0, 1, 1, 0, 0, -1, -1};
int dy[12] = {1, 0, -1, 0, 1, 1, 0, 0, -1, -1, 0, 0};
int ddx[12] = {1, 0, -1, 0, -1, 1, 1, 1, 1, -1, -1, -1};
int ddy[12] = {0, -1, 0, 1, 1, 1, 1, -1, -1, -1, 1, -1};

int cnt;

void countCases();
bool isFilled();

int main () {
  freopen("input.txt", "r", stdin);

  cin >> C;
  for (int i = 0; i < C; ++i) {
    cin >> H >> W;

    // Initialize
    for (int y = 0; y < 20; ++y) {
      for (int x = 0; x < 20; ++x) {
        board[x][y] = false;
      }
    }
    cnt = 0;

    for (int y = 0; y < H; ++y) {
      for (int x = 0; x < W; ++x) {
        char c; cin >> c;
        if (c == '#') {
          board[x][y] = true;
        }
      }
    }

    countCases();
    cout << cnt << endl;
  }
}

void countCases() {
  if (isFilled()) {
    ++cnt;
    return;
  }

  // Find first empty block
  int x, y;
  bool isFound = false;
  for (int j = 0; j < H; ++j) {
    for (int i = 0; i < W; ++i) {
      if (!isFound && !board[i][j]) {
        x = i; y = j;
        isFound = true;
      }
    }
  }

  for (int i = 0; i < 12; ++i) {
    int nx1 = x + dx[i], ny1 = y + dy[i];
    int nx2 = x + ddx[i], ny2 = y + ddy[i];

    if (nx1 < 0 || nx1 >= W || ny1 < 0 || ny1 >= H || board[nx1][ny1]) continue;
    if (nx2 < 0 || nx2 >= W || ny2 < 0 || ny2 >= H || board[nx2][ny2]) continue;

    board[x][y] = board[nx1][ny1] = board[nx2][ny2] = true;
    countCases();
    board[x][y] = board[nx1][ny1] = board[nx2][ny2] = false;
  }
}

bool isFilled() {
  for (int j = 0; j < H; ++j) {
    for (int i = 0; i < W; ++i) {
      if (!board[i][j]) return false;
    }
  }
  return true;
}