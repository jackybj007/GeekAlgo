/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* pl1 = l1;
    struct ListNode* pl2 = l2;
    struct ListNode virnode;
    struct ListNode* pindex = &virnode;

    if (l1 == NULL || l2 == NULL) {
        return (l1 != NULL ? l1 :l2);
    }

    while (pl1 && pl2) {
        if (pl1->val <= pl2->val) {
            pindex->next = pl1;
            pl1 = pl1->next;
        }
        else {
            pindex->next = pl2;
            pl2 = pl2->next;
        }
        pindex = pindex->next;
    }

    if (pl1 != NULL || pl2 != NULL) {
         pindex->next = pl1 ? pl1 : pl2;
    }

    return virnode.next;
}
