#include <iostream>
#include <cctype>
using namespace std;

const int MAX_LEN = 100;

char* makeAcronym(char* inpt){
    if(inpt == nullptr){
        return nullptr;
    }

    char* acronym = new char[MAX_LEN];

    int currPos = 0, currStart = -1, currLen = 0, posAcronym = 0;

    while(inpt[currPos] != '\0'){

        if(isalpha(inpt[currPos])){
            currStart = currPos;

            while(isalpha(inpt[currPos])){
                 currPos++;
                 currLen++;
            }

            if(currLen > 1){
                acronym[posAcronym] = toupper(inpt[currStart]);
                posAcronym++;
            }

            currStart = -1;
            currLen = 0;
        }
        else{
            currPos++;
        }
    }

    acronym[posAcronym] = '\0';

    return acronym;
}


int main(){
    ///�R���x�t�p�r�p�}�u ���y ���{�p�x�p���u�| �{���} char �y �}�� �x�p���y���r�p�}�u �p�t���u���p �r�����~�p�� ���� new
    ///�{���t�u���� ���}�u �x�p�t�u�|�y�|�y ���p�}�u�����p �x�p �}�p���y�r�p
    char* inpt = new char[MAX_LEN];

    ///�R���x�t�p�r�p�}�u ���{�p�x�p���u�|, �r �{���z���� �t�p �x�p���y���u�} �p�t���u���p, �{���t�u���� ���u �~�p�}�y���p �p�{�����~�y�}�p
    ///�H�p�~���|���r�p�}�u �s�� �x�p �t���q���p �����p�{���y�{�p �����} �~���}�p �r�u�u�t�~�p�s�p �t�p �}�� �x�p���y���u�} �p�t���u��
    char* result = nullptr;


    cout<<"Enter a string (max length "<<MAX_LEN-1<<"): ";
    /**
        �P���~�u�w�u �y���{�p�}�u �t�p �r���r�u�t�u�} ���y�}�r���|�u�~ �~�y�x �y�x�����|�x�r�p�}�u cin.getline(), �~�p
        �{���z���� �����t�p�r�p�}�u �{���t�u �t�p �x�p���y���u �r���r�u�t�u�~�y�� �~�y�x �y �� �{�p�{�r�p �}�p�{���y�}�p�|�~�p �t���|�w�y�~�p
        �B ���|�����p�� �����~�u�w�u �}�p���y�r�p �u �� �t���|�w�y�~�p MAX_LEN �y �������q�r�p �t�p �x�p���y���u�} ���u���}�y�~�y���p���y ���y�}�r���|
        ���u �y�}�p�}�u �~�p�z-�s���|���}�p �t���|�w�y�~�p �~�p �~�y�x�p MAX_LEN - 1
    */
    cin.getline(inpt, MAX_LEN);

    cout<<"The acronym is: ";

    result = makeAcronym(inpt);

    cout<<result;


}
