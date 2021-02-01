#pragma once
/**
zaiplementowane przeci��enie operator�w
*/
class Point
{
public:
	Point(int x_, int y_) :
		x{x_},
		y{y_}
	{}

	// przeciazenie operatora <
	bool operator < (int other)
	{
		return value < other;
	}

	// przeciazenie operatora ++
	void operator++()
	{
		++value;
	}

	// przeciazenie operatora ==
	bool operator == (int other)
	{
		return value == other;
	}

	// przeciazenie operatora =
	void operator = (int other)
	{
		value = other;
	}

	int x; // wspolrzedna x
	int y; // wspolrzedna y
	int value{ 0 }; // wartosc
};

