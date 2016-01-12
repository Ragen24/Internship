#include <iostream>
#include <string>

using namespace std;

void decrypt();             // �������� ������� ����������.

int sumPositionsOf1;        // ����� ������� ������(�.�.).
int quantityOf1;            // ����� ������.
int sumDiff;                // �������� ����� ����������� ������ �.�. � ������ �.�. ��������� ���������.
int wordLength;             // ����� �����.
string sourceWord;          // �������� ���������.
string decryptWord;         // �������������� ���������.

void main()
{
	cin >> wordLength;
	getchar();

	while (getline(cin, sourceWord))
	{
		// ����� ������� ����������.
		decrypt();
		// ����� ��������������� ���������.
		cout << endl << decryptWord << endl;
	}
}

// ������� ����������.
void decrypt()
{
	quantityOf1 = 0;
	sumPositionsOf1 = 0;

	// ������� ����� ������� ������.
	for (int i = 0; i < sourceWord.length(); ++i)
	{
		if (sourceWord[i] == '1')
		{
			sumPositionsOf1 += i + 1;
		}
	}

	// ���������� �������� ����.
	sumDiff = (sumPositionsOf1 % (wordLength + 1));

	// ����� ������ 0 ������� �������� 1.
	if (sourceWord.length() == wordLength && sumDiff != 0)
	{
		sourceWord[sumDiff - 1] = '0';
		decryptWord = sourceWord;
	}
	// ����� ����� ������.
	else if (sourceWord.length() < wordLength)
	{
		if (sumDiff == 0)
		{
			decryptWord = sourceWord;
			decryptWord.insert(sourceWord.length(), "0");
		}
		else
		{
			for (int i = sourceWord.length(); i >= 0; --i)
			{
				if (((wordLength + 1) - sumDiff) == i + 1 + quantityOf1)
				{
					decryptWord = sourceWord;

					decryptWord.insert(i, "1");

					break;
				}
				if ((wordLength + 1 - sumDiff) == quantityOf1)
				{
					decryptWord = sourceWord;
					decryptWord.insert(i, "0");

					break;
				}

				if (sourceWord[i - 1] == '1')
					quantityOf1 += 1;
			}
		}
	}
	// �������������� ������ ������� � ����� �������.
	else if (sourceWord.length() > wordLength)
	{
		if (sourceWord[sourceWord.length() - 1] == '0' && sumDiff == 0)
		{
			decryptWord = sourceWord;
			decryptWord.erase(sourceWord.length() - 1, 1);
		}
		else
		{
			for (int i = sourceWord.length(); i >= 0; --i)
			{
				if (sumDiff == i + quantityOf1 || sumDiff == quantityOf1)
				{
					decryptWord = sourceWord;
					decryptWord.erase(i - 1, 1);
					break;
				}

				if (sourceWord[i - 1] == '1')
					quantityOf1 += 1;
			}
		}
	}
	// ������� �� ���������� ��������.
	else
	{
		decryptWord = sourceWord;
	}
}