#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void next_permutation_better(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

void next_permutation_optimal(vector<int> &nums)
{
    int n = nums.size();
    int break_index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            break_index = i;
            break;
        }
    }
    if (break_index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = nums.size() - 1; i > break_index; i--)
    {
        if (nums[i] > nums[break_index])
        { // least greater element
            swap(nums[i], nums[break_index]);
            break;
        }
    }
    reverse(nums.begin() + break_index + 1, nums.end());
}

int main()
{
    vector<int> arr1 = {3, 1, 2};
    next_permutation_better(arr1);
    for (auto it : arr1){
        cout << it << " ";
    }
    cout << endl;
    vector<int> arr2 = {3, 1, 2};
    next_permutation_optimal(arr2);
    for (auto it : arr2){
        cout << it << " ";
    }
    return 0;
}