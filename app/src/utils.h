#ifndef UTILS
#define UTILS

#include <functional>


class FinallyGuard
{
    const std::function<void()> m_finally;

public:
    FinallyGuard(std::function<void()> func)
        : m_finally(func) {
    }

    ~FinallyGuard() {
        if (m_finally)
            m_finally();
    }
};

#endif // UTILS
