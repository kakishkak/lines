#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
	int sizeName;
	cout << "Size of your name: ";
	cin >> sizeName;									//Записываем размер имени
	char* reversedName = new char[sizeName + 1];
	cout << "Enter your name: ";
	cin.ignore();
	cin.getline(reversedName, sizeName + 1);				//Записываем имя
	reversedName[0] = (char)tolower(reversedName[0]);	//Нижний регистр		//Задание 1
	reversedName[sizeName - 1] = (char)toupper(reversedName[sizeName - 1]); //Верхний регистр
	cout << "Your reversed name: ";
	for (int i = sizeName; i > -1; i--)
	{
		cout << reversedName[i];  //Вывод
	}
	delete[]reversedName;
	reversedName = nullptr;



	cout << "Enter text with no more than 10 letters: ";
	char* bigLetterText = new char[11];
	cin.getline(bigLetterText, 11);			//Ввод
	for (int i = 0; i < 10; i++)
	{
		if (i % 3 == 0) {				//Проверка на 3 букву				   //Задание 2
			bigLetterText[i - 1] = (char)toupper(bigLetterText[i - 1]); //Каждую 3 букву делаем большой
		}
	}
	cout << bigLetterText;					//Вывод
	delete[] bigLetterText;
	bigLetterText = nullptr;



	srand(time(NULL));
	cout << "Enter text with no more than 10 letters: ";
	char* justText = new char[11];
	cin.getline(justText, 11);				//Ввод
	for (int i = 0; i < 10; i++)
	{																		   //Задание 3
		if (justText[i] == 'A' || justText[i] == 'C' || justText[i] == 'M') {  //Проверка на A,C,M
			justText[i] = (char)(rand() % 255);		//Рандомизируем
		}
	}
	cout << justText;		//Вывод
	delete[]justText;
	justText = nullptr;



	cout << "Enter text with no more than 10 letters: ";
	char* worldText = new char[11];
	cin.getline(worldText, 11);		//Ввод
	for (int i = 0; i < 10; i++)
	{
		if (worldText[i] == 'H' && i != 6 && worldText[i + 1] == 'e' && worldText[i + 2] == 'l' && worldText[i + 3] == 'l' && worldText[i + 4] == 'o') {	//Проверка на Hello	
			worldText[i] = 'W';//
			worldText[i + 1] = 'o';//											//Задание 4
			worldText[i + 2] = 'r';//  Замена букв
			worldText[i + 3] = 'l';//
			worldText[i + 4] = 'd';//
		}
	}
	cout << "Here the changed variant: " << worldText; //Вывод
	delete[]worldText;
	worldText = nullptr;





	int sentenceLenght;  // Длина предложения
	int stepOfEncryps;	 // Шаг шифровки
	cout << "Write the lenght of your sentence: ";
	cin >> sentenceLenght;	// Вводим длину предложения
	cin.ignore();
	sentenceLenght++;
	char* userSentence = new char[sentenceLenght];	// Переменная хранящая предложение
	cout << "Write your sentence: ";											//Задание 5
	cin.getline(userSentence, sentenceLenght);		// Вводим предложение							
	cout << "Write the encryption step (these can be both positive and negative numbers) : ";
	cin >> stepOfEncryps;	// Пишем шаг шифрования (он может быть как положительным так и отрицательным, от этого будет зависеть сторона шифрования)


	cout << "Your encrypt sentence: " << endl;
	for (int i = 0; i < sentenceLenght; i++)
	{
		if ((int)userSentence[i] > 64 && (int)userSentence[i] < 91 || (int)userSentence[i] > 96 && (int)userSentence[i] < 123) { // Проверка являеться ли буква латинской по ее коду
			(int)userSentence[i] > 96 ? cout << (char)(((((((int)userSentence[i] - 97) + stepOfEncryps) % 26) + 26) % 26) + 97) : cout << (char)(((((((int)userSentence[i] - 65) + stepOfEncryps) % 26) + 26) % 26) + 65); // Очень сложная операция шифрования буквы на которую я убил час, но зато красиво и тернарный оператор есть)
		}
		else {
			cout << userSentence[i];  // Вывод символа без шифрования если это не буква например '!'
		}
	}
}