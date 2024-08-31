#include <iostream>
#include <sstream>

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

class Rational {
    // Insert your implementation of Rational class from 1st part here
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

// Insert your implementation of == operator for Rational class
// from 2nd task part here
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
	return Rational {lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator()};
}
ostream& operator<<(ostream& stream, const Rational& rational){
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational){
    int p,q;
    char operation;
    if ((stream >> p && stream >> operation && stream >> q) && (operation == '/')){
        rational = Rational(p,q);
    }
    return stream;
}

// Implement << and >> operators for Rational class

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct) {
            cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
            return 7;
        }
    }

    cout << "OK" << endl;
    return 0;
}
