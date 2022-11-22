Question:
Similar to Question [1. Two Sum], except that the input array is already sorted in
ascending order.

//Two Pointers

class Solution{
    public:
    vector<int> twoSum(vector<int>& nums,int target){
        vector<int> ans;
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]<target)i++;
            else if(nums[i]+nums[j]>target)j--;
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;++i;
            }
        }
        return ans;
    }
}


//In Java
class Solution{
    public int[] twoSum(int[] nums,int target){
        int i=0,j=nums.length-1;
        while(i<j){
            if(nums[i]+nums[j]<target)++i;
            else if(nums[i]+nums[j]>target)--j;
            else{
                return new int[]{i+1,j+1};
            }
        }
        return new int[]{};
    }
}

//In JavaScript
var twoSum=function(nums,target){
    let i=0,j=nums.length-1;
    while(i<j){
        if(nums[i]+nums[j]<target)++i;
            else if(nums[i]+nums[j]>target)--j;
            else{
                return [i+1,j+1];
            }
    }
}