#https://leetcode.com/problems/string-compression/

class Solution:
    def compress(self, chars: List[str]) -> int:
        ansidx = 0
        
        i = 0
        j = 1
        n = len(chars)
        while i<n:
            count = 0
            ch = chars[i]
            while i<n and j<n and chars[i]==chars[j]:
                count += 1
                i += 1
                j += 1
            
            chars[ansidx]=ch
            if count>0:
                strc = str(count+1)
                for c in strc:
                    
                    ansidx += 1
                    chars[ansidx] = c

            i += 1
            j += 1
            ansidx += 1
    
        return ansidx 
