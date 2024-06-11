#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoPtrMethod(vector<int> &arr, int k, int x)
    {
        int l = 0, h = arr.size() - 1;
        while (h - l >= k) 
        {
            if (x - arr[l] > arr[h] - x)
                l++;
            else
                h--;
        }

        vector<int> ans;
        for (int i = l; i <= h; i++)  // Changed from l < h to l <= h
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        return twoPtrMethod(arr, k, x);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    Solution sol;
    vector<int> closestElements = sol.findClosestElements(arr, k, x);
    for (int num : closestElements)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
