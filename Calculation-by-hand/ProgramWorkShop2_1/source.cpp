//https://github.com/Harmony82/Calculation-by-hand
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<format>
using namespace std;

const int MAX_CALCULATION_DIGITS = 52;//1���オ�肤��
/// <summary>
/// 
/// </summary>
/// <param name="input"></param>
/// <param name="conversionInt"></param>
/// <returns>�L���ȓ��͂�������</returns>
bool Conversion(string input, int conversionInt[MAX_CALCULATION_DIGITS])
{
	bool signexist = false;
	bool isvalid = true;//�L���ȓ��͂�
	for (int i = 0; i < input.length(); i++)
	{
		//\0������������������t�����ɓ���Ă���
		conversionInt[input.length() - 1 - i] = input[i] - '0';
	}
	for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
	{
		//�����̂��Ƃ�0�̂݁B�܂蕄���̓��͓͂��͂̍ŏ��̂�
		if (signexist == true && conversionInt[i] != 0) {
			isvalid = false;
		}

		if (conversionInt[i] >= 0 &&
			conversionInt[i] <= 9)
		{
		}
		else if (conversionInt[i] == '-' - '0')
		{
			signexist = true;
		}
		else
		{
			isvalid = false;
		}
	}
	if (conversionInt[MAX_CALCULATION_DIGITS - 2] != 0 || conversionInt[MAX_CALCULATION_DIGITS - 1] != 0)
	{
		isvalid = false;
	}

	if (isvalid == false)
	{
		cout << "�����ȓ��͂ł��B�������邢��-�A+����͂��ĉ������B������" << MAX_CALCULATION_DIGITS << "�܂łł��B" << "\n";
		return false;
	}
	else
	{
		return true;
	}
}
/// <summary>
/// 
/// </summary>
/// <param name="conversionInt"></param>
/// <param name="signcheck"></param>
/// <returns>�����Z���ǂ���</returns>
bool Input(int conversionInt[MAX_CALCULATION_DIGITS], bool signcheck = false)
{
	string input;
	do
	{
		for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
		{
			conversionInt[i] = 0;
		}
		cin >> input;
	} while (!Conversion(input, conversionInt));

	if (signcheck != true) { return false; }
	for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
	{
		if (conversionInt[i] == '-' - '0')
		{
			conversionInt[i] = 0;
			return true;
		}
	}
	return false;
}
void StartProcessing(int inputTotal[MAX_CALCULATION_DIGITS], int inputNow[MAX_CALCULATION_DIGITS], bool& isSubtraction)
{
	cout << "��������͂��Čv�Z���ł���B\n�Ή����Ă��錅��" << MAX_CALCULATION_DIGITS - 2 << "���܂ŁB";
	cout << "1�ڂ̐��l�����" << "\n" << ":";
	Input(inputTotal);
	cout << "2�ڂ̐��l�����" << "\n" << ":";
	isSubtraction = Input(inputNow, true);
}
void AddNumber(int inputNow[MAX_CALCULATION_DIGITS], bool& isSubtraction)
{
	cout << "���������" << "\n" << ":";
	isSubtraction = Input(inputNow, true);
}
void Addition(int inputTotal[MAX_CALCULATION_DIGITS], int inputNow[MAX_CALCULATION_DIGITS])
{
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
void Subtraction(int inputTotal[MAX_CALCULATION_DIGITS], int inputNow[MAX_CALCULATION_DIGITS])
{
	for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
	{
		if (inputTotal[i] - inputNow[i] < 0)//�J�艺���肠��
		{
			inputTotal[i] = inputTotal[i] - inputNow[i] + 10;
			inputTotal[i + 1]--;
		}
		else//�J�艺����Ȃ�
		{
			inputTotal[i] = inputTotal[i] - inputNow[i];
		}
	}
}
void DisplayNumber(int Numbers[MAX_CALCULATION_DIGITS])
{
	int tmp[MAX_CALCULATION_DIGITS];
	if (Numbers[MAX_CALCULATION_DIGITS-1] == 9)
	{
		int Numbertmp[MAX_CALCULATION_DIGITS];
		for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
		{
			Numbertmp[i] = Numbers[i];
		}
		for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
		{
			tmp[i] = 0;
		}
		tmp[MAX_CALCULATION_DIGITS - 1] = 1;
		Numbertmp[MAX_CALCULATION_DIGITS - 1] = 0;
		Subtraction(tmp, Numbertmp);

	}
	else
	{
		for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
		{
			tmp[i] = Numbers[i];
		}
	}

	bool displayfrag = false;
	for (int i = MAX_CALCULATION_DIGITS - 1; i >= 0; i--)
	{
		if (tmp[i] != 0)
			displayfrag = true;
		if (displayfrag)
			cout << tmp[i];
		else if (i == 0)
			cout << 0;
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
bool EndCheck(int Numbers[MAX_CALCULATION_DIGITS])
{
	for (int i = 0; i < MAX_CALCULATION_DIGITS; i++)
	{
		if (Numbers[i] != 0)
			return false;
	}
	cout << "�I�����܂�";
	return true;
}
int main()
{
	int inputTotal[MAX_CALCULATION_DIGITS] = { 0 };
	int inputNow[MAX_CALCULATION_DIGITS] = { 0 };
	bool isSubtraction;

	StartProcessing(inputTotal, inputNow, isSubtraction);
	while (true)
	{
		DisplayFormula(inputTotal, inputNow);
		if (isSubtraction)
			Subtraction(inputTotal, inputNow);
		else
			Addition(inputTotal, inputNow);
		DisplayAnswer(inputTotal);
		AddNumber(inputNow, isSubtraction);
		if (EndCheck(inputNow))break;
	}
}