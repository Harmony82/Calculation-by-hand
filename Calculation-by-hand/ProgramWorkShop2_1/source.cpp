#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<format>
using namespace std;

const int MAX_INPUT_DIGITS = 50;
const int MAX_CALCULATION_DIGITS = 50+1;//1���オ�肤��
bool Input(int conversionInt[MAX_CALCULATION_DIGITS])
{
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		conversionInt[input.length() - 1 - i] = input[i] - '0';
		//\0������������������t�����ɓ���Ă���
	}
//-�����m����
}
void StartProcessing(int inputTotal[MAX_CALCULATION_DIGITS], int inputNow[MAX_CALCULATION_DIGITS])
{
	cout << "1�ڂ̐��l�����" << "\n" << ":";
	Input(inputTotal);
	cout << "2�ڂ̐��l�����" << "\n" << ":";
	Input(inputNow);
}
void AddNumber(int inputNow[MAX_CALCULATION_DIGITS])
{
	cout << "���������" << "\n" << ":";
	Input(inputNow);
}
void Calculation(int inputTotal[MAX_CALCULATION_DIGITS], int inputNow[MAX_CALCULATION_DIGITS])
{
	int moveup = 0;
	for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
	{
		if (inputTotal[i] + inputNow[i] > 9)//�J��オ�肠��
		{
			inputTotal[i] = inputTotal[i] + inputNow[i] - 10;
			inputTotal[i + 1]++;
		}
		else//�J��オ��Ȃ�
		{
			inputTotal[i] = inputTotal[i] + inputNow[i];
		}
	}
}
void DisplayNumber(int Numbers[MAX_CALCULATION_DIGITS])
{
	bool displayfrag = false;
	for (int i = MAX_CALCULATION_DIGITS - 1; i >= 0; i--)
	{
		if (Numbers[i] != 0)
			displayfrag = true;
		if (displayfrag)
			cout << Numbers[i];
		else
			cout << " ";
	}
}
void DisplayFormula(int inputTotal[MAX_CALCULATION_DIGITS], int inputNow[MAX_CALCULATION_DIGITS])
{
	DisplayNumber(inputTotal);
	cout << "\n";
	DisplayNumber(inputNow);
	cout << "\n";
	for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
	{
		cout << "-";
	}
	cout << "\n";
}
void DisplayAnswer(int inputTotal[MAX_CALCULATION_DIGITS])
{
	DisplayNumber(inputTotal);
	cout << "\n";
}
int main()
{
	int inputTotal[MAX_CALCULATION_DIGITS] = { 0 };
	int inputNow[MAX_CALCULATION_DIGITS] = { 0 };

	StartProcessing(inputTotal, inputNow);
	while (true)
	{
		DisplayFormula(inputTotal, inputNow);
		Calculation(inputTotal, inputNow);
		DisplayAnswer(inputTotal);
		AddNumber(inputNow);
	}
}