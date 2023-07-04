class Solution {
public:
    string minWindow(string s, string t) 
    {
        int arr[58]={0};
        int start = 0, end = 0;
        int n= s.size();
        int m= t.size();

        pair<int,int> ans = {-1,-1};

        for(int i=0 ; i<m ; i++)
        {
            arr[t[i]-'A']++;
        }

        while(end<n)
        {
            if(arr[s[end]-'A']!=0) 
            {
                if(arr[s[end]-'A'] > 0) m--;
                if(arr[s[end]-'A']==1) arr[s[end]-'A'] = -1;
                else arr[s[end]-'A']--;
                
            }

            while(start<=end && m<=0)
            {
                if(m==0 && (end-start<ans.second-ans.first || ans.second==-1))
                {
                    ans.second = end;
                    ans.first = start;
                }
                if(arr[s[start]-'A']!=0) 
                {
                    if(arr[s[start]-'A']==-1) arr[s[start]-'A'] = 1;
                    else arr[s[start]-'A']++;
                    if(arr[s[start]-'A']>0) m++;
                }
                start++;
            }
            end++;
        }
        if(ans.first==-1) return "";
        return s.substr(ans.first , ans.second-ans.first+1);
    }
};
