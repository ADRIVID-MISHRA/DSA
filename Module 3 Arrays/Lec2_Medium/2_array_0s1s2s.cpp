#include<iostream>
#include<vector>

using namespace std;;

vector<int> sort_better(vector<int> nums){
    // int count0=0,count1=0,count2=0;
    // for(int i=0;i<nums.size();i++){
    //     if(nums[i]==0){
    //         count0++;
    //     }
    //     if(nums[i]==1){
    //         count1++;
    //     }
    //     if(nums[i]==2){
    //         count2++;
    //     }
    // }
    // int count=0;
    // while(count0!=0){
    //     nums[count]=0;
    //     count++;
    //     count0--;
    // }
    // while(count1!=0){
    //     nums[count]=1;
    //     count++;
    //     count1--;
    // }
    // while(count2!=0){
    //     nums[count]=2;
    //     count++;
    //     count2--;
    // }
    // return nums;


    //Below is the same code with cleaner way to write. GPT gave(lern)

    int count0 = 0, count1 = 0, count2 = 0;

    // Count the occurrences
    for (int num : nums) {
        if (num == 0) count0++;
        else if (num == 1) count1++;
        else count2++;
    }

    // Rewrite the array in place
    int index = 0;
    while (count0--) nums[index++] = 0;
    while (count1--) nums[index++] = 1;
    while (count2--) nums[index++] = 2;
    return nums;
}

void sort_optimal(vector<int> &nums){
    int n=nums.size();
    int low=0,high=n-1,mid=0;

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
         }
        else {
            swap(nums[high],nums[mid]);
            high--;
        }
    }
}

int main(){
    vector<int> nums={1,1,1,0,1,2,2,2,0,2,1,2,0,2,1,1,0,2,1,0};

    vector<int> result=sort_better(nums);
    for(auto i:result){
        cout<<i<<" ";
    }

    cout<<endl;

    sort_optimal(nums);
    for(auto i:nums){
        cout<<i<<" ";
    }
    return 0;
}