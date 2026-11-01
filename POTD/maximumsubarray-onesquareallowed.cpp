class Solution {
public:
    int maximumSubarray(vector<int>& arr) {

        int noSquare = arr[0];
        int oneSquare = arr[0] * arr[0];

        int ans = max(noSquare, oneSquare);

        for(int i = 1; i < arr.size(); i++) {

            int x = arr[i];

            int newNoSquare = max(x, noSquare + x);

            int newOneSquare = max({
                x * x,
                oneSquare + x,
                noSquare + x * x
            });

            noSquare = newNoSquare;
            oneSquare = newOneSquare;

            ans = max(ans, oneSquare);
            ans = max(ans, noSquare);
        }

        return ans;
    }
};