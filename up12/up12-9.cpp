#include <thread>

// скорее всего, неверная реализация, но pending review

template <typename F1, typename F2, typename... Args>
void async_launch(F1&& func, F2&& call, Args&&... args)
{
    auto exec = [&func, &call, &args...]() {
        call(func(args...));
    };
    
    std::jthread thr(exec);
}
