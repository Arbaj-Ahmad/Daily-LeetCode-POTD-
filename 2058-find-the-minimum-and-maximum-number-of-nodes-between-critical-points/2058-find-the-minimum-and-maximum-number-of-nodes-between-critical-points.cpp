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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if (!head || !head->next || !head->next->next)
            return {-1, -1};
        ListNode* prev = head;
        ListNode* curr = head->next;


        int first = -1, previous = -1;
        int curr_index = 1;
        int min_dist = INT_MAX;


        while (curr->next) {
            bool is_max =
                (curr->val > prev->val && curr->val > curr->next->val);
            bool is_min =
                (curr->val < prev->val && curr->val <curr->next->val);

            if (is_max || is_min) {
                if (first == -1) {
                    first = curr_index;
                }
                
                
                 else {
                    min_dist = min(min_dist, curr_index - previous);
                }
                previous = curr_index;
            }

            prev = curr;
            curr = curr->next;
            curr_index++;
        }
        if (min_dist == INT_MAX)
            return {-1, -1};
        return {min_dist, previous - first};
    }
};