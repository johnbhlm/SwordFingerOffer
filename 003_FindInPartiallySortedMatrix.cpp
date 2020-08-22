#include <iostream>
#include <vector>

using namespace std;

//1.暴力法
//class Solution {
//public:
//	bool Find(int target, vector<vector<int> > array) {
//		int row = 0, col = 0, t = 0;
//		bool isFound = false;
//
//		for (int i = 0; i < array.size(); ++i) {
//			for (int j = 0; j < array[i].size(); ++j) {
//				if (false == isFound && target == array[i][j]) {
//					//已经找到后就没必要再找了
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
//		// 从右上角的元素找起,如果查找的元素比当前位置元素小, 就向左走; 如果查找的元素比当前位置元素大, 就向下走
//		for (int i = 0, j = cols - 1; (i >= 0 && i < rows) && (j >= 0 && j < cols);) {
//			if (target == array[i][j]) {
//				isFound = true;
//				break;
//			}
//			else if(array[i][j] > target){//target在当前位置的左侧
//				j--;
//				
//			}
//			else {//target在当前位置的下方
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

		//从左下角的元素找起,如果查找的元素比当前位置元素小, 就向上走; 如果查找的元素比当前位置元素大, 就向右走
		for (int i = rows - 1, j = 0; (i >= 0 && i < rows) && (j >= 0 && j < cols);) {
			if (target == array[i][j]) {
				isFound = true;
				break;
			}
			else if (target < array[i][j]) { //target在当前位置的上方
				i--;
			}
			else{ //target在当前位置的右侧
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

