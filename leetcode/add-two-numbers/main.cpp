

// Submission begin

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ret = NULL;
    ListNode *last = NULL;
    ListNode *cur = NULL;
    int advance = 0;

    while (l1 != NULL || l2 != NULL) {
      int v1 = l1 == NULL ? 0 : l1->val;
      int v2 = l2 == NULL ? 0 : l2->val;
      int sum = v1 + v2 + advance;
      cur = new ListNode(sum % 10);
      advance = sum / 10;

      if (last == NULL) {
        ret = cur;
      } else {
        last->next = cur;
      }

      last = cur;
      l1 = l1 == NULL ? NULL : l1->next;
      l2 = l2 == NULL ? NULL : l2->next;
    }

    if (advance != 0) {
      cur = new ListNode(advance);
      // last won't be NULL when advance != 0;
      last->next = cur;
    }

    return ret;
  }
};

// Submission end
