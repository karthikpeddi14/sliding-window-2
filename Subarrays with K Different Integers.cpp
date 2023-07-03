class Solution {
public:
    int atmostkdistinct(vector<int>& nums , int k)
    {
        if(k==0) return 0;
        int start=0 , end = 0 , count=0;
        int arr[20001]={0};
        int unique=0;
        int n=nums.size();

        while(end<n)
        {
            arr[nums[end]]++;
            if(arr[nums[end]]==1) unique++;
            
            while(start<end && unique>k)
            {
                arr[nums[start]]--;
                if(arr[nums[start]]==0) unique--;
                start++;
            }

            count += end-start+1;
            end++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return atmostkdistinct(nums,k) - atmostkdistinct(nums,k-1);
    }
};
