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
	// Вставьте сюда реализацию класса Rational из первой части
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

// Вставьте сюда реализацию operator == для класса Rational из второй части
bool operator==(const Rational& lhs, const Rational& rhs){
	return lhs.Numerator()*rhs.Denominator() == rhs.Numerator()*lhs.Denominator(); 

}

Rational operator+(const Rational& lhs, const Rational& rhs){
	return Rational {lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator() , rhs.Denominator()*lhs.Denominator()}; 
}

Rational operator-(const Rational& lhs, const Rational& rhs){
	return Rational {lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator() , rhs.Denominator()*lhs.Denominator()}; 
}

// Реализуйте для класса Rational операторы * и /

Rational operator*(const Rational& lhs, const Rational& rhs){
	return Rational {lhs.Numerator()*rhs.Numerator(), lhs.Denominator()*rhs.Denominator()};
} 

Rational operator/(const Rational& lhs, const Rational& rhs){
	return Rational {lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator()};
} 	

int main(){
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal){
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal){
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}
	cout << "OK" << endl;
	return 0;
}