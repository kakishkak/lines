#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
	int sizeName;
	cout << "Size of your name: ";
	cin >> sizeName;									//���������� ������ �����
	char* reversedName = new char[sizeName + 1];
	cout << "Enter your name: ";
	cin.ignore();
	cin.getline(reversedName, sizeName + 1);				//���������� ���
	reversedName[0] = (char)tolower(reversedName[0]);	//������ �������		//������� 1
	reversedName[sizeName - 1] = (char)toupper(reversedName[sizeName - 1]); //������� �������
	cout << "Your reversed name: ";
	for (int i = sizeName; i > -1; i--)
	{
		cout << reversedName[i];  //�����
	}
	delete[]reversedName;
	reversedName = nullptr;



	cout << "Enter text with no more than 10 letters: ";
	char* bigLetterText = new char[11];
	cin.getline(bigLetterText, 11);			//����
	for (int i = 0; i < 10; i++)
	{
		if (i % 3 == 0) {				//�������� �� 3 �����				   //������� 2
			bigLetterText[i - 1] = (char)toupper(bigLetterText[i - 1]); //������ 3 ����� ������ �������
		}
	}
	cout << bigLetterText;					//�����
	delete[] bigLetterText;
	bigLetterText = nullptr;



	srand(time(NULL));
	cout << "Enter text with no more than 10 letters: ";
	char* justText = new char[11];
	cin.getline(justText, 11);				//����
	for (int i = 0; i < 10; i++)
	{																		   //������� 3
		if (justText[i] == 'A' || justText[i] == 'C' || justText[i] == 'M') {  //�������� �� A,C,M
			justText[i] = (char)(rand() % 255);		//�������������
		}
	}
	cout << justText;		//�����
	delete[]justText;
	justText = nullptr;



	cout << "Enter text with no more than 10 letters: ";
	char* worldText = new char[11];
	cin.getline(worldText, 11);		//����
	for (int i = 0; i < 10; i++)
	{
		if (worldText[i] == 'H' && i != 6 && worldText[i + 1] == 'e' && worldText[i + 2] == 'l' && worldText[i + 3] == 'l' && worldText[i + 4] == 'o') {	//�������� �� Hello	
			worldText[i] = 'W';//
			worldText[i + 1] = 'o';//											//������� 4
			worldText[i + 2] = 'r';//  ������ ����
			worldText[i + 3] = 'l';//
			worldText[i + 4] = 'd';//
		}
	}
	cout << "Here the changed variant: " << worldText; //�����
	delete[]worldText;
	worldText = nullptr;





	int sentenceLenght;  // ����� �����������
	int stepOfEncryps;	 // ��� ��������
	cout << "Write the lenght of your sentence: ";
	cin >> sentenceLenght;	// ������ ����� �����������
	cin.ignore();
	sentenceLenght++;
	char* userSentence = new char[sentenceLenght];	// ���������� �������� �����������
	cout << "Write your sentence: ";											//������� 5
	cin.getline(userSentence, sentenceLenght);		// ������ �����������							
	cout << "Write the encryption step (these can be both positive and negative numbers) : ";
	cin >> stepOfEncryps;	// ����� ��� ���������� (�� ����� ���� ��� ������������� ��� � �������������, �� ����� ����� �������� ������� ����������)


	cout << "Your encrypt sentence: " << endl;
	for (int i = 0; i < sentenceLenght; i++)
	{
		if ((int)userSentence[i] > 64 && (int)userSentence[i] < 91 || (int)userSentence[i] > 96 && (int)userSentence[i] < 123) { // �������� ��������� �� ����� ��������� �� �� ����
			(int)userSentence[i] > 96 ? cout << (char)(((((((int)userSentence[i] - 97) + stepOfEncryps) % 26) + 26) % 26) + 97) : cout << (char)(((((((int)userSentence[i] - 65) + stepOfEncryps) % 26) + 26) % 26) + 65); // ����� ������� �������� ���������� ����� �� ������� � ���� ���, �� ���� ������� � ��������� �������� ����)
		}
		else {
			cout << userSentence[i];  // ����� ������� ��� ���������� ���� ��� �� ����� �������� '!'
		}
	}
}