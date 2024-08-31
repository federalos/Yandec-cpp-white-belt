#include <iostream>
#include <map>
#include <set>
#include <vector>

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
// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
bool operator>(const Rational& lhs, const Rational& rhs){
	return lhs.Numerator()*rhs.Denominator() > rhs.Numerator()*lhs.Denominator(); 
}
bool operator<(const Rational& lhs, const Rational& rhs){
	return lhs.Numerator()*rhs.Denominator() < rhs.Numerator()*lhs.Denominator(); 
}

int main(){
	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3){
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs){
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }})
		{
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2){
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}
	cout << "OK" << endl;
	return 0;
}