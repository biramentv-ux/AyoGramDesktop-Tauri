# 📱 dyrakDGram Мобилни - Android & iOS

> **Пълнофункционален Telegram клиент за мобилни устройства**
>
*Изграден с Tauri Mobile - бърз, лек и сигурен*

---

## 🚀 Възможности

- ✅ Пълен Telegram протокол
- ✅ Български превод
- ✅ Ghost Mode (скрит режим)
- ✅ Stream Mode (гледане на съдържание)
- ✅ Звукови съобщения
- ✅ Групови чатове
- ✅ Cloud storage (5GB безплатно)
- ✅ End-to-end encryption

---

## 📲 Инсталиране

### Android
- **APK**: [Изтегли dyrakDGram APK](https://github.com/dyragram/dyrakDGram/releases)
- **Изисквания**: Android 7.0+ (ARM64-v8a, x86_64)

### iOS  
- **App Store**: предстоящо
- **TestFlight**: [Присъедини се към TestFlight](https://testflight.apple.com/dyragram)
- **Изисквания**: iOS 14.0+ (iPhone/iPad)

---

## 🛠️ Сграждане от изходен код

### Android
```bash
# Инсталиране на Rust и Tauri CLI
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
source $HOME/.cargo/env
npm install -g @tauri-apps/cli

# Сграждане на Android приложение
cd dyrak-dgram
cargo tauri android build --release
```

### iOS
```bash
# Инсталиране на Xcode и зависимости
xcode-select --install
npm install -g @tauri-apps/cli

# Сграждане на iOS приложение
cd dyrak-dgram
cargo tauri ios build --release
```

---

## 📁 Структура на проекта

```
dyrak-dgram/
├── src-tauri/          # Rust backend (Tauri)
├── web/               # Web frontend (React + Tailwind)
├── android/           # Android специфичен код
│   ├── app/           # App ресурси
│   └── build.gradle   # Конфигурация за сграждане
├── ios/               # iOS специфичен код
│   ├── Resources/     # Асети и конфигурации
│   └── Info.plist     # Конфигурация на приложението
└── README.md          # Този файл
```

---

## 🌐 Уеб версия

Посетете нашия уеб апликация: [https://web.dyragram.app](https://web.dyragram.app)

- **Светла/Тъмна тема**: Автоматично превключване
- **Респонсивен дизайн**: Работи на всички устройства
- **Инстанкт sync**: Реално време

---

## 🤝 Принос

Добре дошли са приносите! Ето как можете да помогнете:

1. Форкни репозитория
2. Създай бранч с функцията (`git checkout -b feature/УдивителнаФункция`)
3. Запази промените (`git commit -m 'feat: добави удивителна функция'`)
4. Пушни към бранча (`git push origin feature/УдивителнаФункция`)
5. Отвори Pull Request

---

## 📄 Лиценз

Разпространяван под MIT лиценз. Виж `LICENSE` за подробности.

---

## 💬 Поддръжка

- Telegram група: [@dyrakDGramChat](https://t.me/dyragramChat)
- GitHub проблеми: [Съобщи за бъг](https://github.com/dyragram/dyrakDGram/issues)

---

*dyrakDGram не е свързан с Telegram или Telegram FZ LLC*

---

<div align="center">
  <img src="https://img.shields.io/github/license/dyragram/dyrakDGram?style=flat-square">
  <img src="https://img.shields.io/github/v/release/dyragram/dyrakDGram?style=flat-square">
  <img src="https://img.shields.io/github/stars/dyragram/dyrakDGram?style=flat-square">
</div>
