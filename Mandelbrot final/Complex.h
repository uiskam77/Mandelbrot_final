#pragma once

struct Complex {
	Complex(double a_, double b_) :
		a{ a_ },
		b{ b_ }
	{}

	// przeciazenie operatora *
	Complex operator* (Complex other)
	{
		auto newA = this->a * other.a - this->b * other.b;
		auto newB = this->a * other.b + this->b * other.a;
		return Complex(newA, newB);
	}

	// przeciazenie operatora +
	Complex operator+ (Complex other)
	{
		auto newA = this->a + other.a;
		auto newB = this->b + other.b;
		return Complex(newA, newB);
	}

	// przeciazenie operatora () (do sprawdzenia czy || z liczby jest wieksze od 2
	bool operator()()
	{
		return a + b > 2 ? false : true;
	}

	double a;
	double b;
};

