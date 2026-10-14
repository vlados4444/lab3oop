/**
 * @file Polynomial.cpp
 * @brief Реализация класса Polynomial.
 */

#include "Polynomial.h"
#include <stdexcept>

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

// ==================== Унарные операции ====================

Polynomial& Polynomial::operator++()       { ++a; ++b; ++c; return *this; }
Polynomial Polynomial::operator++(int)     { Polynomial t(*this); ++(*this); return t; }
Polynomial& Polynomial::operator--()       { --a; --b; --c; return *this; }
Polynomial Polynomial::operator--(int)     { Polynomial t(*this); --(*this); return t; }

// ==================== Операции присваивания ====================

Polynomial& Polynomial::operator+=(const Polynomial& other)
{
    a += other.a; b += other.b; c += other.c;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other)
{
    a -= other.a; b -= other.b; c -= other.c;
    return *this;
}

Polynomial& Polynomial::operator*=(double k)
{
    a *= k; b *= k; c *= k;
    return *this;
}

Polynomial& Polynomial::operator/=(double k)
{
    if (k == 0.0)
        throw std::invalid_argument("Polynomial::operator/=: деление на ноль");
    a /= k; b /= k; c /= k;
    return *this;
}

// ==================== Бинарные операции ====================

/**
 * @brief Сложение двух полиномов.
 * Реализовано через operator+=, как требует задание.
 * @param lhs Левый операнд (копия — чтобы изменить и вернуть).
 * @param rhs Правый операнд.
 * @return Новый полином — сумма lhs и rhs.
 */
Polynomial operator+(Polynomial lhs, const Polynomial& rhs)
{
    lhs += rhs;
    return lhs;
}

/**
 * @brief Вычитание двух полиномов через operator-=.
 */
Polynomial operator-(Polynomial lhs, const Polynomial& rhs)
{
    lhs -= rhs;
    return lhs;
}

/**
 * @brief Умножение полинома на число через operator*=.
 */
Polynomial operator*(Polynomial lhs, double k)
{
    lhs *= k;
    return lhs;
}

/**
 * @brief Деление полинома на число через operator/=.
 * @throw std::invalid_argument Если k == 0.
 */
Polynomial operator/(Polynomial lhs, double k)
{
    lhs /= k;
    return lhs;
}

// ==================== Заглушки ====================

double Polynomial::getA() const { return a; }
double Polynomial::getB() const { return b; }
double Polynomial::getC() const { return c; }
int Polynomial::getRootsCallCount() { return rootsCallCount; }
double Polynomial::evaluate(double) const { return 0.0; }

bool operator<(const Polynomial&, const Polynomial&) { return false; }
bool operator>(const Polynomial&, const Polynomial&) { return false; }
bool operator<=(const Polynomial&, const Polynomial&) { return false; }
bool operator>=(const Polynomial&, const Polynomial&) { return false; }
bool operator==(const Polynomial&, const Polynomial&) { return false; }
bool operator!=(const Polynomial&, const Polynomial&) { return false; }

void Polynomial::print() const {}
void Polynomial::findRoots() const {}