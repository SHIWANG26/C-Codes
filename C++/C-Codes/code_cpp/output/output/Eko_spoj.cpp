#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossibleSolution(const vector<long long int>& trees, long long int m, int mid) {
    // Use long long int for woodCollected to accommodate large values
    long long int woodCollected = 0;
    for (long long int treeHeight : trees) {
        if (treeHeight > mid) {
            woodCollected += treeHeight - mid;
        }
    }
    return woodCollected >= m;
}

int maxSawBladeHeight(const vector<long long int>& trees, long long int m) {
    int start = 0, end = *max_element(trees.begin(), trees.end());
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossibleSolution(trees, m, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long int> trees;
    for (int i = 0; i < n; ++i) {
        long long int height;
        cin >> height;
        trees.push_back(height);
    }

    // Cast m to long long int for consistency
    cout << maxSawBladeHeight(trees, static_cast<long long int>(m)) << endl;

    return 0;
}
