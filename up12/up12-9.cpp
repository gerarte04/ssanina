#include <functional>
#include <future>
#include <thread>
#include <iostream>

// very weird (not working)

template <typename Res, typename... Args>
void async_launch(std::function<Res(Args...)> func, std::function<void(Res)> call, Args... args)
{
    std::packaged_task<void(std::function<Res(Args...)>, std::function<void(Res)>, Args...)> task([](std::function<Res(Args...)> func, std::function<void(Res)> call, Args... args) {
        call(func(args...));
        });
    task(func, call, args...);
}
