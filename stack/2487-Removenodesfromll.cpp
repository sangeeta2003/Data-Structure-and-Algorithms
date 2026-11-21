/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
       
        stack<ListNode*> st;
        ListNode* temp = head;
       
        while(temp != nullptr){
while(!st.empty() && temp -> val > st.top()->val ){
    st.pop();
}
    st.push(temp);

temp = temp -> next;
        }
        ListNode* newHead = nullptr;
        while(!st.empty()){
ListNode* node = st.top();
        st.pop();
        node -> next = newHead;
        newHead = node;
     
        }
           return newHead;
        
    }
};