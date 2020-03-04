#include <iostream>
using namespace std;

const int MAX_LEN = 100;

void change(char* &str, char targetChar, char newChar){
    ///�@�{�� ���{�p�x�p���u�|�� �~�u �������y �{���} �~�y���� �~���}�p �{�p�{�r�� �t�p �����p�r�y�}
    if(str == nullptr){
        return;
    }

    ///�P�����r�p�}�u �t�p ���q�����w�t�p�}�u �}�p���y�r�p
    int pos = 0;

    while(str[pos]!='\0'){
        if(str[pos] == targetChar){
            str[pos] = newChar;
        }
        pos++;
    }
}

int main(){
    ///�R���x�t�p�r�p�}�u ���y ���{�p�x�p���u�| �{���} char �y �}�� �x�p���y���r�p�}�u �p�t���u���p �r�����~�p�� ���� new
    ///�{���t�u���� ���}�u �x�p�t�u�|�y�|�y ���p�}�u�����p �x�p �}�p���y�r�p
    char* inpt = new char[MAX_LEN];
    char targetChar, newChar;

    cout<<"Enter a string (max length "<<MAX_LEN-1<<"): ";
    /**
        �P���~�u�w�u �y���{�p�}�u �t�p �r���r�u�t�u�} ���y�}�r���|�u�~ �~�y�x �y�x�����|�x�r�p�}�u cin.getline(), �~�p
        �{���z���� �����t�p�r�p�}�u �{���t�u �t�p �x�p���y���u �r���r�u�t�u�~�y�� �~�y�x �y �� �{�p�{�r�p �}�p�{���y�}�p�|�~�p �t���|�w�y�~�p
        �B ���|�����p�� �����~�u�w�u �}�p���y�r�p �u �� �t���|�w�y�~�p MAX_LEN �y �������q�r�p �t�p �x�p���y���u�} ���u���}�y�~�y���p���y ���y�}�r���|
        ���u �y�}�p�}�u �~�p�z-�s���|���}�p �t���|�w�y�~�p �~�p �~�y�x�p MAX_LEN - 1
    */
    cin.getline(inpt, MAX_LEN);

    cout<<"Enter targetChar: ";
    cin>>targetChar;
    cout<<"Enter newChar:";
    cin>>newChar;

    change(inpt, targetChar, newChar);

    cout<<"After change: ";
    cout<<inpt<<endl;
}
