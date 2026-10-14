/**
 * @file Polynomial.cpp
 * @brief Реализация класса Polynomial.
 */

#include "Polynomial.h"

/**
 * @brief Статический счётчик вызовов findRoots().
 */
int Polynomial::rootsCallCount = 0;

// ==================== Конструкторы ====================

Polynomial::Polynomial()
    : a(0.0), b(0.0), c(0.0)
{
    std::cout << "[Polynomial] Создан по умолчанию: 0x^2 + 0x + 0\n";
}

Polynomial::Polynomial(double a, double b, double c)
    : a(a), b(b), c(c)
{
    std::cout << "[Polynomial] Создан: " << a << "x^2 + "
              << b << "x + " << c << "\n";
}

Polynomial::Polynomial(const Polynomial& other)
    : a(other.a), b(other.b), c(other.c)
{
    std::cout << "[Polynomial] Скопирован: " << a << "x^2 + "
              << b << "x + " << c << "\n";
}

Polynomial::~Polynomial()
{
    std::cout << "[~Polynomial] Уничтожен: " << a << "x^2 + "
              << b << "x + " << c << "\n";
}

// ==================== Заглушки ====================

double Polynomial::getA() const { return a; }
double Polynomial::getB() const { return b; }
double Polynomial::getC() const { return c; }
int Polynomial::getRootsCallCount() { return rootsCallCount; }
double Polynomial::evaluate(double) const { return 0.0; }

Polynomial& Polynomial::operator++() { return *this; }
Polynomial Polynomial::operator++(int) { return *this; }
Polynomial& Polynomial::operator--() { return *this; }
Polynomial Polynomial::operator--(int) { return *this; }

Polynomial& Polynomial::operator+=(const Polynomial&) { return *this; }
Polynomial& Polynomial::operator-=(const Polynomial&) { return *this; }
Polynomial& Polynomial::operator*=(double) { return *this; }
Polynomial& Polynomial::operator/=(double) { return *this; }

Polynomial operator+(Polynomial lhs, const Polynomial&) { return lhs; }
Polynomial operator-(Polynomial lhs, const Polynomial&) { return lhs; }
Polynomial operator*(Polynomial lhs, double) { return lhs; }
Polynomial operator/(Polynomial lhs, double) { return lhs; }

bool operator<(const Polynomial&, const Polynomial&) { return false; }
bool operator>(const Polynomial&, const Polynomial&) { return false; }
bool operator<=(const Polynomial&, const Polynomial&) { return false; }
bool operator>=(const Polynomial&, const Polynomial&) { return false; }
bool operator==(const Polynomial&, const Polynomial&) { return false; }
bool operator!=(const Polynomial&, const Polynomial&) { return false; }

void Polynomial::print() const {}
void Polynomial::findRoots() const {}