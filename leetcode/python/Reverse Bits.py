class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        s = bin(n).lstrip('0b').zfill(32)
        s = s[::-1]
        return int(s, 2)
