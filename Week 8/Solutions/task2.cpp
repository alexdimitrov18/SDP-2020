#include <iostream>
#include <queue>
#include <string>


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
    �U���~���{�y��, �{�������� �������r�u�����r�p �t�p�|�y �u�|�u�}�u�~���y���u �r �����p���{�p ���p �����t���u�t�u�~�y �r
    ���p�������� ���u�t, ��.�u. �u�|�u�}�u�~���p, �{���z���� ���u�t�y �~�p���u�|�� �~�p �����p���{�p���p �u ����-�}�p�|���{
    ���� �r���y���{�y �������p�~�p�|�y
*/
bool isAscending(std::queue<int> q){

    ///�D���{�p���� �r �����p���{�p���p �y�}�p �����~�u �t�r�p �u�|�u�}�u�~���p
    while(q.size()>=2){
        int temp = q.front(); ///�H�p���p�x�r�p�u�} �������z�~���������p �~�p �����u�t�~�y�� �u�|�u�}�u�~��
        q.pop();              ///�y �s�� �����u�}�p���r�p�}�u

        if(q.front() <= temp){ ///�@�{�� ���u�{�����y�� �����u�t�u�~ �u�|�u�}�u�~�� �u ����-�}�p�|���{ �y�|�y ���p�r�u�~ ���� �����u�t�y���~�y�� �����u�t�u�~, �x�~�p���y �~�u �u �r �~�p���p�����r�p�� ���u�t
            return false;      ///�R�|�u�t���r�p���u�|�~�� �r�������p�}�u false - �~�u �u �����t���u�t�u�~�p
        }
    }

    return true; ///�@�{�� �x�p �����|�p���p �����p���{�p �~�u ���}�u �~�p�}�u���y�|�y ���������y�r�����u���y�u ���� ���� �u �������t���u�t�u�~�p �r ���p�������� ���u�t �y �r�������p�}�u true

}

int main(){
    std::queue<int> inpt;

    inputQueue(inpt);
    std::cout<<"Is the queue in ascending order : "<<(isAscending(inpt) ? "Yes" : "No");
}
