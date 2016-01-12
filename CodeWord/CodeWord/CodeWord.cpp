#include <iostream>
#include <string>

using namespace std;

void decrypt();             // Прототип функции дешифровки.

int sumPositionsOf1;        // Сумма позицый едениц(п.е.).
int quantityOf1;            // Сумма едениц.
int sumDiff;                // Разность между необходимой суммой п.е. и суммой п.е. исходного сообщения.
int wordLength;             // Длина слова.
string sourceWord;          // Исходное сообщение.
string decryptWord;         // Расшифрованное сообшение.

void main()
{
	cin >> wordLength;
	getchar();

	while (getline(cin, sourceWord))
	{
		// Вызов функции дешифровки.
		decrypt();
		// Вывод расшифрованного сообщения.
		cout << endl << decryptWord << endl;
	}
}

// Функция дешифровки.
void decrypt()
{
	quantityOf1 = 0;
	sumPositionsOf1 = 0;

	// Подсчет суммы позицый едениц.
	for (int i = 0; i < sourceWord.length(); ++i)
	{
		if (sourceWord[i] == '1')
		{
			sumPositionsOf1 += i + 1;
		}
	}

	// Нахождение разности сумм.
	sumDiff = (sumPositionsOf1 % (wordLength + 1));

	// Любой символ 0 заменен символом 1.
	if (sourceWord.length() == wordLength && sumDiff != 0)
	{
		sourceWord[sumDiff - 1] = '0';
		decryptWord = sourceWord;
	}
	// Любой сивол удален.
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
	// Дополнительный символ вствлен в любую позицию.
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
	// Введено не изменненое сообение.
	else
	{
		decryptWord = sourceWord;
	}
}