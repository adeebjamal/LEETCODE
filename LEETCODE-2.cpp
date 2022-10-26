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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=l1;
        ListNode* head2=l2;
        int sum=head1->val+head2->val;
        ListNode* ans=new ListNode(sum%10);
        ListNode* temp=ans;
        sum/=10;
        head1=head1->next;
        head2=head2->next;
        while(head1!=NULL and head2!=NULL) {
            sum+=head1->val+head2->val;
            temp->next=new ListNode(sum%10);
            sum/=10;
            temp=temp->next;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1!=NULL) {
            sum+=head1->val;
            temp->next=new ListNode(sum%10);
            sum/=10;
            temp=temp->next;
            head1=head1->next;
        }
        while(head2!=NULL) {
            sum+=head2->val;
            temp->next=new ListNode(sum%10);
            sum/=10;
            temp=temp->next;
            head2=head2->next;
        }
        if(sum>0) temp->next=new ListNode(sum%10);
        return ans;
    }
};
int main() {
    return 0;
}