# 🚀 AyoGram Desktop Hybrid - Tauri Edition

> **Telegram, но по твой начин.** Хибриден desktop клиент с Ghost Mode и Stream Mode.
>
> Построен с ⚡️ Tauri + Rust + Vite/Tailwind за максимална скорост, минимален memory footprint,
> и истинска плагин архитектура — без Android emulator.

<div align="center">
  <img src="https://img.shields.io/badge/platform-Windows%2010/11-blue?style=flat-square" alt="Platform"> 
  <img src="https://img.shields.io/badge/framework-Tauri%202-red?style=flat-square" alt="Tauri"> 
  <img src="https://img.shields.io/badge/language-Rust-orange?style=flat-square" alt="Rust"> 
  <img src="https://img.shields.io/badge/arch-Portable-green?style=flat-square" alt="Portable">
</div>

---

## ✨ Ключови Функционалности

| 💎 Фича | Описание |
|---------|----------|
| **Ghost Mode** 🕵️‍♂️ | Чети Telegram без да се показваш — невидим за другите, реален за теб |
| **Stream Mode** ⚡ | Мигнени обновяване на чатове и профили в реално време |
| **Plugin Architecture** 🧩 | Разширявай приложението с Rust/C++ плъгини без да прегоряваш |
| **Portable** 📦 | Една папка, нула инсталации — копирай и стартирай от USB stick |
| **System Tray** 🖥️ | Минимизирай в трей за бърз достъп |
| **Telegram Web Integration** 💬 | Позволен Telegram client interface с собствена логика на плагините |

---

## 🚀 Бърз Старт (Windows)

```powershell
# Копирай репото и отвори PowerShell в него:
git clone https://github.com/biramentv-ux/AyoGramDesktop-Tauri.git
cd AyoGramDesktop-Tauri

# Изпълни бързи скрипт — инсталира всичко автоматично:
Set-ExecutionPolicy -Scope Process -Bypass
.\build-tauri.ps1
```

🎉 Това ще инсталира Node.js 20, Rust stable, pnpm, компилира frontend и Rust backend
и създаде portable папка в `release/AyoGramDesktop_Portable/`.

---

## 📦 Portable Build — Отделен файл или папка?

```powershell
# Изпълни build скриптът:
.\build-tauri.ps1 -PortableOnly
```

📁 **Резултат:** `release/AyoGramDesktop_Portable/` съдържа:
- `AyoGramDesktop.exe` — само приложението (portable)
- `*.msi` — опционален инсталатор за традиционна инсталация
- `ayu_settings.json` — потребителски настройки

---

## 🧩 Плъгин Архитектура

AyoGram поддържа истинска, расширяема плъгин система на Rust/C++. 
Всеки плъгин е отделна crate с собствена `Cargo.toml`, но се компилира и линква с основното приложение.

### Съществуващи Плъгини:

| Плъгин | Описание |
|--------|----------|
| `ghost_mode` | 👻 Невидим режим — чети без да показваш activity |
| `stream_mode` | ⚡ Realtime обновяване на всички чатове и профили |
| `fake_payment` | 💳 Пресечка/прехвърляне на вградения Telegram плащания UI |
| `local_premium` | 🌟 Локaлно имитиране на Telegram Premium статус без реално плащане |

### Добавяне на Нов Плъгин:

1. **Създай нова Rust crate:**
   ```bash
   mkdir my_new_plugin
   cd my_new_plugin
   cargo init --lib
   ```

2. **Дефинирай интерфейс в `Cargo.toml`:**
   ```toml
   [package]
   name = "my_new_plugin"
   version = "0.1.0"
   edition = "2024"

   [dependencies]
   serde_json = "1.0"
   ```

3. **Имплементирай в `src/lib.rs`:**
   ```rust
   use serde_json::{json, Value};

   pub fn plugin_init() -> Value {
       json!({
           "name": "My New Plugin",
           "version": "0.1.0",
           "enabled": true,
           "hooks": {"on_message_received": true}
       })
   }

   pub fn plugin_handle_event(event: &str, payload: Value) -> Option<Value> {
       if event == "on_message_received" {
           // Твоята логика тук...
           return Some(json!({"processed": true}));
       }
       None
   }
   ```

4. **Регистрирай в `src-tauri/Cargo.toml`:**
   ```toml
   my_new_plugin = { path = "../my_new_plugin" }
   ```

5. **Експортирай Tauri command в `src-tauri/src/main.rs`:**
   ```rust
   use my_new_plugin::plugin_init;

   #[tauri::command]
   fn my_plugin_info() -> String {
       let info = plugin_init();
       info.to_string()
   }

   tauri::generate!
   ```

6. **Използвай в UI:**
   ```javascript
   window.__TAURI__.invoke('my_plugin_info').then(info => {
     console.log('Plugin:', info);
   });
   ```

---

## 🔧 Developer Quick Start

```powershell
# Инсталиране на зависимости:
pnpm install

# Frontend dev server:
pnpm dev

# Backend dev (Rust):
cd src-tauri && cargo tauri dev
```

---

## 📁 Структура на Проектa

```
AyoGramDesktop/
├─ src-tauri/              # Tauri backend + Rust код
│  ├─ src/main.rs          # Tauri entry, system-tray, commands
│  ├─ Cargo.toml           # Backend dependencies
│  └─ icons/               # Приложение иконки
├─ ghost_mode/             # 👻 Ghost Mode плъгин
│  ├─ Cargo.toml
│  └─ src/lib.rs
├─ stream_mode/            # ⚡ Stream Mode плъгин
│  ├─ Cargo.toml
│  └─ src/lib.rs
├─ fake_payment/           # 💳 Fake Payment плъгин
├─ local_premium/          # 🌟 Local Premium плъгин
├─ src/                    # Vite/Tailwind frontend
│  ├─ index.html
│  ├─ App.tsx
│  └─ ...компоненти...
├─ package.json            # Node dependencies
├─ vite.config.ts          # Vite configuration
├─ tauri.conf.json         # Tauri configuration
├─ build-tauri.ps1         # 🚀 Автоматичен build скрипт
└─ release/                # Генериран releases и portable папки
```

---

## ⚙️ Тестване Auto-Updater Локално

1. Смени `pubkey` в `tauri.conf.json` с реален Ed25519 ключ.
2. Стартирай локален HTTP server:
   ```powershell
   python -m http.server 8000
   ```
3. Смени updater endpoints на `http://localhost:8000/releases/{{version}}`.
4. Пусни `cargo tauri dev` и тествай update flow.

---

## 🖥️ Системни Изисквания

- Windows 10/11 (64-bit)
- PowerShell 5+
- Интернет за първо сваляне на зависимости (Node.js, Rust toolchain)
- ~2GB free space за build

---

## 🛠️ Troubleshooting

**Проблем:** `pnpm` не е инсталиран  
**Решение:** `npm install -g pnpm`

**Проблем:** Rust toolchain липсва  
**Решение:** Изпълни `.\build-tauri.ps1` — той автоматично сваля и инсталира.

---

<div align="center">
  <strong>AyoGram Desktop Hybrid</strong> — Telegram, който работи за теб.<br>
  Сделан с ❤️ от <a href="https://github.com/biramentv-ux">biramentv-ux</a>
</div>
