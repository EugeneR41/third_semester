#include "num.h"

Num::Num(int m_value, int m_modulo) {
    modulo = m_modulo;
    value = m_value % modulo;
}

Num &Num::operator=(const Num& other) = default;

Num Num::operator+(const Num &other) {
    int new_value = value + other.value;
    return Num(new_value, modulo);
}

Num Num::operator-(const Num& other) {
    int new_value = value - other.value;
    return Num(new_value, modulo);
}

Num Num::operator*(const Num& other) {
    int new_value = value * other.value;
    return Num(new_value, modulo);
}

Num Num::operator+(int num) {
    int new_value = value + num;
    return Num(new_value, modulo);
}

Num Num::operator-(int num) {
    int new_value = value - num;
    return Num(new_value, modulo);
}

Num Num::operator*(int num) {
    int new_value = value * num;
    return Num(new_value, modulo);
}

Num &Num::operator+=(const Num& other) {
    value = value + other.value;
    return *this;
}

Num &Num::operator-=(const Num& other) {
    if (value < other.value)
        value = value + modulo - other.value;
    else
        value = value - other.value;
    return *this;
}

Num &Num::operator*=(const Num& other) {
    value = value * other.value;
    return *this;
}

Num &Num::operator+=(int num) {
    int64_t new_value = value;
    new_value = (new_value + num) % modulo;
    value = new_value;
    return *this;
}

Num &Num::operator-=(int num) {
    if (value < num)
        value = value + modulo - num;
    else
        value = value - num;
    return *this;
}

Num &Num::operator*=(int num) {
    int64_t new_value = value;
    new_value = (new_value * num) % modulo;
    value = new_value;
    return *this;
}
