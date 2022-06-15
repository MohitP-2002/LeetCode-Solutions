class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, (a, b)->a.length() - b.length());
        Map<String, Integer> dp = new HashMap<>();
        int res=0;
        for(String word:words){
            int ans=0;
            for(int i=0;i<word.length();i++){
                String prev = word.substring(0,i) + word.substring(i+1);
                ans=Math.max(ans, dp.getOrDefault(prev, 0)+1);
            }
            dp.put(word,ans);
            res=Math.max(res,ans);
        }
        return res;
    }
}