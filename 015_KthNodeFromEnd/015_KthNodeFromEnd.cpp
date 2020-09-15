#include <iostream>

using namespace std;

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

struct ListNode {
	int val;
	struct ListNode *pNext;
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0) {
			return NULL;
		}

		ListNode *pRight = pListHead;
		ListNode *pLeft = pListHead;

		for (int i = 0; i < k-1; i++) {
			if (pRight->pNext != NULL) {
				pRight = pRight->pNext;
			}
			else {
				return NULL;
			}				
		}

		while (pRight->pNext != NULL) {
			pRight = pRight->pNext;
			pLeft = pLeft->pNext;
		}

		return pLeft;
	}
};

//尾插
void addToTail(ListNode **pHead, int value) {
	ListNode *pNew = new ListNode();
	pNew->val = value;
	pNew->pNext = NULL;

	if (*pHead == NULL) {
		*pHead = pNew;
	}
	else {
		ListNode *pNode = *pHead;
		while (pNode->pNext != NULL) {
			pNode = pNode->pNext;
		}
		pNode->pNext = pNew;
	}
}

//打印
void print(ListNode **pHead) {
	ListNode *pNode = *pHead;
	while (pNode != NULL) {
		cout << pNode->val << " " ;
		pNode = pNode->pNext;
	}
	cout << endl;
}

int main()
{
	ListNode* pNode = NULL;
	
	addToTail(&pNode, 1);
	addToTail(&pNode, 2);
	addToTail(&pNode, 3);
	addToTail(&pNode, 4);
	addToTail(&pNode, 5);
	addToTail(&pNode, 6);
	addToTail(&pNode, 7);
	cout << "the list is:" << endl;
	print(&pNode);

	Solution solu;
	int k;
	cout << "Enter k:" << endl;
	cin >> k;
	cout << "the " << k << "th number is " << solu.FindKthToTail(pNode, k)->val << endl;

	return 0;
}
