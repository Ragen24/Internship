#include <iostream>
#include <bitset>
#include <vector>
#include <intrin.h>

using namespace std;

void getDiff();                // ������� ���������� ����������� �������� ����� ���.

int stonesQuantity;            // ���������� ������.
int weight = 0;                // ��� ���� ������.
int weightL = 0;               // ��� ����� ����.
int targetWeight = 0;          // ������� ��� ����(����� ����� ������ �������).
int bestDiff = 100000;         // ���������� �������� ���� ���� ���.
int sumDiff;                   // �������� ���� ���� ���.
bitset<20> mask;               // �������� ����� ��� ������������� ������ (0-�����, 1-������).
vector<int> vecStones;         // ������ ��� �������� ���� ������.

int main()
{
	int stream;                // ���� ���� ������.

	// ���� ���������� ������.
	cin >> stonesQuantity;

	// ���� ���� ������ � ���������� �� ������ ����.
	for (int i = 0; i < stonesQuantity; i++)
	{
		cin >> stream, vecStones.push_back(stream);
		weight += vecStones[i];
	}

	// ����� ������� ���������� ��������.
	getDiff();

	// ����� ���������� �������.
	cout << sumDiff;
}

void getDiff()
{
	// ���������� ��������.
	const unsigned int nIterations = 1 << stonesQuantity;

	weightL = weight;
	// ����������� �������� ����.
	targetWeight = weightL / 2 + weightL % 2;

	// ���� �������� ���������� ������.
	for (unsigned int i = 1; i < nIterations; ++i)
	{
		unsigned long position;
		_BitScanForward(&position, i);
		// ������������� ���� ������.
		mask[position] = !mask[position];

		// ��������� ����� ����� ���� ��� �������������� ������.
		if (mask[position])
		{
			weightL -= vecStones[position];
		}
		else
		{
			weightL += vecStones[position];
		}

		// ��������� ������ �������, ���� ������� ����� �����������.
		if (targetWeight - weightL <= bestDiff && targetWeight - weightL >= 0)
		{
			bestDiff = targetWeight - weightL;
		}
	}

	// ���������� ������� ����� ������ ���� ���, �� ������ �������� � ������ �����.
	sumDiff = weight - (targetWeight - bestDiff);
	sumDiff = abs(sumDiff - (targetWeight - bestDiff));
}

