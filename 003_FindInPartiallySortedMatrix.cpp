#include <iostream>
#include <vector>

using namespace std;

//1.������
//class Solution {
//public:
//	bool Find(int target, vector<vector<int> > array) {
//		int row = 0, col = 0, t = 0;
//		bool isFound = false;
//
//		for (int i = 0; i < array.size(); ++i) {
//			for (int j = 0; j < array[i].size(); ++j) {
//				if (false == isFound && target == array[i][j]) {
//					//�Ѿ��ҵ����û��Ҫ������
//					isFound = true;
//					return isFound;
//				}
//			}
//		}
//		return isFound;
//	}
//};

//class Solution {
//public:
//	bool Find(int target, vector<vector<int> > array) {
//		bool isFound = false;
//		int rows = array.size();
//		int cols = array[0].size();
//
//		for (int i = 0, j = cols - 1; (i >= 0 && i < rows) && (j >= 0 && j < cols);) {
//			if (target == array[i][j]) {
//				isFound = true;
//				break;
//			}
//			else if(array[i][j] > target){//target�ڵ�ǰλ�õ����
//				j--;
//				
//			}
//			else {//target�ڵ�ǰλ�õ��·�
//				i++;
//			}
//		}
//		return isFound;
//	}
//};

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		bool isFound = false;
		int rows = array.size();
		int cols = array[0].size();

		for (int i = rows - 1, j = 0; (i >= 0 && i < rows) && (j >= 0 && j < cols);) {
			if (target == array[i][j]) {
				isFound = true;
				break;
			}
			else if (target < array[i][j]) { //target�ڵ�ǰλ�õ��Ϸ�
				i--;
			}
			else{ //target�ڵ�ǰλ�õ��Ҳ�
				j++;
			}			
		}
		return isFound;
	}
};

void print(vector<vector<int> > array, int row, int cloumn)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cloumn; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int a1[] = { 1, 2, 8, 9, };
	int a2[] = { 2, 4, 9, 12, };
	int a3[] = { 4, 7, 10, 13, };
	int a4[] = { 6, 8, 11, 15, };
	vector<vector<int>> array;
	array.push_back(vector<int>(a1, a1 + 4));
	array.push_back(vector<int>(a2, a2 + 4));
	array.push_back(vector<int>(a3, a3 + 4));
	array.push_back(vector<int>(a4, a4 + 4));

	int num;
	cout << "Enter the find number:" << endl;
	cin >> num;

	cout << "the matrix is:" << endl;
	print(array, 3, 4);

	Solution solu;

	if (solu.Find(num, array)) {
		cout << "find num:" << num << endl;
	}
	else {
		cout << "not find num:" << num << endl;
	}

	return 0;
}

