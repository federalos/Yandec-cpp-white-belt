#include <iostream>

using namespace std;

int Least_common_multiple(int a, int b){
	if (a < 0){
		a = -a;
	}
	if (b < 0){
		b = -b;
	}
	
	while (a > 0 && b > 0){
		if(a > b){
			a = a % b;
		} else {
			b = b % a;
		}
	}
	return a + b;
}

class Rational{
	public:
		Rational(){
			// Реализуйте конструктор по умолчанию
			p = 0;
			q = 1;
		}

		Rational(int numerator, int denominator){
			// Реализуйте конструктор
			int LCM = Least_common_multiple(numerator, denominator);
			
			if (denominator == 0){
				p = numerator;
				q = 1;
			} else{
				if (denominator < 0){
					p = -numerator/LCM;
					q = -denominator/LCM;
				} else{
					p = numerator/LCM;
					q = denominator/LCM;
				}
			}
		}

		int Numerator() const{
			// Реализуйте этот метод
			return p;
		}

		int Denominator() const{
			// Реализуйте этот метод
			return q;
		}
	private:
		// Добавьте поля
		int p; // numerator
		int q; // denominator

};

int main(){
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10){
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3){
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3){
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3){
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1){
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1){
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}
	cout << "OK" << endl;
	return 0;
}