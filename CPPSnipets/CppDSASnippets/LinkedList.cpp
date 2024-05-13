#include<bits/stdc++.h>
using namespace std;

struct Node* reverseList(struct Node *head)
{
        // code here
        // return head of reversed list
        struct Node* prev=nullptr;
        struct Node* temp=head;
        while(temp != nullptr)
        {
            struct Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
}
 bool detectLoop(Node* head)
 {
        // your code here
        Node* slow=head;
        Node* fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow == fast)
             return 1;
        }
        return 0;
}
int getNthFromLast(Node *head, int n)
{
           // Your code here
           Node* slow=head;
           Node* fast=head;
           
           Node* temp=head;
           int len=0;
           while(temp)
           {
               temp=temp->next;
               len++;
           }
           if(len < n)
            return -1;
           
        //   while( i<=n && fast)
        //   {
        //       fast=fast->next;
        //   }
           for(int i=1;i<=n;i++)
           {
               fast=fast->next;
           }
           if(fast == nullptr)
            return head->data;
           
           while(fast->next != nullptr)
           {
               slow=slow->next;
               fast=fast->next;
           }
           return slow->next->data;
}
int getMiddle(Node *head)
{
        // Your code here
        Node* slow=head;
        Node* fast=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
}
ListNode *detectCycle(ListNode *head) 
{
        // if(head == nullptr || head->next== nullptr)
        //     return nullptr;
        // unordered_map<ListNode*,int>m;
        // ListNode*temp=head;
        // int i=1;
        // ListNode* prev=nullptr;
        // while(temp != nullptr)
        // {
        //     if(m.find(temp) != m.end())
        //     {
        //         return temp;
        //     }
        //     m.insert({temp,i});
        //     i++;
        //     prev=temp;
        //     temp=temp->next;
        // }
        // return nullptr;
        
        if(head == nullptr || head->next== nullptr)
            return nullptr;
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast != nullptr && fast->next!= nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow == fast)
            {
                slow=head;
                while(slow != fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
                
            }
        }
        return nullptr;    
}
int countNodesinLoop(struct Node *head)
{
    // Code here
    struct Node* slow=head;
    struct Node* fast=head;
    
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow == fast)
        {
            fast=fast->next;
            int len=1;
            
            while(slow != fast)
            {
                fast=fast->next;
                len++;
            }
            return len;
        }
    }
    return 0;
    
}

int main()
{

}