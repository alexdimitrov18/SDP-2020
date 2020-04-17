#include <iostream>
#include <queue>
#include <string>
#include <stack>

/**
	�U���~�{���y��, �{�������� �������r�u�����r�p �t�p�|�y �u�t�y�~ ���y�}�r���|�u�~ �~�y�x ���u
	�����������y ���p�}�� ���� ���y�����y

	@param[in] s �B�����t�~�y�� �~�y�x

	@returns   �B�������p true, �p�{�� �u �y�x�����|�~�u�~�� �����|���r�y�u����, �r
			   ���������y�r�u�~ ���|�����p�z false
*/
bool isInteger(std::string s) {
	bool state = true;		///�U�|�p�s, �� �{���z���� ���x�~�p���p�r�p�}�u �t�p�|�y ���u�{�����y�� �~�y�x �����t�����w�p ���p�}�� ���y�����y

	for (int i = 0; state && i < s.length(); i++) {
		if (!isdigit(s[i])) {		///�@�{�� �~�p�}�u���y�} ���y�}�r���| ���p�x�|�y���u�~ ���� ���y�����p ���r�p�|���}�u ���|�p�s�p
			state = false;
		}
	}

	return state;
}


/**
	�U���~�{���y��, �{�������� �{���~�r�u�����y���p �t�p�t�u�~ ���y�}�r���|�u�~ �~�y�x �r ���u�|�����y���|�u�~�p �������z�~������

	@param[in] s �B�����t�~�y�� �~�y�x

	@returns   �B�������p ���y���|������ �r ���y�}�r���|�~�y�� �~�y�x �{�p���� ���u�|�����y���|�u�~�p �t�p�~�~�p
*/
int toInteger(std::string s) {
	int num = 0; ///�S�u�{���������� ���y���|��

	for (int i = 0; i < s.length(); i++) {
		num = 10 * num + (s[i] - '0');	///�T�}�~���w�p�r�p�}�u ���u�{���������� ���y���|�� �� 10 �y �s�� �����q�y���p�}�u �� ���u�{�����p���p ���y�����p
	}

	return num;

}


/**
	�����~�{���y��, �{�������� �r���r�u�w�t�p �r ���u���u���y���p�~�p �����p���{�p ���� ���u�|�y ���y���|�p,
	�t���{�p���� �~�u ���u �r���r�u�t�u �~�u����, �{���u���� �~�u �u �����|�� ���y���|��

	@param[in, out] q �P���t�p�t�u�~�p �����p���{�p, �r �{�������� �����|�~�y�} ���u�|�y ���y���|�p

*/
void inputQueue(std::queue<int>& q) {
	std::string input;  ///�N�y�x, �r �{���z���� ���p�x�y�} ���u�{�����y�� �r�����t ���� �{�|�p�r�y�p�������p���p

	while(1) {
		std::cin >> input;		///�I�x�r�|�y���p�}�u ���� ���������{�p �~�y�x

		if (isInteger(input)) {			///�@�{�� �y�x�r�|�u���u�~�y�� �~�y�x �u ���y���|��
			q.push(toInteger(input));   ///�P���u���q���p�x���r�p�}�u �s�� �r ���p�{���r�p �y �s�� ���|�p�s�p�}�u �r �����p���{�p���p
		}
		else {							///�B ���������y�r�u�~ ���|�����p�z ���u���}�y�~�y���p�}�u �����~�{���y�����p
			return;
		}
	}
}


///�U���~�{���y�� �����y�~���y���p���p �����p���{�p�~�p �u�{���p�~�p. �H�p ����-�����t�����q�~�� ���q�����~�u�~�y�u ���u �{���~�����|���y���p�z���u ��
///���u���u�~�y���u �����y�}�u���y ���� �����u�t�y���~������ �����p���~�u�~�y�u
void outputQueue(std::queue<int> q) {

	while (!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
}


/**
    �U���~�{���y��, �{�������� �������r�u�����r�p �t�p�|�y �u�|�u�}�u�~���y���u �~�p
    �����t�p�t�u�~�p���p �����p���{�p ���q���p�x���r�p�� ���p�|�y�~�t�����}. �@�|�s�����y�����}�p �u ���u�p�|�y�x�y���p�~
    �� �����}�����u�~ �����u�{ �y �����p���{�p. �D���{�p���� �r �����t�p�t�u�~�p���p �����p���{�p �y�}�p �u�|�u�}�u�~���y
    �������p�}�u �������r�y�� �u�|�u�}�u�~�� �r �����u�{�p (���p�{�p ���q�������p�}�u �����t���u�t�q�p���p �~�p �u�|�u�}�u�~���y���u �r �����p���{�p���p)
    �y �r �����p���{�p���p (���p�{�p �x�p���p�x�r�p�}�u �����y�s�y�~�p�|�~�p���p �����t���u�t�q�p). �R�u�s�p �p�{�� �����p���{�p���p �u ���q���p�x���r�p�|�p
    ���p�|�y�~�t���} ���� �r���u�{�y �t�r�p �������u�t�~�y �u�|�u�}�u�~���p �r �t�r�u���u �����}�����~�y ���������{�������y �������q�r�p �t�p ���y �������p�t�p��.

    @param[in] q �O���p���{�p���p, ���y�y���� �u�|�u�}�u�~���y ���u �������r�u�����r�p�}�u

    @returns true - �p�{�� ���q���x���r�p��  ���p�|�y�~�t�����}
             false - �r ���������y�r�u�~ ���|�����p�z

*/
bool isPalindrome(std::queue<int> q){
    std::stack<int> tempSt; ///�P���}�����u�~ �����u�{, �r �{���z���� ���u ���q�����~�u�} �u�|�u�}�u�~���y���u ���� �����p���{�p���p
    std::queue<int> tempQ;  ///�N���r�p �����p���{�p, �{���t�u���� ���u ���p�x�y�} �u�|�u�}�u�~���y���u �~�p �����t�p�t�u�~�p���p

    ///�D���{�p���� �y�}�p �u�|�u�}�u�~���y �r �����p���{�p���p
    while(!q.empty()){
        ///�P�����p�}�u �����u�t�~�y�� �u�|�u�}�u�~�� �~�p �����p���p�{���p �r �����}�����~�y���u �����u�{ �y �����p���{�p
        tempSt.push(q.front());
        tempQ.push(q.front());

        q.pop(); ///�����u�}�p�����r�p�}�u �����u�t�~�y�� �u�|�u�}�u�~��
    }

    ///�D���{�p���� �y�}�p �u�|�u�}�u�~���y �r �����}�����~�y�� �����u�{
    while(!tempSt.empty()){
        ///�@�{�� �t�r�p ���u�{�����y �u�|�u�}�u�~���y �r �����}�����~�y���u ���������{�������y ���u ���p�x�}�y�~�p�r�p�� ���� �����p���{�p���p �~�u �u ���q���p�x���r�p�|�p ���p�|�y�~�t�����}
        if(tempSt.top() != tempQ.front()){
            return false;
        }

        ///�P���u�}�p���r�p�}�u ���y �������r�y���u �t�r�p �u�|�u�}�u�~���p �x�p �����}�����~�y���u ���������{�������y, �x�p �t�p �t�����������y�} ���|�u�t�r�p���y���u �u�|�u�}�u�~���y
        tempSt.pop();
        tempQ.pop();
    }

    return true;
}

int main(){
    std::queue<int> inpt;

    inputQueue(inpt);
    std::cout<<"Is the queue palindrome : "<<(isPalindrome(inpt) ? "Yes" : "No");
}
