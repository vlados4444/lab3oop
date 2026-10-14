/**
 * @file Polynomial.cpp
 * @brief Реализация класса Polynomial.
 */

#include "Polynomial.h"
#include <stdexcept>
#include <cmath>

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

Polynomial operator+(Polynomial lhs, const Polynomial& rhs) { lhs += rhs; return lhs; }
Polynomial operator-(Polynomial lhs, const Polynomial& rhs) { lhs -= rhs; return lhs; }
Polynomial operator*(Polynomial lhs, double k)             { lhs *= k;   return lhs; }
Polynomial operator/(Polynomial lhs, double k)             { lhs /= k;   return lhs; }

// ==================== Операции сравнения ====================

bool operator<(const Polynomial& l, const Polynomial& r)  { return l.c < r.c; }
bool operator>(const Polynomial& l, const Polynomial& r)  { return l.c > r.c; }
bool operator<=(const Polynomial& l, const Polynomial& r) { return l.c <= r.c; }
bool operator>=(const Polynomial& l, const Polynomial& r) { return l.c >= r.c; }

bool operator==(const Polynomial& l, const Polynomial& r)
{
    return l.a == r.a && l.b == r.b && l.c == r.c;
}

bool operator!=(const Polynomial& l, const Polynomial& r)
{
    return !(l == r);
}

// ==================== Методы чтения ====================

double Polynomial::getA() const { return a; }
double Polynomial::getB() const { return b; }
double Polynomial::getC() const { return c; }
int Polynomial::getRootsCallCount() { return rootsCallCount; }

double Polynomial::evaluate(double x) const
{
    return a * x * x + b * x + c;
}

// ==================== Вывод ====================

void Polynomial::print() const
{
    std::cout << a << "x^2 + " << b << "x + " << c << "\n";
}

// ==================== Поиск корней ====================

void Polynomial::findRoots() const
{
    ++rootsCallCount;

    std::cout << "Поиск корней для ";
    print();

    if (a == 0.0)
    {
        if (b == 0.0)
        {
            std::cout << (c == 0.0
                ? "Бесконечно много решений\n"
                : "Нет решений\n");
        }
        else
        {
            std::cout << "Линейное уравнение, корень: x = " << -c / b << "\n";
        }
        return;
    }

    double d = b * b - 4 * a * c;
    std::cout << "Дискриминант D = " << d << "\n";

    if (d > 0)
    {
        double x1 = (-b + std::sqrt(d)) / (2 * a);
        double x2 = (-b - std::sqrt(d)) / (2 * a);
        std::cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << "\n";
    }
    else if (d == 0)
    {
        std::cout << "Один корень: x = " << -b / (2 * a) << "\n";
    }
    else
    {
        std::cout << "Действительных корней нет (D < 0)\n";
    }
}