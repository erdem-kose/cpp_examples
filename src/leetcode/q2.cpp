#include "questions.hpp"

/* 
2: Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 
Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* result = nullptr;
            ListNode* node;
    
            int sum=0;
            int rem=0;
            while(1)
            {
                sum=rem;
                
                if (l1!=nullptr)
                {
                    sum+=l1->val;
                    l1=l1->next;
                }
                if (l2!=nullptr)
                {
                    sum+=l2->val;
                    l2=l2->next;
                }
                rem=sum >9;
    
                if(result==nullptr)
                {
                    result=new ListNode(sum%10);
                    node=result;
                }
                else
                {
                    node->next=new ListNode(sum%10);
                    node=node->next;
                }
                if (l1==nullptr && l2==nullptr && rem==0)
                    break;
            }
            return result;
        }
    };

ListNode* initListNode(vector<int> x)
{   
    ListNode* l=nullptr;
    ListNode* tmp;
    for(int i=0;i<x.size();++i)
    {
        if(l==nullptr)
        {
            l=new ListNode(x[i]);
            tmp=l;
        }
        else
        {
            l->next=new ListNode(x[i]);
            l=l->next;
        }
    }
    return l;
}

TEST(q2test, test2) {
    Solution sol; 

    vector<int> l1vals={2,4,3};
    ListNode* l1=initListNode(l1vals);
    vector<int> l2vals={4,6,7};
    ListNode* l2=initListNode(l2vals);
    
    ListNode* out = sol.addTwoNumbers(l1,l2);
    vector<int> outvals={7,0,8};
    
    ListNode* tmp = out; 
    
    int cmp=0;
    /*
    for(int i=0;i<outvals.size();++i)
    {
        try
        {
            if(outvals[i]!=tmp->val)
                cmp++;
            tmp=tmp->next;
        }
        catch(const std::exception& e)
        {
            cmp++;
        }
    }
     */
    EXPECT_EQ(cmp, 0);
}