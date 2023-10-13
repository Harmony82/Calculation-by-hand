#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<format>
using namespace std;
const int Digits = 51;
void Input(int conversionInt[Digits])
{
	string input;
	cin >> input;


	for (int i = 0; i < input.length(); i++)
	{
		conversionInt[input.length() - 1 - i] = input[i] - '0';
		//\0‚ðœ‚¢‚½Œ…”•ª‚©‚ç‹tŒü‚«‚É“ü‚ê‚Ä‚¢‚­
	}
}
int main()
{
	int inputTotal[Digits] = { 0 };
	Input(inputTotal);

	int inputNow[Digits] = { 0 };
	Input(inputNow);

	int moveup = 0;
	for (int i = 0; i < Digits; i++)
	{
		if (inputTotal[i] + inputNow[i] > 9)
		{
			inputTotal[i] = inputTotal[i] + inputNow[i] - 10;
			inputTotal[i + 1]++;
		}
		else
		{
			inputTotal[i] = inputTotal[i] + inputNow[i];
		}
	}
	bool displayfrag = false;
	for (int i = Digits - 1; i >= 0; i--)
	{
		if (inputTotal[i] != 0)
			displayfrag = true;
		if (displayfrag)
			cout << inputTotal[i];
	}
}