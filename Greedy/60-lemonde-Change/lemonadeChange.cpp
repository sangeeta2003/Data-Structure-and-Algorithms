
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int money : bills) {
            if (money == 5) {
                five++;
            }
            else if (money == 10) {
                if (five == 0) return false;

                five--;
                ten++;
            }
            else if (money == 20) {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};