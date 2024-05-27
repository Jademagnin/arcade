/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** cacheManager
*/

#include <functional>
#include <sstream>
#include <string>
#include <map>
#include <memory>
#include <iostream>

template <typename T, typename... Args>
class CacheManager {
public:
    CacheManager() = default;
    ~CacheManager() = default;

    T call(std::function<T(Args...)> func, Args... args)
    {
        std::string key = generateKey(func, args...);
        // std::cout << "key: " << key << std::endl;
        if (_cache.find(key) == _cache.end())
        {
            _cache[key] = func(args...);
        }
        return _cache[key];
    }

    std::string getKeyByFunc(std::function<T(Args...)> func, Args... args)
    {
        return generateKey(func, args...);
    }

    void removeByFuncCall(std::function<T(Args...)> func, Args... args)
    {
        std::string key = generateKey(func, args...);
        if (_cache.find(key) != _cache.end()) {
            _cache.erase(key);
        }
    }

    void removeByKey(const std::string &key)
    {
        if (_cache.find(key) != _cache.end())
            _cache.erase(key);
    }

    void clear()
    {
        _cache.clear();
    }

private:
    std::map<std::string, T> _cache;

    std::string generateKey(std::function<T(Args...)> func, Args... args)
    {
        auto func_ptr = func.target<T(*)(Args...)>();
        if (!func_ptr) {
            throw std::runtime_error("Function is not a free function");
        }

        std::size_t hash = 0;
        hash_combine(hash, reinterpret_cast<std::size_t>(*func_ptr));
        (hash_combine(hash, args), ...);

        return std::to_string(hash);
    }

    template <class U>
    void hash_combine(std::size_t& seed, const U& v)
    {
        std::hash<U> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
};
