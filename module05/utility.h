#ifndef MODULE05_UTILITY_H
#define MODULE05_UTILITY_H

#include <map>
#include <mutex>

template<typename Result, typename ...Args>
auto
make_memoized(Result (*f)(Args...)) {
    std::map<std::tuple<Args...>, Result> cache{};
    return [f, cache](Args... args) mutable -> Result {
        const auto args_tuple = std::make_tuple(args...);
        const auto cached = cache.find(args_tuple);
        if (cached == cache.end()) {
            auto result = f(args...);
            cache[args_tuple] = result;
            return result;
        } else {
            return cached->second;
        }
    };
}

template <class Sig, class F>
class memoize_helper;

template <class Result, class... Args, class F>
class memoize_helper<Result(Args...), F> {
private:
    using function_type = F;
    using args_tuple_type
            = std::tuple<std::decay_t<Args>...>;

    function_type f;
    mutable std::map<args_tuple_type, Result> m_cache;       // <1>
    mutable std::recursive_mutex m_cache_mutex;              // <1>

public:
    template <typename Function>
    memoize_helper(int, Function&& f)                        // <2>
            : f(f)                                               // <2>
    {
    }

    memoize_helper(const memoize_helper& other)              // <2>
            : f(other.f)                                         // <2>
    {
    }

    template <class... InnerArgs>
    Result operator()(InnerArgs&&... args) const
    {
        std::unique_lock<std::recursive_mutex>
                lock{m_cache_mutex};

        const auto args_tuple =                              // <3>
                std::make_tuple(args...);                        // <3>
        const auto cached = m_cache.find(args_tuple);        // <3>

        if (cached != m_cache.end()) {
            return cached->second;                           // <4>

        } else {
            auto&& result = f(                               // <5>
                    *this,                                   // <5>
                    std::forward<InnerArgs>(args)...);       // <5>
            m_cache[args_tuple] = result;                    // <5>
            return result;                                   // <5>
        }
    }
};

#endif //MODULE05_UTILITY_H
