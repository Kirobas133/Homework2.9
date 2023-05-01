#include <iostream>


class Fraction
{
private:
	int numerator_;
	int denominator_;
	void NOM (Fraction& frac) {
		int num, denom, ad;
		num = abs(frac.numerator_);
		denom = abs(frac.denominator_);		
		if (num < denom) {
			int temp2;
			temp2 = num;
			num = denom;
			denom = temp2;
		}
		while (denom > 0) {
			ad = num % denom;
			num = denom;
			denom = ad;
		}
		Fraction temp((frac.numerator_ / num), (frac.denominator_ / num));
		frac = temp;
	}

public:
	Fraction(int numerator = 1, int denominator = 1)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction(const Fraction& fr) {
		numerator_ = fr.numerator_;
		denominator_ = fr.denominator_;
	}
	Fraction& operator = (const Fraction& right) {
		this->numerator_ = right.numerator_;
		this->denominator_ = right.denominator_;
		return *this;
	}
	bool operator == (Fraction other) {
		return ((this->numerator_* other.denominator_) == (other.numerator_ * this->denominator_));
	}
	bool operator != (Fraction other) {
		return ((this->numerator_ * other.denominator_) != (other.numerator_ * this->denominator_));
	}
	bool operator < (Fraction other) {
		return ((this->numerator_ * other.denominator_) < (other.numerator_ * this->denominator_));
	}
	bool operator > (Fraction other) {
		return ((this->numerator_ * other.denominator_) > (other.numerator_ * this->denominator_));
	}
	bool operator <= (Fraction other) {
		return ((this->numerator_ * other.denominator_) <= (other.numerator_ * this->denominator_));
	}
	bool operator >= (Fraction other) {
		return ((this->numerator_ * other.denominator_) >= (other.numerator_ * this->denominator_));
	}
	Fraction operator + (Fraction& right) {
		int numerator_new, denominator_new;
		numerator_new = this->numerator_ * right.denominator_ + right.numerator_ * this->denominator_;
		denominator_new = this->denominator_ * right.denominator_;
		Fraction frac(numerator_new, denominator_new);
		NOM(frac);
		return frac;
	}
	Fraction operator - (Fraction& right) {
		int numerator_new, denominator_new;
		numerator_new = this->numerator_ * right.denominator_ - right.numerator_ * this->denominator_;
		denominator_new = this->denominator_ * right.denominator_;
		Fraction frac(numerator_new, denominator_new);
		NOM(frac);
		return frac;
	}
	Fraction operator * (Fraction& right) {
		int numerator_new, denominator_new;
		numerator_new = this->numerator_ * right.numerator_;
		denominator_new = this->denominator_ * right.denominator_;
		Fraction frac(numerator_new, denominator_new);
		NOM(frac);
		return frac;
	}
	Fraction operator / (Fraction& right) {
		int numerator_new, denominator_new;
		numerator_new = this->numerator_ * right.denominator_;
		denominator_new = this->denominator_ * right.numerator_;
		Fraction frac(numerator_new, denominator_new);
		NOM(frac);
		return frac;
	}
	Fraction& operator ++ () {
		numerator_ = numerator_ + denominator_;
		NOM(*this);
		return *this;
		
}
	Fraction& operator ++ (int) {
		numerator_ = numerator_ + denominator_;
		NOM(*this);
		return *this;
	}
	Fraction& operator -- () {
		this->numerator_ = numerator_ - denominator_;
		NOM(*this);
		return *this;
	}
	Fraction& operator -- (int) {
		this->numerator_ = this->numerator_ - this->denominator_;
		NOM(*this);
		return *this;
	}
	Fraction operator - () {
		Fraction f(-numerator_, denominator_);
		return f;
	}

	friend std::ostream& operator << (std:: ostream& out, Fraction& right);
};
std::ostream& operator << (std::ostream& out, Fraction& right) {
	std::cout << right.numerator_ << "/" << right.denominator_;
	return out;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> b;
	Fraction f1(a, b);

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> b;
	Fraction f2(a, b);
	Fraction f3;
	Fraction temp;

	f3 = f1 + f2;
	std::cout << f1 << " + " << f2 << " = " << f3 << std::endl;
	f3 = f1 - f2;
	std::cout << f1 << " - " << f2 << " = " << f3 << std::endl;
	f3 = f1 * f2;
	std::cout << f1 << " * " << f2 << " = " << f3 << std::endl;
	f3 = f1 / f2;
	std::cout << f1 << " / " << f2 << " = " << f3 << std::endl;
	std::cout << "++" << f1 << " * " << f2 << " = ";
	f3 = (++f1)* f2;
	std::cout << f3 << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl;
	std::cout << f1 << "--" << " * " << f2 << " = ";
	f3 = (f1--) * f2;
	std::cout << f3 << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl;

	/*std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';*/
	return 0;
}