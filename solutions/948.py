from typing import List


class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        start, end = 0, len(tokens) - 1
        score, highscore = 0, 0

        while start <= end:
            if power >= tokens[start]:
                power -= tokens[start]
                start += 1
                score += 1
            elif score > 0:
                power += tokens[end]
                end -= 1
                score -= 1
            else:
                break

            if score > highscore:
                highscore = score

        return highscore


if __name__ == "__main__":
    print(Solution().bagOfTokensScore([71,55,82], 54))
