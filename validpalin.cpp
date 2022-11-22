Question:
Given a string, determine if it is a palindrome, considering only alphanumeric characters
and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.


//Two Pointers
// In jvascript
var isPalindrome =function(s){
    let newStr=s.toLowerCase().replace(/[^0-9a-z]/g,"");
    let i=0,j=newStr.length-1;
    while(i<j){
        if(newStr[i]!==newStr[j])return false;
        i++;j--;
    }
    return true;
}



//In c++
class Solution{
    public:
    bool isPalindrome(String s){
        string ans="";
        transform(s.begin(),s.end(),s.begin(),::tolower);
        for(char i:s){
            if((i>'a'&&i<='z')||(i>='0'&&i<='9'))ans+=i;
        }

        int j=ans.length()-1;
        for(int i=0;i<ans.length()/2;i++){
            if(ans[i]!=ans[j--])
              return false;
        }
        return true;
    }
}