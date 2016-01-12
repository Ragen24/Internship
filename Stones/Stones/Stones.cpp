#include <iostream>
#include <bitset>
#include <vector>
#include <intrin.h>

using namespace std;

void getDiff();                // Функция нахождения минимальной разности весов куч.

int stonesQuantity;            // Количество камней.
int weight = 0;                // Вес всех камней.
int weightL = 0;               // Вес левой кучи.
int targetWeight = 0;          // Целевой вес кучи(чтобы через рюкзак сделать).
int bestDiff = 100000;         // Наименьшая разность сумм двух куч.
int sumDiff;                   // Разность масс двух куч.
bitset<20> mask;               // Двоичное число для распределения камней (0-левая, 1-правая).
vector<int> vecStones;         // Вектор для хранения масс камней.

int main()
{
	int stream;                // Ввод масс камней.

	// Ввод количества камней.
	cin >> stonesQuantity;

	// Ввод масс камней и нахождение их общего веса.
	for (int i = 0; i < stonesQuantity; i++)
	{
		cin >> stream, vecStones.push_back(stream);
		weight += vecStones[i];
	}

	// Вызов функции нахождения разности.
	getDiff();

	// Вывод наименьшей разницы.
	cout << sumDiff;
}

void getDiff()
{
	// Количество итераций.
	const unsigned int nIterations = 1 << stonesQuantity;

	weightL = weight;
	// Определение целевого веса.
	targetWeight = weightL / 2 + weightL % 2;

	// Цикл перебора комбинаций камней.
	for (unsigned int i = 1; i < nIterations; ++i)
	{
		unsigned long position;
		_BitScanForward(&position, i);
		// Перекладывает один камень.
		mask[position] = !mask[position];

		// Изменение массы левой кучи при перекладывании камней.
		if (mask[position])
		{
			weightL -= vecStones[position];
		}
		else
		{
			weightL += vecStones[position];
		}

		// Изменение лучшей разницы, если найдина более оптимальная.
		if (targetWeight - weightL <= bestDiff && targetWeight - weightL >= 0)
		{
			bestDiff = targetWeight - weightL;
		}
	}

	// Нахождение разницы между весами двух куч, на основе целевого и общего весов.
	sumDiff = weight - (targetWeight - bestDiff);
	sumDiff = abs(sumDiff - (targetWeight - bestDiff));
}

