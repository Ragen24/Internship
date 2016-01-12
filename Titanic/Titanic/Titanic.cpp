#include <iostream>
#include <cmath>

using namespace std;

// ����������� ��������.
const double PI = 3.14159265358979323846;
const double EARTH_DIAMETR = 6875;

struct position
{
	double x, y, z;
};
// ��������� ������� ������� � ��������.
position ship, iceberg;

// ���� ����� ������� ��������� � ������������ �������.
double angle1, angle2;

// ���������� ��������� ��������.
void objectCoord(int, int, int, char[10], int, int, int, char[10], int);

// ������� ���������� ��������� ��������� ����� �������� � ���������.
double dis(double a, double b, double c, double d, double e, double f)
{
	a -= d;
	b -= e;
	c -= f;
	return sqrt(a*a + b*b + c*c);
}

void main()
{
	// ������ �������.
	int latitudeDegS;
	int latitudeMinS;
	int latitudeSecS;
	// ��� �������� ���������� ����������.
	char latitudeS[10];

	// ������� �������
	int longitudeDegS;
	int longitudeMinS;
	int longitudeSecS;
	// ��� �������� ���������� ����������.
	char longitudeS[10];

	// ������ ��������.
	int latitudeDegI;
	int latitudeMinI;
	int latitudeSecI;
	// ��� �������� ���������� ����������.
	char latitudeI[10];

	// ������� ��������.
	int longitudeDegI;
	int longitudeMinI;
	int longitudeSecI;
	// ��� �������� ���������� ����������.
	char longitudeI[10];

	char str[10000];

	// ���� ������.
	for (int i = 1; i <= 3; ++i) gets_s(str);
	scanf_s("%d^%d'%d\" %s\n", &latitudeDegS, &latitudeMinS, &latitudeSecS, &latitudeS);
	//gets_s(str);  // �� ������� � ���� �� ��������, � ��� ������� � visual studio ��� �����.
	scanf_s("and %d^%d'%d\" %s\n", &longitudeDegS, &longitudeMinS, &longitudeSecS, &longitudeS);
	gets_s(str);
	//gets_s(str);
	scanf_s("%d^%d'%d\" %s\n", &latitudeDegI, &latitudeMinI, &latitudeSecI, &latitudeI);
	//gets_s(str);
	scanf_s("and %d^%d'%d\" %s\n", &longitudeDegI, &longitudeMinI, &longitudeSecI, &longitudeI);
	gets_s(str);

	objectCoord(latitudeDegS, latitudeMinS, latitudeSecS, latitudeS, longitudeDegS, longitudeMinS, longitudeSecS, longitudeS, 1);
	objectCoord(latitudeDegI, latitudeMinI, latitudeSecI, latitudeI, longitudeDegI, longitudeMinI, longitudeSecI, longitudeI, 2);

	// ���������� �������� ���������.
	double linedis = dis(ship.x, ship.y, ship.z, iceberg.x, iceberg.y, iceberg.z);
	// ���������� �������� ���������.
	double ans = asin(linedis / EARTH_DIAMETR) * 2;
	ans = ans * EARTH_DIAMETR / 2;

	// ����� ���������� � ��������� �� 2-� ������ ����� �������.
	cout << ("The distance to the iceberg: ");
	cout.precision(2);
	cout << fixed;
	cout << ans;
	cout << " miles." << endl;
	if (100.00 - ans > 0.005) cout << ("DANGER!");
	getchar();
}

// ������� ���������� ��������� �������.
void objectCoord(int latitudeDeg, int latitudeMin, int latitudeSec, char latitude[10], int longitudeDeg, int longitudeMin, int longitudeSec, char longitude[10], int trig)
{
	// ���������� ���� ������.
	angle1 = latitudeDeg * 3600 + latitudeMin * 60.0 + latitudeSec;
	angle1 /= 3600.0 * 180;
	angle1 *= PI;
	if (latitude[0] == 'S') angle1 = -angle1;

	// ���������� ���� �������.
	angle2 = longitudeDeg * 3600 + longitudeMin * 60.0 + longitudeSec;
	angle2 /= 3600.0 * 180;
	angle2 *= PI;
	if (longitude[0] == 'W') angle2 = -angle2;
	// ���������� ��������� �������.
	if (trig == 1)
	{
		ship.x = EARTH_DIAMETR / 2 * cos(angle1)*cos(angle2);
		ship.y = EARTH_DIAMETR / 2 * cos(angle1)*sin(angle2);
		ship.z = EARTH_DIAMETR / 2 * sin(angle1);
	}
	// ���������� ��������� ��������.
	else if (trig == 2)
	{
		iceberg.x = EARTH_DIAMETR / 2 * cos(angle1)*cos(angle2);
		iceberg.y = EARTH_DIAMETR / 2 * cos(angle1)*sin(angle2);
		iceberg.z = EARTH_DIAMETR / 2 * sin(angle1);
	}
}