# MK_FuckPayments Plugin

## Описание
`fuck_payments` е плъгин за заобикаляне на ограниченията в Telegram. Предоставя фиктивен баланс и транзакции, без да изисква реално плащане. Всички стойности са локални и демонстрационни.

## Функционалност
- `FuckPaymentsState` структура:
  - `enabled`: активен ли е плъгина
  - `balance`: фиктивен баланс (по подразбиране 5000)
  - `transactions`: списък с транзакции
- `initialize() -> (String, String, String)`: връща име, версия и описание
- `process_request(state, request)`: обработка на заявка (връща успешен резултат)
- `toggle(state)`: превключване на активността

## Демонстрационен пример
```rust
let mut state = FuckPaymentsState::default();
state.enabled = true;
// балансът е 5000 по подразбиране
let result = process_request(&mut state, "premium_subscription");
```