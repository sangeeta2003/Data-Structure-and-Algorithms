class Solution {
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Put first node of every list into heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            ListNode* curr = pq.top();
            pq.pop();

            // Add smallest node
            tail->next = curr;
            tail = tail->next;

            // Add next node from same list
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        return dummy.next;
    }
};