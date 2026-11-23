# Local Telegram Premium Plugin

## Описание
`local_premium` осигурява локална реализация на Telegram Premium функции. Тези функции са достъпни в рамките на приложението, без изискване за реално плащане.

## Функционалност
- `PremiumState` структура:
  - `enabled`: дали Premium е активен
  - `features`: списък с разблокирани функции (по подразбиране: `premium_badge`, `message_privacy`)
- `initialize() -> (String, String, String)`: връща име, версия и описание
- `enable_features(features)`: активира указаните функции
- `is_enabled(state)`: проверява дали плъгина е активен

## Пример за употреба
```rust
let mut state = PremiumState::default();
state.enabled = true;
enable_features(&mut state, vec!["premium_badge", "message_privacy"]);
```