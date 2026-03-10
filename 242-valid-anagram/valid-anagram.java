class Solution {
    public boolean isAnagram(String s, String t) {
        int hash[]=new int[26];
        int rash[]=new int[26];
        for(int i=0;i<s.length();i++){
            hash[s.charAt(i)-'a']++;
        }
        for(int i=0;i<t.length();i++){
            rash[t.charAt(i)-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash[i]!=rash[i]){
                return false;
            }
            
        }
        return true;
    }
}