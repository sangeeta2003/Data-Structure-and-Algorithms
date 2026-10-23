
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n && j < n) {
            // Skip blank spaces
            while (i < n && start[i] == '_') {
                i++;
            }

            while (j < n && target[j] == '_') {
                j++;
            }

            // Both strings must have matching pieces
            if (i == n || j == n) {
                return i == n && j == n;
            }

            // Pieces must be in the same order
            if (start[i] != target[j]) {
                return false;
            }

            // L cannot move to the right
            if (start[i] == 'L' && i < j) {
                return false;
            }

            // R cannot move to the left
            if (start[i] == 'R' && i > j) {
                return false;
            }

            i++;
            j++;
        }

        // Check that no pieces remain
        while (i < n && start[i] == '_') {
            i++;
        }

        while (j < n && target[j] == '_') {
            j++;
        }

        return i == n && j == n;
    }
};
