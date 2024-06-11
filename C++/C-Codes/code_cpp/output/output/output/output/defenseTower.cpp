#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> rowC;
    vector<int> colC;
    rowC.push_back(0);
    colC.push_back(0);
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        rowC.push_back(a);
        colC.push_back(b);
    }
    rowC.push_back(x + 1);
    colC.push_back(y + 1);
    for (auto i : rowC)
    {
        cout << i << " ";
    }
    cout << endl;
    int maxLen = INT_MIN;
    for (int i = 1; i < rowC.size() - 1; i++)
    {
        int a = rowC[i - 1];
        int b = rowC[i];
        maxLen = max(maxLen, b - a - 1);
    }
    int maxWid = INT_MIN;
    for (int i = 1; i < colC.size() - 1; i++)
    {
        int a = colC[i - 1];
        int b = colC[i];
        maxWid = max(maxWid, b - a - 1);
    }
    cout << "Maximum penalty area is: " << maxLen * maxWid << endl;

    return 0;
}
