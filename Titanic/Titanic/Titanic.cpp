#include <iostream>
#include <cmath>

using namespace std;

// Определение констант.
const double PI = 3.14159265358979323846;
const double EARTH_DIAMETR = 6875;

struct position
{
	double x, y, z;
};
// Структуры позицый коробля и айсберга.
position ship, iceberg;

// Углы между началом координат и координатами объекта.
double angle1, angle2;

// Нахождение координат объектов.
void objectCoord(int, int, int, char[10], int, int, int, char[10], int);

// Функция нахождения линейного растояния между короблем и айсбергом.
double dis(double a, double b, double c, double d, double e, double f)
{
	a -= d;
	b -= e;
	c -= f;
	return sqrt(a*a + b*b + c*c);
}

void main()
{
	// Широта коробля.
	int latitudeDegS;
	int latitudeMinS;
	int latitudeSecS;
	// Для хранения буквенного обознчения.
	char latitudeS[10];

	// Долгота коробля
	int longitudeDegS;
	int longitudeMinS;
	int longitudeSecS;
	// Для хранения буквенного обознчения.
	char longitudeS[10];

	// Широта айсберга.
	int latitudeDegI;
	int latitudeMinI;
	int latitudeSecI;
	// Для хранения буквенного обознчения.
	char latitudeI[10];

	// Долгота айсберга.
	int longitudeDegI;
	int longitudeMinI;
	int longitudeSecI;
	// Для хранения буквенного обознчения.
	char longitudeI[10];

	char str[10000];

	// Ввод данных.
	for (int i = 1; i <= 3; ++i) gets_s(str);
	scanf_s("%d^%d'%d\" %s\n", &latitudeDegS, &latitudeMinS, &latitudeSecS, &latitudeS);
	//gets_s(str);  // На таймусе с этим не проходит, а для запуска в visual studio они нужны.
	scanf_s("and %d^%d'%d\" %s\n", &longitudeDegS, &longitudeMinS, &longitudeSecS, &longitudeS);
	gets_s(str);
	//gets_s(str);
	scanf_s("%d^%d'%d\" %s\n", &latitudeDegI, &latitudeMinI, &latitudeSecI, &latitudeI);
	//gets_s(str);
	scanf_s("and %d^%d'%d\" %s\n", &longitudeDegI, &longitudeMinI, &longitudeSecI, &longitudeI);
	gets_s(str);

	objectCoord(latitudeDegS, latitudeMinS, latitudeSecS, latitudeS, longitudeDegS, longitudeMinS, longitudeSecS, longitudeS, 1);
	objectCoord(latitudeDegI, latitudeMinI, latitudeSecI, latitudeI, longitudeDegI, longitudeMinI, longitudeSecI, longitudeI, 2);

	// Нахождение линейной дистанции.
	double linedis = dis(ship.x, ship.y, ship.z, iceberg.x, iceberg.y, iceberg.z);
	// Нахождение линейной дистанции.
	double ans = asin(linedis / EARTH_DIAMETR) * 2;
	ans = ans * EARTH_DIAMETR / 2;

	// Вывод результата с точностью до 2-х знаков после запятой.
	cout << ("The distance to the iceberg: ");
	cout.precision(2);
	cout << fixed;
	cout << ans;
	cout << " miles." << endl;
	if (100.00 - ans > 0.005) cout << ("DANGER!");
	getchar();
}

// Функция нахождения координат объекта.
void objectCoord(int latitudeDeg, int latitudeMin, int latitudeSec, char latitude[10], int longitudeDeg, int longitudeMin, int longitudeSec, char longitude[10], int trig)
{
	// Нахождение угла широты.
	angle1 = latitudeDeg * 3600 + latitudeMin * 60.0 + latitudeSec;
	angle1 /= 3600.0 * 180;
	angle1 *= PI;
	if (latitude[0] == 'S') angle1 = -angle1;

	// Нахождение угла долготы.
	angle2 = longitudeDeg * 3600 + longitudeMin * 60.0 + longitudeSec;
	angle2 /= 3600.0 * 180;
	angle2 *= PI;
	if (longitude[0] == 'W') angle2 = -angle2;
	// Нахождение координат коробля.
	if (trig == 1)
	{
		ship.x = EARTH_DIAMETR / 2 * cos(angle1)*cos(angle2);
		ship.y = EARTH_DIAMETR / 2 * cos(angle1)*sin(angle2);
		ship.z = EARTH_DIAMETR / 2 * sin(angle1);
	}
	// Нахождение координат айсберга.
	else if (trig == 2)
	{
		iceberg.x = EARTH_DIAMETR / 2 * cos(angle1)*cos(angle2);
		iceberg.y = EARTH_DIAMETR / 2 * cos(angle1)*sin(angle2);
		iceberg.z = EARTH_DIAMETR / 2 * sin(angle1);
	}
}