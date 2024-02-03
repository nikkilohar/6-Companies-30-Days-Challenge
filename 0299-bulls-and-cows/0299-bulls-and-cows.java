class Solution {
    public String getHint(String secret, String guess) {
        int[] c1 = new int[10];
        int[] c2 = new int[10];
        
        int bulls = 0, cows = 0;
        int i, N = secret.length();
        char ch1, ch2;
        for(i = 0; i < N; i++){
            ch1 = secret.charAt(i);
            ch2 = guess.charAt(i);
            
            // matching digit at same position = bull
            if(ch1 == ch2)
                ++bulls;
            
            // increment count of digits seen so far in each number
            c1[ch1 - '0']++;
            c2[ch2 - '0']++;
        }
        
        for(i = 0; i < 10; i++){
            cows += Math.min(c1[i], c2[i]);
        }
        
        cows -= bulls;
        
        return bulls + "A" + cows + "B";
    }
}