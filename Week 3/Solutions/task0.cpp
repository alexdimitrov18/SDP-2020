#include <iostream>
using namespace std;

const int MAX_LEN = 100;

int len(char* ptr){
    ///�B���r�u�w�t�p�}�u �q��������, �{���z���� �t�p �����q�������r�p ���u�{�����y�� ���p�x�}�u�� �~�p ���y�}�r���|�~�y�� �~�y�x
    ///�S���x�y �q�������� ���u �~�y ���|���w�y �y �x�p �t�p �����}�~�y�} �~�p �{���� �����x�y���y�� �r �}�p���y�r�p ���}�u �����y�s�~�p�|�y
    int result = 0;

    ///�D���{�p���� �~�u �����u���~�u�} �{���p�� �~�p ���y�}�r���|�~�y�� �~�y�x (���u���}�y�~�y���p���p���p �~���|�p)
    ///�T�r�u�|�y���r�p�}�u �q���������p
    while(ptr[result] != '\0'){
        result++;
    }

    return result;
}

int main(){
    ///�R���x�t�p�r�p�}�u ���y ���{�p�x�p���u�| �{���} char �y �}�� �x�p���y���r�p�}�u �p�t���u���p �r�����~�p�� ���� new
    ///�{���t�u���� ���}�u �x�p�t�u�|�y�|�y ���p�}�u�����p �x�p �}�p���y�r�p
    char* inpt = new char[MAX_LEN];


    cout<<"Enter a string (max length "<<MAX_LEN-1<<"): ";
    /**
        �P���~�u�w�u �y���{�p�}�u �t�p �r���r�u�t�u�} ���y�}�r���|�u�~ �~�y�x �y�x�����|�x�r�p�}�u cin.getline(), �~�p
        �{���z���� �����t�p�r�p�}�u �{���t�u �t�p �x�p���y���u �r���r�u�t�u�~�y�� �~�y�x �y �� �{�p�{�r�p �}�p�{���y�}�p�|�~�p �t���|�w�y�~�p
        �B ���|�����p�� �����~�u�w�u �}�p���y�r�p �u �� �t���|�w�y�~�p MAX_LEN �y �������q�r�p �t�p �x�p���y���u�} ���u���}�y�~�y���p���y ���y�}�r���|
        ���u �y�}�p�}�u �~�p�z-�s���|���}�p �t���|�w�y�~�p �~�p �~�y�x�p MAX_LEN - 1
    */
    cin.getline(inpt, MAX_LEN);

    cout<<len(inpt)<<endl;

}
