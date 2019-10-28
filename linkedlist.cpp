#include <iostream>
    using namespace std;
    struct ListNode {
      double value;
      ListNode *next;
    };
    int main()  {
    ListNode *head;
    head = new ListNode; // Allocate new node
    head->value = 16.4; // Store the value
    head->next = NULL; // Signify end of list
    ListNode *secondPtr = new ListNode;
    secondPtr->value = 19.3;
    secondPtr->next = NULL; // Second node is end of list
    head->next = secondPtr; // First node points to second
    // Print the list
    cout << "First item is " << head->value << endl;
    cout << "Second item is " << head->next->value << endl;
    return 0;
    }
