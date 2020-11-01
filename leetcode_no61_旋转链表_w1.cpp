/* ------------------------------------------------------------------|
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了94.27%的用户
*	内存消耗：7.5 MB, 在所有 C++ 提交中击败了5.32%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 ListNode* rotateRight(ListNode* head, int k) {
     if (!head) {
         return head;
     }
     //统计链表长度
     ListNode* nowNode = head;
     int length = 1;
     while (nowNode->next) {
         length++;
         nowNode = nowNode->next;
     }
     //修改为环形链表
     nowNode->next = head;
     //取余数
     k %= length;
     ListNode* resHead = head->next;
     ListNode* resTail = head;
     int move = length - k - 1;
     //找到断点
     while (move--) {
         resHead = resHead->next;
         resTail = resTail->next;
     }

     resTail->next = nullptr;
     return resHead;
 }

 int main() {
     ListNode* head = new ListNode(1);
     ListNode* mainNode = head;
     mainNode->next = new ListNode(2);
     mainNode = mainNode->next;
     mainNode->next = new ListNode(3);
     mainNode = mainNode->next;
     mainNode->next = new ListNode(4);
     mainNode = mainNode->next;
     mainNode->next = new ListNode(5);
     mainNode = mainNode->next;
     int k = 2;


 }