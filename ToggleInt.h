#ifndef TOGGLEINT_H
#define TOGGLEINT_H
#include <algorithm>

using namespace std;

/**
 * @brief integer value that can be switched "on" and "off"
 * between a set value and zero
 */
class ToggleInt
{
    private:
        int m_int;
        int saved;
    public:
        /**
         * @brief default constructor sets value to 0
         */
        ToggleInt(): m_int(0), saved(0) {}
        /**
         * @brief constructor that initializes value directly,
         *        instead of having to call set()
         */
        ToggleInt(int val) : m_int(val), saved(0) {}
        /**
         * @brief set new value
         * @param val
         */
        void set(int val) { m_int = val; }
        /**
         * @return current value
         */
        int value() { return m_int; }
        /**
         * @brief switch between set value and 0
         */
        void toggle() {
            swap(m_int, saved);
        }
};

#endif // TOGGLEINT_H
