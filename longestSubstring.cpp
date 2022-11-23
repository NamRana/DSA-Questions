Given a string s, find the length of the longest substring without repeating characters.

 
class Solution{
    public:
    int subString(string s){
        int length=0,maxlength=0,j=0;
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            length++;
            while (mp[s[i]]>1)
            {
                /* code */mp[s[j++]]--;
                length--;
            }
            maxlength==max(maxlength,length);
            
        }
        return maxlength;
    }
}