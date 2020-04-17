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
    ���p�������� ���u�t, ��.�u. �u�|�u�}�u�~���p, �{���z���� ���u�t�y �~�p ���u�|�� �~�p �����p���{�p���p �u ����-�}�p�|���{
    ���� �r���y���{�y �������p�~�p�|�y
*/
bool isAscending(std::queue<int> q){

    ///�D���{�p���� �r �����p���{�p���p �y�}�p �����~�u �t�r�p �u�|�u�}�u�~���p
    while(q.size()>=2){
        int temp = q.front(); ///�H�p���p�x�r�p�u�} �������z�~���������p �~�p �����u�t�~�y�� �u�|�u�}�u�~��
        q.pop();              ///�y �s�� �����u�}�p���r�p�}�u

        if(q.front() < temp){ ///�@�{�� ���u�{�����y�� �����u�t�u�~ �u�|�u�}�u�~�� �u ����-�}�p�|���{ ���� �����u�t�y���~�y�� �����u�t�u�~, �x�~�p���y �~�u �u �r �~�p���p�����r�p�� ���u�t
            return false;     ///�R�|�u�t���r�p���u�|�~�� �r�r�������p�}�u false - �~�u �u �����t���u�t�u�~�p
        }
    }

    return true; ///�@�{�� �x�p �����|�p���p �����p���{�p �~�u ���}�u �~�p�}�u���y�|�y ���������y�r�����u���y�u ���� ���� �u �������t���u�t�u�~�p �r ���p�������� ���u�t �y �r�������p�}�u true

}

/**
    �U���~���{�y��, �{�������� ���� �����t�p�t�u�~�y �t�r�u ���������y���p�~�y �����p���{�y �r ���p�������� ���u�t �r�������p �����u���p �����p���{�p,
    �{�������� �������� �u ���������y���p�~�p �� �u�|�u�}�u�~���y���u �~�p �����t�p�t�u�~�y���u �t�r�u.

    @param[in] q1, q2 �D�r�u���u �����t�p�t�u�~�y �����p���{�y

    @returns �O���p���{�p, �{�������� �u ���������y���p�~�p �� �u�|�u�}�u�~���y���u �~�p q1 �y q2

    @throws 1 �@�{�� q1 �~�u �u ���������y���p�~�p ���p����������
    @throws 2 �@�{�� q2 �~�u �u ���������y���p�~�p ���p����������
*/
std::queue<int> mergeQ(std::queue<int> q1, std::queue<int> q2){

    ///�S�u�������r �q�|���{, �r �{���z���� �������r�u�����r�p�}�u �t�p�|�y �r�����t�p �u �{�����u�{���u�~
    try{
        ///�@�{�� �~���{���� ���� �t�r�u���u �����p���{�y �~�u �u �����t���u�t�u�~�p �r���x�����t������ ���r�����|���}�u �s���u���{�p, �{�������� ���u ���r�p�~�u�} �r catch �q�|���{�p
        if(!isAscending(q1))
        throw 1;
        if(!isAscending(q2))
        throw 2;
    }catch(int err){
        ///�@�{�� �y�}�p ���r�����|�u�~�p �s���u���{�p �y�x���y���r�p�}�u �~�p �u�{���p�~�p
        std::cout<<(err == 1 ? "First": "Second")<<" queue is not sorted!";
        throw; /// �P���u�t�p�r�p�}�u �{���t�p �~�p �s���u���{�p���p �~�p �r�y�{�p���p���p �����~�{���y��
    }

    std::queue<int> result;

    ///�D���{�p���� �y �r �t�r�u���u �����p���p�{�y �y�}�p �u�|�u�}�u�~���y
    while(!q1.empty()&&!q2.empty()){
        ///�@�{�� �����u�t�~�y�� �u�|�u�}�u�~�� �r q2 �u ����-�}�p�|���{ ���� �����u�t�~�y�� �u�|�u�}�u�~�� �r q1
        if(q1.front() > q2.front()){
            result.push(q2.front()); ///�P�����p�}�u �����u�t�~�y�� �u�|�u�}�u�~�� �~�p q2 �r ���u�x���|���p���~�p���p �����p���{�p
            q2.pop();                ///�P���u�}�p���r�p�}�u �u�|�u�}�u�~���p ���� q2
        }
        ///�B ���������y�r�u�~ ���|�����p�z �����p�r�y�} �s�����~�y���u ���������{�y �x�p q1
        else{
            result.push(q1.front());
            q1.pop();
        }
    }

    ///�R�u�s�p �p�{�� �~���{���� ���� �t�r�u���u �����p���{�y �y�}�p �u�|�u�}�u�~���y, ���u ���u �y�x�����|�~�y
    ///���������r�u���~�y�� ���y�{���| �y ���u �������~�u �������p�~�p�|�y���u �u�|�u�}�u�~���y �r ���u�x���|���p���~�p���p �����p���{�p
    while(!q1.empty()){
        result.push(q1.front());
        q1.pop();
    }

    while(!q2.empty()){
        result.push(q2.front());
        q2.pop();
    }

    return result;

}

int main(){
    std::queue<int> q1, q2;
    inputQueue(q1);
    inputQueue(q2);

    outputQueue(mergeQ(q1, q2));
}
