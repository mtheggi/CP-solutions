class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        listnew = s.strip().split()
        listnew.reverse() 
        return " ".join(listnew)  
        
