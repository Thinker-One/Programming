### 1. C++ 彩色输出
```c++
#include <iostream>
#include <cstdio>

#define ENABLE_LOG 1		             // 控制打印的开启和关闭
#if ENABLE_LOG
#define LOG_INFO(color, fmt, ...) \
    do { \
        std::cout << color; \
        printf(fmt, ##__VA_ARGS__); \
        std::cout << DEFAULT << std::endl; \
    } while (0)
#else
#define LOG_INFO(color, fmt, ...)
#endif

const std::string DEFAULT = "\033[0m";       // 重置所有属性，包括颜色、加粗、下划线等，使其恢复到默认状态
const std::string RED     = "\033[31m";      // 红色
const std::string GREEN   = "\033[32m";      // 绿色
const std::string YELLOW  = "\033[33m";      // 黄色
const std::string BLUE    = "\033[34m";      // 蓝色
const std::string MAGENTA = "\033[35m";      // 品红色
const std::string CYAN    = "\033[36m";      // 青色
const std::string WHITE   = "\033[37m";      // 白色

int main() {
    std::string jsonString("hello world!");
    LOG_INFO(DEFAULT, "这是一个测试程序：hello world!");
    LOG_INFO(GREEN, "这是一个测试程序：hello world!");
    LOG_INFO(YELLOW, "这是一个测试程序：%s", "hello world!");
    LOG_INFO(CYAN, "这是一个测试程序：%s", jsonString.c_str());
    return 0;
}
```
