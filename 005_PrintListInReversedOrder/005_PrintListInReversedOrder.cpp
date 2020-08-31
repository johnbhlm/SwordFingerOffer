#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

//struct ListNode {
//	int m_nVal;
//	struct ListNode *m_pNext;
//	//ListNode(int x) :m_nVal(x), m_pNext(NULL) {}
//};


////头插
//void AddToHead(ListNode **pHead, int value) {
//	ListNode *pNew = new ListNode();
//	pNew->m_nVal = value;
//	pNew->m_pNext = NULL;
//
//	if (*pHead == NULL) {
//		*pHead = pNew;
//	}
//	else {
//		pNew->m_pNext = (*pHead)->m_pNext;
//		(*pHead)->m_pNext = pNew;
//	}
//}

////尾插
//void AddToTail(ListNode **pHead, int value) {
//	ListNode *pNew = new ListNode();
//	pNew->m_nVal = value;
//	pNew->m_pNext = NULL;
//
//	if (*pHead == NULL) {
//		*pHead = pNew;
//	}else{
//		ListNode *pNode = *pHead;
//		while (pNode->m_pNext != NULL) {
//			pNode = pNode->m_pNext;
//		}
//		pNode->m_pNext = pNew;
//	}
//}

//// 查找并删除节点
//void RemoveNode(ListNode **pHead, int value) {
//	if (pHead == NULL || *pHead == NULL)
//		return;
//	ListNode *pToBeDeleted = NULL;
//	if ((*pHead)->m_nVal == value) {
//		pToBeDeleted = *pHead;
//		*pHead = (*pHead)->m_pNext;
//	}
//	else {
//		ListNode *pNode = *pHead;
//		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nVal!=value) {
//			pNode = pNode->m_pNext;
//		}
//		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nVal == value) {
//			pToBeDeleted = pNode->m_pNext;
//			pNode->m_pNext = pNode->m_pNext->m_pNext;
//		}
//	}
//	if (pToBeDeleted != NULL) {
//		delete pToBeDeleted;
//		pToBeDeleted = NULL;
//	}
//}


struct ListNode {
	int val;
	struct ListNode *next;
};

//尾插
void AddToTail(ListNode **pHead, int value) {
	ListNode *pNew = new ListNode();
	pNew->val = value;
	pNew->next = NULL;

	if (*pHead == NULL) {
		*pHead = pNew;
	}
	else {
		ListNode *pNode = *pHead;
		while (pNode->next != NULL) {
			pNode = pNode->next;
		}
		pNode->next = pNew;
	}
}

//// 1.栈 方法
//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {
//		vector<int> result;
//		stack<int> stk;
//
//		ListNode *pHead = head;
//		while (pHead != NULL) {
//			stk.push(pHead->val);
//			pHead = pHead->next;
//		}
//
//		while (!stk.empty()) {
//			result.push_back(stk.top());
//			stk.pop();
//		}
//		return result;
//	}
//};

//// 2.用库函数，每次扫描一个节点，将该结点数据存入vector中，如果该节点有下一节点，将下一节点数据直接插入vector最前面，直至遍历完
//// 或者直接加在最后，最后调用reverse
//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {
//		vector<int> result;
//		if (head != NULL) {
//			result.insert(result.begin(), head->val);
//			while (head->next != NULL) {
//				result.insert(result.begin(), head->next->val);
//				head = head->next;
//			}
//		}
//		return result;
//	}
//};


//// 3. 数组
//class Solution {
//public:
//	vector<int> printListFromTailToHead(ListNode* head) {		
//		ListNode *pHead = head;
//		int length = 0;
//		while(pHead != NULL) {
//			length++;
//			pHead = pHead->next;
//		}
//		
//		vector<int> result(length,0);
//		while (head != NULL) {
//			result[--length] = head->val;
//			head = head->next;
//		}
//		return result;
//	}
//};

//// 4. 递归
class Solution{
public:
	vector<int> printListFromTailToHead(struct ListNode* head){
		vector<int> result;
		printListFromTailToHeadRecursion(head, result);
		return result;
	}

	void printListFromTailToHeadRecursion(struct ListNode* head, vector<int> &result){
		if (head != NULL){
			printListFromTailToHeadRecursion(head->next, result);
			result.push_back(head->val);
		}
	}
};

class Solution {
public:
	vector<int> result;
	vector<int> printListFromTailToHead(ListNode* head) {		
		if (head == NULL) {
			return result;
		}

		result = printListFromTailToHead(head->next);
		result.push_back(head->val);

		return result;
	}
};

int main()
{
	/*ListNode list[4];
	list[0].m_nVal = 1;
	list[0].m_pNext = &list[1];
	list[1].m_nVal = 2;
	list[1].m_pNext = &list[2];
	list[2].m_nVal = 3;
	list[2].m_pNext = &list[3];
	list[3].m_nVal = 4;
	list[3].m_pNext = NULL;*/

	ListNode *pHead=NULL;
	AddToTail(&pHead, 1);
	AddToTail(&pHead, 2);
	AddToTail(&pHead, 3);
	AddToTail(&pHead, 4);

	Solution solu;
	vector<int> res = solu.printListFromTailToHead(pHead);

	cout << "there are " << res.size() << "datas in vector" << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}
