#include "iostream"
#include <vector>

struct ListNode{
  int data;
  ListNode* next;
  ListNode(int a):data(a),next(NULL) {}
};

class Solution {
public:
  ListNode* add_node(ListNode*, int);

  ListNode* reverse_ll(ListNode* head) {
    ListNode* temp=head->next;
    ListNode* current=head;
    ListNode* prev=NULL;

    while(current!=NULL) {
      current->next=prev;
      prev=current;
      current=temp;
      temp=temp->next;
    }
    return prev;
  }
}

void Solution::add_node(ListNode** head, int data) {
  ListNode* node = new ListNode(data);
  if(*head==NULL)
  *head=node;

  ListNode* temp=*head;
  while(temp->next!=NULL) {
    temp=temp->next;
  }
  temp->next=node;
}

int main() {
std::vector<int>elements{1,2,3,4,5};
Solution linked_list;
ListNode* head=NULL;
for(int i = 0; i<elements.size(); i++) {
  head=linked_list.add_node(head,elements[i]);
}
std::cout<<"LINKED LIST:\n";
ListNode* current=head;
while(current->next!=NULL)
  std::cout<<current->data<<"->";
std::cout<<current->data<<std::endl;

linked_list.reverse_ll(head);
std::cout<<"REVERSED LINKED LIST:\n";
current=head;
while(current->next!=NULL)
  std::cout<<current->data<<"->";
std::cout<<current->data<<std::endl;

  return 0;
}
