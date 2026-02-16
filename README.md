# Шаблон проекта программы для МК

## Требуемые инструментальные средства:

- arm-none-eabi-gcc
- gdb-multiarch (arm-none-eabi-gdb)
- make (make + ninja-build)
- cmake
- openocd
- doxygen (для документирования программы)


## Рекомендуемый редактор (IDE)

Visual Studio Code c плагинами ():

- C/C++;
- CMake Tools;
- Cortex-Debug.

## Настройка и сборка проекта

---

# Linux

## Настройка

Откройте терминал в корневой папке проекта и выполните:

```
cmake -B build
```

Будет создана директория `build/` с файлами конфигурации.

---

## Сборка проекта

В том же терминале выполните:

```
cmake --build build
```

---

# Windows

## Настройка проекта (Configuration)

1. Откройте VS Code в корне проекта.
2. Выполните в терминале:

```
cmake --preset debug
```

Команда создаст директорию:

```
build/debug
```

и сгенерирует файлы сборки согласно пресету `debug`.

---

## Сборка проекта (Build)

В том же терминале выполните:

```powershell
cmake --build --preset app-debug
```

После успешной сборки бинарные файлы будут находиться в:

```
build/debug
```

---

## Настройка IntelliSense в VS Code

Чтобы корректно работала подсветка и автодополнение:

1. Нажмите `Ctrl + Shift + P`
2. Выберите `C/C++: Edit Configurations (UI)`
3. Откройте раздел **Advanced settings**
4. В поле **Compile Commands** укажите:

```
${workspaceFolder}/build/debug/compile_commands.json
```

Сохраните изменения.

---

## VS Code не видит Ninja / Make / Toolchain / Printf

Если инструмент доступен в обычном PowerShell, но не работает в VS Code:

1. Нажмите `Ctrl + Shift + P`
2. Выберите `Preferences: Open User Settings (JSON)`
3. Добавьте в конец файла:

```json
"terminal.integrated.env.windows": {
    "PATH": "${env:PATH};C:\\Program Files\\Git\\usr\\bin;C:\\Program Files (x86)\\Arm GNU Toolchain arm-none-eabi\\14.2 rel1\\bin;C:\\Users\\Omen\\AppData\\Local\\Microsoft\\WinGet\\Links"
}
```

> Несколько путей разделяются символом `;`  
> После изменений перезапустите VS Code.  
> Имейте ввиду, что ваши пути могут отличаться от указанных выше