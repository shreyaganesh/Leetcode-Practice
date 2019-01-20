#include "iostream"
#include <vector>

struct ListNode{
  int data;
  ListNode* next;
  ListNode(int a):data(a),next(NULL) {}
};

class Solution {
public:
  void add_node(ListNode**, int);
  void print_List(ListNode*);
  ListNode* reverse_ll(ListNode*);
  ListNode* reverseList_recursion(ListNode*);
};

// Add new node to end of linked list given head and data of node
void Solution::add_node(ListNode** head, int data) {
  ListNode* node = new ListNode(data);
  if(*head==NULL)
  *head=node;
  else {
    ListNode* temp=*head;
    while(temp->next!=NULL) {
      temp=temp->next;
    }
    temp->next=node;
  }
}

// Print elements of Linked List
void Solution::print_List(ListNode* head) {
  ListNode* current=head;
  while(current->next!=NULL) {
    std::cout<<current->data<<"->";
    current=current->next;
  }
  std::cout<<current->data<<std::endl;
}

// Linked List Reversal - ITERATIVE
struct ListNode* Solution::reverse_ll(ListNode* head) {
    ListNode* current=head;
    ListNode* prev=NULL;

    while(current!=NULL) {
      ListNode* temp=current->next;
      current->next=prev;
      prev=current;
      current=temp;
    }
    return prev;
  }

// Linked List Reversal - RECURSIVE
struct ListNode* Solution::reverseList_recursion(ListNode* head) {
  if(head==NULL || head->next==NULL)
    return head;

  ListNode* p = reverseList_recursion(head->next);
  head->next->next = head;
  head->next = NULL;
  return p;
}

// MAIN FUNCTION CALL
int main() {

//initialize the linked list and print it
  std::vector<int>elements{1,2,3,4,5};
  Solution linked_list;
  ListNode* head=NULL;
  for(int i = 0; i<elements.size(); i++) {
    linked_list.add_node(&head,elements[i]);
  }

  std::cout<<"LINKED LIST:\n";
  linked_list.print_List(head);

//Reverse the linked list using iterative technique
  head=linked_list.reverse_ll(head);
  std::cout<<"REVERSED LINKED LIST (ITERATIVE):\n";
  linked_list.print_List(head);

//reverse it back to original using recursive technique
  head=linked_list.reverseList_recursion(head);
  std::cout<<"REVERSED LINKED LIST (RECURSIVE):\n";
  linked_list.print_List(head);

  return 0;
}
