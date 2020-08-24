#include <iostream>

using namespace std;

/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL && length <= 0) {
			return;
		}

		int spaceCnt = 0; //空格数
		int strOrgLen = 0; //字符串实际长度

		while (str[strOrgLen] != '\0') {			
			if (str[strOrgLen] == ' ') {
				spaceCnt++;
			}
			strOrgLen++;
		}

		int strNewLen = (spaceCnt << 1) + strOrgLen; //strNewLen 为把空格替换成'%20'之后的长度
		int p1 = strOrgLen; //原始数组最后一个元素的下标
		int p2 = strNewLen; //新数组最后一个元素的下标
		
		while (p1 >= 0 && p2 > p1) {
			if (str[p1] == ' ') {
				str[p2--] = '0';
				str[p2--] = '2';
				str[p2--] = '%';
			}
			else {
				str[p2--] = str[p1];
			}
			p1--;
		}
	}
};

int main()
{
	char str[14] = "We Are Happy.";
	cout << "original string:" << endl;
	cout << str << endl;

	Solution solu;
	solu.replaceSpace(str, 14);
	cout << "replace string:" << endl;
	cout << str << endl;

	return 0;
}
