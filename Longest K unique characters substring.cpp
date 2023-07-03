class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        int arr[26] = {0};
        int start = 0;
        int end = 0;
        int unique=0;
        int maxi = -1;
        int n= s.size();
        
        while(end<n)
        {
            arr[s[end]-'a']++;
            if(arr[s[end]-'a']==1) unique++;
            
            while(start < end && unique>k )
            {
                arr[s[start]-'a']--;
                if(arr[s[start]-'a']==0) unique--;
                start++;
            }
            if(unique==k) maxi = max(maxi,end-start+1);
            end++;
        }
        return maxi;
    }
};
