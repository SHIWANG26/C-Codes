#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        
        for (int num : nums) {
            int index = abs(num) - 1; // Adjust index to 0-based
            
            if (nums[index] < 0) {
                duplicates.push_back(abs(num));
            } else {
                nums[index] *= -1; // Mark the element at index as negative
            }
        }
        
        return duplicates;
    }
};

int main()
{
    vector<int> nums = {1,2,3,3,4,5,66,7,8,6,7,8,4};
    Solution sol;
    vector<int> duplicates = sol.findDuplicates(nums);
    cout<<"Duplicates of the array are:\n";
    for (int num: duplicates)
    {
        cout<<num;
    }
    cout<<endl;
    
return 0;
}
