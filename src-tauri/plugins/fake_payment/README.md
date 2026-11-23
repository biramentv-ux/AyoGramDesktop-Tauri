# Fake Payment Plugin

## Описание
Плъгин `fake_payment` предлага заместващ механизъм за плащания в AyoGramDesktop. Той позволява на потребителя да имитира успешни плащания и да зададе фиктивен баланс за демонстрационни цели.

## Функционалност
- `FakePaymentState` структура със следните полета:
  - `enabled`: булева стойност, дали плъгина е активен
  - `last_request`: опционален низ за последната заявка
  - `balance`: число за фиктивен баланс
- `initialize() -> (String, String, String)` функция за инициализация с име, версия и описание
- `process_request(state, request)` обработка на заявка към платежната система
- `toggle(state)` превключване на активността на плъгина

## Използване
```rust
let mut state = FakePaymentState::default();
state.enabled = true;
let result = process_request(&mut state, "payment_request_123");
```