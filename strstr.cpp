Question:
Implement strstr(). Returns the index of the first occurrence of needle in haystack, or –1
if needle is not part of haystack.

There are known efficient algorithms such as Rabin-Karp algorithm, KMP algorithm, or
the Boyer-Moore algorithm.

//Brute force
public int strStr(String haystack, String needle){
    for(int i=0; ;i++){
        for(int j=0; ;j++){
            if(j==needle.length())return i;
            if(i+j==haystack.length())return -1;
            if(needle.charAt(j)!==hayStack.charAt(i+j))break;
        }
    }
}

//Using KMP
class Solution{
    public:
    //calculating lps function
    vector<int> calc(string pat,int m){
        vector<int> lps(m,0);
        int i=0,j=0;
        while(i<m){
            if(pat[i]==pat[j]){
                j++;
                lps[i++]=j;
            }
            else{
                if(j)j=lps[j-1];
                else lps[i++]=0;
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle){
        int n=haystack.length(),m=needle.length();
        if(m==0)return 0;
        vector<int> lps=calc(needle,m);
        int i=0,j=0;
        while(i<n&&j<m){
            if(haystack[i]== needle[j]){i++; j++;}
            if(j==m)return i-j;
            else if(i<n&&j<m&& haystack[i]!=needle[j]){
                if(j) j=lps[j-1];
                else i++;
            }
        }
        return -1;
    }
}

//Rolling Hash or Rabin Karp
class Solution{
    public:
    int rabinKarp(string &text, string &pattern){
        long BASE=26,MOD=1e9+7;
        long power=1;

        for(int i=1;i<pattern.size();i++){
            pattern_hash=(pattern_hash*BASE+(pattern[i]-'a'+1))%MOD;
            text_hash=(text_hash*BASE+(text[i]-'a'+1))%MOD;
        }
        if(pattern_hash==text_hash) return 0;

        int start=0;
        for(int i=pattern.size();i<text.size();i++){
            int ch=text[start++]-'a'+1;
            text_hash=text_hash-(ch*power);

            text_hash=(text_hash*BASE+(text[i]-'a'+1))%MOD;

            if(text_hash<0){
                text_hash+=MOD;
            }
            if(text_hash==pattern_hash) return start;
        }
        return -1;

    }

    int strStr(string haystack, string needle){
        if(needle.size()==0)return 0;
        return rabinKarp(haystack, needle);
    }

}

//one line java
class Solution{
    public int strStr(String x,String y){
        return x.indexof(y);
    }
}