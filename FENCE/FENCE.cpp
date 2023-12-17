#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& heights, int start, int end);

int C;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> C;
    for (int i = 0; i < C; ++i) {
        int N; cin >> N;
        vector<int> heights;

        for (int j = 0; j < N; ++j) {
            int n; cin >> n;
            heights.push_back(n);
        }
        int ret = solve(heights, 0, N-1);
        cout << ret << endl;
    }
}

int solve(vector<int>& heights, int start, int end) {
    // base case
    if (start == end) {
        return heights[start];
    }

    int mid = (start + end)/2;
    int max_size = max(solve(heights, start, mid), solve(heights, mid+1, end));

    // case: max size block is included on both sides
    int l = mid; int r = mid + 1;
    int h = min(heights[l], heights[r]);
    int size = (r-l+1) * h;

    while(l > start || r < end) {
        if (r < end && (l == start || heights[l-1] <= heights[r+1])) {
            ++r;
            h = min(heights[r], h);
        } else {
            --l;
            h = min(heights[l], h);
        }
        size = max(size, (r-l+1) * h);
    }
    return max(max_size, size);
}