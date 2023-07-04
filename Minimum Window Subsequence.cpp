class Solution {
  public:
    string minWindow(string str1, string str2) 
    {
        int n = str1.size();
        int m = str2.size();
        int start=0, end=0;
        pair<int,int> ans = {-1,-1};
        int pointer = 0;
        
        while(end<n)
        {
            if(str1[end] == str2[pointer])
            {
                pointer++;
            }
            
            if(pointer == m)
            {
                start=end;
                pointer = m-1;
                while(pointer>=0)
                {
                    if(str1[start]==str2[pointer]) pointer--;
                    start--;
                }
                
                if(ans.second==-1 || end-start-1<ans.second-ans.first) 
                {
                    ans.second = end;
                    ans.first = start+1;
                }
                end = start+1;
            }
            else end++;
        }
        if(ans.second == -1) return  "";
        return str1.substr(ans.first,ans.second-ans.first+1);
    }
};
