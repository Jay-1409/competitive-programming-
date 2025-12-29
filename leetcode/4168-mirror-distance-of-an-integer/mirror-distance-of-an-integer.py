class Solution:
    def mirrorDistance(self, n: int) -> int:
        m = list(map(int, str(n)))
        i, j = 0, len(m) - 1
        while i<j:
            m[i], m[j] = m[j], m[i]
            i += 1
            j -= 1
        m = int("".join(map(str, m)))
        d = m - n
        return abs(d)
        