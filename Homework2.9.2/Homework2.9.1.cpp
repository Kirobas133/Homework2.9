#include <iostream>
#include <ostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	void NOM (Fraction& frac) {
		int temp1, temp2;
		//temp2 =
		//https://www.cyberforum.ru/cpp-beginners/thread704279.html
		if (frac.numerator_ < frac.denominator_) {
			int temp3;
			temp3 = frac.numerator_;
			frac.numerator_ = frac.denominator_;
			frac.denominator_ = temp3;
		}
		while (temp1 = frac.numerator_ % frac.denominator_) {
			frac.numerator_ = frac.denominator_;
			frac.denominator_ = temp1;
		}
	}
	Fraction() {
		numerator_ = 1;
		denominator_ = 1;
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	void operator = (Fraction& right) {
		this->numerator_ = right.numerator_;
		this->denominator_ = right.denominator_;
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
	Fraction& operator + (Fraction& right) {
		int numerator_new, denominator_new;
		numerator_new = this->numerator_ * right.denominator_ + right.numerator_ * this->denominator_;
		denominator_new = this->denominator_ * right.denominator_;
		this->numerator_ = numerator_new;
		this->denominator_ = denominator_new;
		NOM(*this);
		return *this;
	}
	friend std::ostream& operator << (std:: ostream& out, Fraction& right);
};
std::ostream& operator << (std::ostream& out, Fraction& right) {
	std::cout << right.numerator_ << "/" << right.denominator_;
	return out;
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);
	std::cout << (f1 + f2) << "\n";

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}