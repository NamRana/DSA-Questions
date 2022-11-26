// Question:
// Given a string S, find the longest palindromic substring in S. You may assume that the
// maximum length of S is 1000, and there exists one unique longest palindromic substring

class Solution{
    public String longestPalindrome(String s){
        int start = 0,end=0;
        for(int i=0;i<s.length();i++){
            int l1=expandAround(s,i,i);
            int l2=expandAround(s,i,i+1);
            int l=Math.max(l1,l2);
            if(len>end-start){
                start=i-(l-1)/2;

            }
            
        }
        return s.substring(start,end+1);
    }

    public int expandAround(String s,int left,int right){
        int L=left,R=right;
        while(L>=0 && R<s.length() && s.charAt(L)==s.charAt(R)){
            L--;R++;
        }
        return R-L-1;
    }

}


//Brute force
class Solution{
    public:
    string rev(string str){
        int n=str.length();
        for(int i=0;i<n/2;i++){
            swap(str[i],str[n-i-1]);
        }
        return str;
    }

    string palind(string s){
        string res,str2;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                str2=s.substr(i,j);
                if(str2==rev(str)&&str2.length()>res.length())res=str2;
        }
    }
    return res;
}
}