# Unlock Stars Content Plugin

## Описание
`unlock_stars` предоставя механизъм за разблокиране на платени функции в Telegram без реално плащане. Използва се за демонстрационни цели и тестове.

## Функционалност
- `PremiumState` структура:
  - `enabled`: активен ли е плъгина
  - `features`: списък от разблокирани функции (по подразбиране: `premium_badge`, `message_privacy`)
- `initialize() -> (String, String, String)`: връща име, версия и описание
- `enable_features(features)`: активира указаните функции
- `get_features(state)`: връща списък с текущо разблокирани функции
- `is_enabled(state)`: проверява дали плъгина е активен

## Пример за употреба
```rust
let mut state = PremiumState::default();
state.enabled = true;
enable_features(&mut state, vec!["star_chat", "premium_badge"]);
```