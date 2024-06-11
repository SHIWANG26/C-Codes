#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
        void sort_color(vector<int>& nums){
            int low = 0, high = nums.size() - 1, curr = 0;
            while (curr<=high)
            {
                if (nums[curr]==0)
                {
                    swap(nums[curr], nums[low]);
                    low++;
                    curr++;
                }
                else if (nums[curr]==2)
                {
                    swap(nums[curr], nums[high]);
                    high--;
                }
                else
                {
                    curr++;
                }    
            }
        }
};
int main()
 {
    vector <int> nums{0,1,2,2,1,0};
    Solution Sort;
    Sort.sort_color(nums);
    for (int num : nums)
    {
        cout << num << " ";
    }
    
    return 0;
 }
