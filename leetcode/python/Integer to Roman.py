class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        roman_list = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        number_list = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    
        result = ''
        while num > 0:
            for i in range(0, len(roman_list)):
                if num - number_list[i] >= 0:
                    num -= number_list[i]
                    result += roman_list[i]
                    break
            
        return result

    
