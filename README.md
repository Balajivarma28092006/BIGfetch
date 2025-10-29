```markdown
# BIGfetch

A lightweight system information fetch tool written in C++ (like neofetch, but for Windows).  
BIGfetch displays details such as OS, CPU, RAM, Disk, Battery, Uptime, and more — all customizable via a JSON config.  
It also supports ASCII logos and colored output in the console.

---

## ✨ Features

- 🔹 Show OS version, CPU info, RAM usage, Disk usage, Battery status, Hostname, Username, and Uptime  
- 🎨 Customizable color scheme (via `config/config.json`)  
- 🖼️ Support for ASCII art logos (`src/ascii/logo.txt`)  
- ⚙️ Modular structure (separate `systeminfo`, `configreader`, `colors`, `display`, `ascii`)  
- 📦 Package-managed dependencies with vcpkg (currently `nlohmann-json`)  
- 🪟 Windows-specific system API integration  

---

## 📂 Project Structure

```
BIGfetch/
├── CMakeLists.txt        # CMake build configuration
├── vcpkg.json            # Dependencies (nlohmann-json)
├── config/
│   └── config.json       # User configuration
├── src/
│   ├── main.cpp          # Entry point
│   ├── ascii/logo.txt    # ASCII art logo
│   ├── sysinfo/
│   │   ├── systeminfo.cpp
│   │   └── systeminfo.h
│   ├── colors/
│   │   ├── colors.cpp
│   │   └── colors.h
│   ├── display/
│   │   ├── display.cpp
│   │   └── display.h
│   ├── configreader.cpp
│   └── configreader.h
└── external/
└── helper.cpp/.h     # Extra messages
```

---

## ⚡ Installation

1. **Clone the repo**
   ```bash
   git clone https://github.com/yourusername/BIGfetch.git
   cd BIGfetch
   ```

2. **Install dependencies with vcpkg**
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   ./vcpkg/bootstrap-vcpkg.bat
   ./vcpkg/vcpkg install nlohmann-json
   ```

3. **Build with CMake + Ninja**
   ```bash
   cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake -G Ninja
   cmake --build build
   ```

4. **Run**
   ```bash
   ./build/BIGfetch.exe
   ```

---

## ⚙️ Configuration

Customize what BIGfetch displays in `config/config.json`:

```json
{
  "show": {
    "os": true,
    "helper": true,
    "RAM": true,
    "cpu": true,
    "username": true,
    "hostname": true,
    "diskspace": true,
    "uptime": true,
    "colorbar": true,
    "battery": true,
    "ascii": true
  },
  "colors": {
    "title": "CYAN",
    "label": "YELLOW",
    "value": "WHITE"
  }
}
```

---

## 🖼️ ASCII Logo

Place your ASCII art inside `src/ascii/logo.txt`.
For example:

```
███╗   ██╗███████╗ ██████╗ 
████╗  ██║██╔════╝██╔═══██╗
██╔██╗ ██║█████╗  ██║   ██║
██║╚██╗██║██╔══╝  ██║   ██║
██║ ╚████║███████╗╚██████╔╝
╚═╝  ╚═══╝╚══════╝ ╚═════╝ 
```

---

## 🎨 Colors

BIGfetch supports both Windows API colors and ANSI escape codes.
Available colors:

```
RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, DEFAULT
```

---

## 🔮 Roadmap

* Linux/macOS support
* GPU info detection
* Themes (multiple ASCII + color configs)
* Package manager support (Chocolatey / Scoop / Winget)

---

## 🤝 Contributing

Pull requests are welcome!
For major changes, please open an issue first to discuss your ideas.

---

## 📄 License

[MIT License](LICENSE)
```
