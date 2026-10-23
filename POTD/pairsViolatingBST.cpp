/* BST Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/



class Solution {
public:
    void inorder(Node* root, vector<int>& arr) {
        if (root == nullptr) return;

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    long long mergeSort(vector<int>& arr, vector<int>& temp,
                        int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;

        long long count = 0;
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);

        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                count += mid - i + 1;
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int p = left; p <= right; p++) {
            arr[p] = temp[p];
        }

        return count;
    }

    int pairsViolatingBST(Node* root) {
        vector<int> arr;
        inorder(root, arr);

        if (arr.empty()) return 0;

        vector<int> temp(arr.size());

        return (int)mergeSort(arr, temp, 0, arr.size() - 1);
    }
};
