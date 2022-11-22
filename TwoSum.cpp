Question:
Given an array of integers, find two numbers such that they add up to a specific target
number.
The function twoSum should return indices of the two numbers such that they add up to
the target, where index1 must be less than index2. Please note that your returned answers
(both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution


//Greedy O(n2)
class Solution{
public:
vector<int> twoSum(vector<int>& nums,int target){

    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && nums[i]+nums[j]==target){return {i,j};}
        }

    }
    return {};

}
};

//Two Pointers o(nlogn)
class Solution{
    public:
    vector<int> twoSum(vector<int>& nums,int target){
        int n=nums.size();

        //nested lists
        vector<pair<int,int> >a {};
        for(int i=0;i<n;i++){
            a.push_back(make_pair(nums[i],i));
        }

        sort(a.begin(),a.end());

        int i=0,j=n-1;
        while(i<j){
            int sum=a[i].first+a[j].first;
            if(sum==target){
                return {a[i].second,a[j].second};
            }else if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};


//Unordered Map o(n)
class Solution{
    public:
    vector<int> twoSum(vector<int>& nums,int target){
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(target-nums[i])) return {i,m[target-nums[i]]}

            m[nums[i]]=i;
        }
        return {};
    }

}


//In java
class Solution{
    public int[] twoSum(int[] nums,int target){
        Map<Integer,Integer> map=new HashMap<>();

        for(int i=0;i<nums.length;i++){
            if(map.containsKey(target-nums[i])){
                return new int [] {map.get(target-nums[i]),i};
            }
            map.put(nums[i],i);
        }
        return new int[] {};
    }
}
