#include <iostream>
using namespace std;

class Rnum {
private:
  int p;
  int q;

public:
  Rnum operator/(const Rnum &obj) {
    Rnum temp;
    temp.p = p * obj.q;
    temp.q = q * obj.p;
    simplify(temp);
    return temp;
  }

  Rnum operator+(const Rnum &obj) {
    Rnum temp;
    temp.p = (p * obj.q) + (obj.p * q);
    temp.q = q * obj.q;
    simplify(temp);
    return temp;
  }

  Rnum operator-(const Rnum &obj) {
    Rnum temp;
    temp.p = (p * obj.q) - (obj.p * q);
    temp.q = q * obj.q;
    if (temp.p == 0) {
      temp.q = 0;
    }
    simplify(temp);
    return temp;
  }

  Rnum operator*(const Rnum &obj) {
    Rnum temp;
    temp.p = p * obj.p;
    temp.q = q * obj.q;
    simplify(temp);
    return temp;
  }

  // pre

  void operator++() {
    p++;
    q++;
  }

  // post
  void operator++(int) {
    ++p;
    ++q;
  }

  void operator=(const Rnum &obj) {
    p = obj.p;
    q = obj.q;
  }

  bool operator==(const Rnum &obj) {
    if (p == obj.p && q == obj.q)
      return 1;
    else
      return 0;
  }

  bool operator!=(const Rnum &obj) {
    if (p == obj.p && q == obj.q)
      return 0;
    else
      return 1;
  }

  bool operator<(const Rnum &obj) {
    if ( (p / q) < (obj.p / obj.q))
      return 1;
    else
      return 0;
  }

  bool operator>(const Rnum &obj) {
    if ((p / q) > (obj.p / obj.q))
      return 1;
    else
      return 0;
  }
  void simplify(Rnum &obj) {
    int i = 2;
    while (i <= obj.p && i <= obj.q) {
      if (obj.p % i == 0 && obj.q % i == 0) {
        obj.p = obj.p / i;
        obj.q = obj.q / i;
      } else
        i++;
    }
  }

  friend ostream &operator<<(ostream &out, const Rnum &obj) {
    out << obj.p << "/" << obj.q;
    return out;
  }

  friend istream &operator>>(istream &in, Rnum &obj)

  {

    cout << "enter numerator: ";
    in >> obj.p;
    cout << "enter denominator: ";
    in >> obj.q;
    while (obj.q == 0) {
      cout << "the denominator cannot be zero" << endl;
      cout << "enter again: " << endl;
      in >> obj.q;
    }
    return in;
  }
};

int main() {
  system("cls");
  Rnum n1;
  Rnum n2;

  cout << "First number: " << endl;
  cin >> n1;
  cout << "------------the number is: " << n1 << endl;
  cout << "\nSecond Number: " << endl;
  cin >> n2;
  cout << "------------the number is: " << n2 << endl<<endl;

  if (n1 > n2)
    cout << "first number is greater" << endl;
  else if (n1 < n2)
    cout << "second number is greater" << endl;
  else
    cout << "they are equal" << endl;
  cout << "\ntheir division: " << n1 / n2 << endl;
  cout << "their sum: " << n1 + n2 << endl;
  cout << "their difference: " << n1 - n2 << endl;
  cout << "their product: " << n1 * n2 << endl<<endl;


  ++n1;
  n2++;
  cout << "first number after incrementing: " << n1 << endl;
  cout << "second number after incrementing: " << n2 << endl<<endl;
  return 0;
}