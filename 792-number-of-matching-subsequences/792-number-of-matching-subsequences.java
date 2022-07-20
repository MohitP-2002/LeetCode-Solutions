class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        Map<Character, Queue<String>> map = new HashMap<>();
        for(int i=0;i<s.length();i++){
            map.putIfAbsent(s.charAt(i), new LinkedList<>());
        }
        for(String word: words){
            char c = word.charAt(0);
            if(map.containsKey(c)){
                map.get(c).offer(word);
            }
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            Queue<String> q=map.get(c);
            int size=q.size();
            for(int k=0;k<size;k++){
                String p = q.poll();
                if(p.substring(1).length()==0) ans++;
                else {
                    if(map.containsKey(p.charAt(1))){
                        map.get(p.charAt(1)).add(p.substring(1));
                    }
                }
            }
        }
        return ans;
    }
}