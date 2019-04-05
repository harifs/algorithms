from math import factorial as f

class Solution:
    def generate(self, numRows):
        C = lambda n, r: f(n) // f(r) // f(n - r)
        return [[C(n, r) for r in range(n + 1)] for n in range(numRows)]

if __name__ == '__main__':
    sol = Solution()
    list = sol.generate(8)
    print list