/*******************************************************
 *  test
 *  My Website           https://zhangqixiang.cn
 *  My Github            https://github.com/hmjmf
 *  Email                zqx5449@gmail.com
 * 
 *  Created by 启翔 张 (QiXiang Zhang) on 2018/7/19.
 *  Copyright (c) 2018 . All rights reserved.
 *******************************************************/

#include <assert.h>
#include "math.h"
#include "vector"
#include "iostream"
struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(nullptr) {}
   };

//2
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* list = new ListNode(0);
    ListNode* l = list;

    int carry = 0;
    while (l1 || l2 || carry){
      int value1 = 0;
      int value2 = 0;
      if(l1){
        value1 = l1->val;
        l1 = l1->next;
      }
      if(l2){
        value2 = l2->val;
        l2 = l2->next;
      }

      int val = value1 + value2 + carry;
      carry = val / 10;

      l->val = val%10;
      if (l1 || l2 || carry){
        l->next = new ListNode(0);
        l = l->next;
      }
    }
    return list;
  }
};

ListNode* buildList(std::vector<int> v){
  ListNode* list = new ListNode(0);
  ListNode* l = list;
  for(auto i = 0; i<v.size();i++){
    l->val = v[i];
    if (i == v.size() - 1) break;
    l->next = new ListNode(0);
    l = l->next;
  }
  return list;
}
void printList(ListNode* l){
  while (l){
    std::cerr << l->val << std::endl;
    l = l->next;
  }
}
void TEST(){
  Solution s;
  printList(s.addTwoNumbers(buildList({2,4,3}), buildList({5,6,4})));
}

int main()
{
  TEST();
}
