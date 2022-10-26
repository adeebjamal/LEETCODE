#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val=val;
        this->next=NULL;
    }
};
class Solution {
public:
    void reverse_list(ListNode* &head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nexxt=head->next;
        while(curr!=NULL) {
            nexxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nexxt;
        }
        head=prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverse_list(l1);
        reverse_list(l2);
        ListNode* head1=l1;
        ListNode* head2=l2;
        ListNode* ans=new ListNode((head1->val + head2->val)%10);
        int sum=(head1->val + head2->val)/10;
        head1=head1->next;
        head2=head2->next;
        ListNode* temp=ans;
        while(head1!=NULL or head2!=NULL) {
            if(head1!=NULL) {
                sum+= head1->val;
                head1=head1->next;
            }
            if(head2!=NULL) {
                sum+= head2->val;
                head2=head2->next;
            }
            temp->next=new ListNode(sum%10);
            sum/=10;
            temp=temp->next;
        }
        reverse_list(ans);
        return ans;
    }
};
int main() {

    return 0;
}