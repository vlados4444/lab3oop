/**
 * @file Polynomial.h
 * @brief Заголовочный файл класса Polynomial — многочлен 2-й степени.
 * @author Твоё Имя
 * @date 14.10.2026
 *
 * Содержит объявление класса Polynomial, который представляет
 * многочлен вида ax² + bx + c и поддерживает полный набор
 * арифметических операций, операций сравнения и унарных операций.
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

/**
 * @brief Класс, описывающий многочлен второй степени ax² + bx + c.
 *
 * Класс представляет целостную математическую сущность — многочлен
 * второй степени. Поддерживает следующие группы операций:
 *
 *  - **Создание:** три конструктора (по умолчанию, параметризованный,
 *    копирования).
 *  - **Унарные операции:** префиксный и постфиксный инкремент,
 *    префиксный и постфиксный декремент.
 *  - **Присваивание:** `+=`, `-=`, `*=`, /=.
 *  - **Бинарные арифметические:** `+`, `-`, `*`, `/` — реализованы
 *    через соответствующие операции присваивания.
 *  - **Сравнение:** `<`, `>`, `<=`, `>=`, `==`, `!=` (по значению
 *    при x = 0, то есть по свободному члену c).
 *  - **Вычисления:** значение многочлена в точке, поиск корней.
 *
 * @section invariants Инварианты
 *  - Деление на ноль через `/=` отклоняется исключением.
 *  - Деление на полином с нулевыми коэффициентами запрещено.
 *
 * @section static_state Статическое состояние
 *  - `rootsCallCount` — счётчик вызовов findRoots() с момента
 *    запуска программы.
 */
class Polynomial
{
private:
    double a;   ///< Коэффициент при x².
    double b;   ///< Коэффициент при x.
    double c;   ///< Свободный член.

    /**
     * @brief Статический счётчик вызовов метода findRoots().
     *
     * Общий для всех объектов класса. Увеличивается при каждом
     * вызове findRoots() и никогда не сбрасывается.
     */
    static int rootsCallCount;

public:

    // ==================== Конструкторы ====================

    /**
     * @brief Конструктор по умолчанию.
     * @post Создаётся полином 0x² + 0x + 0.
     */
    Polynomial();

    /**
     * @brief Параметризованный конструктор.
     * @param a Коэффициент при x².
     * @param b Коэффициент при x.
     * @param c Свободный член.
     */
    Polynomial(double a, double b, double c);

    /**
     * @brief Конструктор копирования.
     * @param other Копируемый полином.
     */
    Polynomial(const Polynomial& other);

    /**
     * @brief Деструктор. Выводит сообщение об уничтожении.
     */
    ~Polynomial();

    // ==================== Методы чтения ====================

    /// @return Коэффициент a.
    double getA() const;

    /// @return Коэффициент b.
    double getB() const;

    /// @return Коэффициент c.
    double getC() const;

    /**
     * @brief Возвращает количество вызовов findRoots().
     * @return Значение статического счётчика.
     */
    static int getRootsCallCount();

    /**
     * @brief Вычисляет значение полинома в точке x.
     * @param x Значение аргумента.
     * @return a*x*x + b*x + c.
     */
    double evaluate(double x) const;

    // ==================== Унарные операции ====================

    /// @brief Префиксный ++: увеличивает коэффициенты на 1.
    Polynomial& operator++();

    /// @brief Постфиксный ++: возвращает копию, потом увеличивает.
    Polynomial operator++(int dummy);

    /// @brief Префиксный --: уменьшает коэффициенты на 1.
    Polynomial& operator--();

    /// @brief Постфиксный --: возвращает копию, потом уменьшает.
    Polynomial operator--(int dummy);

    // ==================== Операции присваивания ====================

    /// @brief Поэлементное сложение с другим полиномом.
    Polynomial& operator+=(const Polynomial& other);

    /// @brief Поэлементное вычитание другого полинома.
    Polynomial& operator-=(const Polynomial& other);

    /// @brief Умножение всех коэффициентов на число.
    Polynomial& operator*=(double k);

    /// @brief Деление всех коэффициентов на число (k != 0).
    Polynomial& operator/=(double k);

    // ==================== Бинарные операции ====================

    /// @brief Сложение двух полиномов (через +=).
    friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs);

    /// @brief Вычитание двух полиномов (через -=).
    friend Polynomial operator-(Polynomial lhs, const Polynomial& rhs);

    /// @brief Умножение полинома на число (через *=).
    friend Polynomial operator*(Polynomial lhs, double k);

    /// @brief Деление полинома на число (через /=).
    friend Polynomial operator/(Polynomial lhs, double k);

    // ==================== Операции сравнения ====================

    friend bool operator<(const Polynomial& l, const Polynomial& r);
    friend bool operator>(const Polynomial& l, const Polynomial& r);
    friend bool operator<=(const Polynomial& l, const Polynomial& r);
    friend bool operator>=(const Polynomial& l, const Polynomial& r);
    friend bool operator==(const Polynomial& l, const Polynomial& r);
    friend bool operator!=(const Polynomial& l, const Polynomial& r);

    // ==================== Вывод ====================

    /**
     * @brief Выводит полином в формате "ax^2 + bx + c".
     */
    void print() const;

    /**
     * @brief Находит корни уравнения ax² + bx + c = 0.
     *
     * При каждом вызове увеличивает статический счётчик
     * rootsCallCount.
     */
    void findRoots() const;
};

#endif // POLYNOMIAL_H