
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int i = 0;
        int j = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;

        while (i <= j) {
            if (power >= tokens[i]) {
                // Play the smallest token face-up
                power -= tokens[i];
                score++;
                i++;

                maxScore = max(maxScore, score);
            }
            else if (score > 0) {
                // Play the largest token face-down
                power += tokens[j];
                score--;
                j--;
            }
            else {
                break;
            }
        }

        return maxScore;
    }
};