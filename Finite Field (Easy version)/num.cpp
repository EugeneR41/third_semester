#include "num.h"

Num::Num(int m_value, int m_modulo) {
    modulo = m_modulo;
    value = m_value % modulo;
}

Num::Num(const Num& other) {
    value = other.value;
    modulo = 0;
}
