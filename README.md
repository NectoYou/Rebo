# rebo

Минималистичная C++17 библиотека для сохранения файлов (TXT, JSON). Header‑only: просто подключи один файл и используй.

**Автор:** <твой ник>  
**Лицензия:** MIT

## Как подключить

1. Скачай `rebo.hpp` из папки `include`.
2. Положи в свой проект (например, рядом с `main.cpp` или в папку `libs`).
3. Добавь в код: `#include "rebo.hpp"`
4. Собирай с флагом `-std=c++17`.

## Примеры

### Сохранить JSON
```cpp
#include "rebo.hpp"
#include <iostream>

int main() {
    std::string json = R"({"volume":50, "brightness":70})";
    if (rebo::save_json(".", "config", json)) {
        std::cout << "Saved!\n";
    }
}
