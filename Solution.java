class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy head node
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {

            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            ptr->next = new ListNode(sum);
            ptr = ptr->next;
        }

        // If carry remains
        if (carry == 1) {
            ptr->next = new ListNode(1);
        }

        return result->next; // skip dummy node
    }
};
class Solution {
public static void main(String[]args)
{
}
}
