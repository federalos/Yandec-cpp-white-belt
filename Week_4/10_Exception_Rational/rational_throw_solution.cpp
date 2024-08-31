#include <iostream>
#include <exception>

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
        } 
        else {
            b = b % a;
        }
	}
	return a + b;
}

class Rational{
	// Вставьте сюда реализацию класса Rational
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

				throw invalid_argument("denominator is 0");
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

// Вставьте сюда реализацию operator / для класса Rational
bool operator==(const Rational& lhs, const Rational& rhs){
	return lhs.Numerator()*rhs.Denominator() == rhs.Numerator()*lhs.Denominator(); 
}
Rational operator+(const Rational& lhs, const Rational& rhs){
	return Rational {lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator() , rhs.Denominator()*lhs.Denominator()}; 
}
Rational operator-(const Rational& lhs, const Rational& rhs){
	return Rational {lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator() , rhs.Denominator()*lhs.Denominator()}; 
}
Rational operator*(const Rational& lhs, const Rational& rhs){
	return Rational {lhs.Numerator()*rhs.Numerator(), lhs.Denominator()*rhs.Denominator()};
} 

Rational operator/(const Rational& lhs, const Rational& rhs){
    if (rhs.Numerator() == 0){
        throw domain_error("Division by zero");
    }
	return Rational {lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator()};
}
ostream& operator<<(ostream& stream, const Rational& rational){
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}
bool operator>(const Rational& lhs, const Rational& rhs){
	return lhs.Numerator()*rhs.Denominator() > rhs.Numerator()*lhs.Denominator(); 
}
bool operator<(const Rational& lhs, const Rational& rhs){
	return lhs.Numerator()*rhs.Denominator() < rhs.Numerator()*lhs.Denominator(); 
}

istream& operator>>(istream& stream, Rational& rational){
    int p,q;
    char operation;
    if ((stream >> p && stream >> operation && stream >> q) && (operation == '/')){
        rational = Rational(p,q);
    }
    return stream;
}

int main(){
	try{
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument& inv_arg){
        cout << inv_arg.what() << endl;
	}
	try{
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error& dom_e){
        cout << dom_e.what() << endl;
	}
	cout << "OK" << endl;
	return 0;
}