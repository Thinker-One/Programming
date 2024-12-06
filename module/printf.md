### 1. C++ 显示彩色调试信息
* **颜色的表示**
```c++
// 标准颜色，用 ANSI 转义码表示
const std::string DEFAULT = "\033[0m";                     // 重置所有属性，包括颜色、加粗、下划线等，使其恢复到默认状态
const std::string RED     = "\033[31m";                    // 红色
const std::string GREEN   = "\033[32m";                    // 绿色
const std::string YELLOW  = "\033[33m";                    // 黄色
const std::string BLUE    = "\033[34m";                    // 蓝色
const std::string MAGENTA = "\033[35m";                    // 品红色
const std::string CYAN    = "\033[36m";                    // 青色
const std::string WHITE   = "\033[37m";                    // 白色

// 高亮颜色，用 ANSI 转义码表示
const std::string DEFAULT = "\033[0m";                     // 重置颜色
const std::string RED     = "\033[1;31m";                  // 亮红色
const std::string GREEN   = "\033[1;32m";                  // 亮绿色
const std::string YELLOW  = "\033[1;33m";                  // 亮黄色
const std::string BLUE    = "\033[1;34m";                  // 亮蓝色
const std::string MAGENTA = "\033[1;35m";                  // 亮品红色
const std::string CYAN    = "\033[1;36m";                  // 亮青色
const std::string WHITE   = "\033[1;37m";                  // 亮白色

// 高亮颜色，用 RGB 表示，推荐这种，亮度醒目，灵活性高，可自己配置合适的颜色
const std::string DEFAULT = "\033[0m";                     // 重置颜色
const std::string RED     = "\033[38;2;255;100;100m";      // 亮红色 (RGB: 255, 100, 100)
const std::string GREEN   = "\033[38;2;100;255;100m";      // 亮绿色 (RGB: 100, 255, 100)
const std::string YELLOW  = "\033[38;2;255;255;100m";      // 亮黄色 (RGB: 255, 255, 100)
const std::string BLUE    = "\033[38;2;100;100;255m";      // 亮蓝色 (RGB: 100, 100, 255)
const std::string MAGENTA = "\033[38;2;255;100;255m";      // 亮品红色 (RGB: 255, 100, 255)
const std::string CYAN    = "\033[38;2;100;255;255m";      // 亮青色 (RGB: 100, 255, 255)
const std::string WHITE   = "\033[38;2;255;255;255m";      // 亮白色 (RGB: 255, 255, 255)

// note
1、\033 是转义字符 (ESC) 的十六进制表示，表示转义序列的开始
2、\033[0m：这是重置颜色的转义序列，确保后面的文本恢复为终端默认的颜色。
3、1 是表示高亮/亮色的参数，m 表示命令的结束
4、38 是用来指定前景色（即文本颜色）的参数，48 用于设置背景色
5、2 表示使用 24 位（RGB）颜色模式，后跟 RGB 的三个分量（R;G;B）
6、其中 R, G, B 分别是 0 到 255 范围内的整数，表示红、绿、蓝的颜色分量，每个分量取值范围是 0 到 255

```
* **示例**
```c++
#include <iostream>
#include <cstdio>

#define ENABLE_LOG 1		                       // 控制打印的开启和关闭
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

const std::string DEFAULT = "\033[0m";                 // 重置颜色
const std::string RED     = "\033[38;2;255;100;100m";  // 亮红色 (RGB: 255, 100, 100)
const std::string GREEN   = "\033[38;2;100;255;100m";  // 亮绿色 (RGB: 100, 255, 100)
const std::string YELLOW  = "\033[38;2;255;255;100m";  // 亮黄色 (RGB: 255, 255, 100)
const std::string BLUE    = "\033[38;2;100;100;255m";  // 亮蓝色 (RGB: 100, 100, 255)
const std::string MAGENTA = "\033[38;2;255;100;255m";  // 亮品红色 (RGB: 255, 100, 255)
const std::string CYAN    = "\033[38;2;100;255;255m";  // 亮青色 (RGB: 100, 255, 255)
const std::string WHITE   = "\033[38;2;255;255;255m";  // 亮白色 (RGB: 255, 255, 255)

int main() {
    std::string jsonString("hello world!");
    LOG_INFO(DEFAULT, "这是一个测试程序：hello world!");
    LOG_INFO(GREEN, "这是一个测试程序：hello world!");
    LOG_INFO(YELLOW, "这是一个测试程序：%s", "hello world!");
    LOG_INFO(CYAN, "这是一个测试程序：%s", jsonString.c_str());
    return 0;
}
```
