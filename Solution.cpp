#include <iostream>
using namespace std;

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

// Function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Creating first number: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Creating second number: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}

