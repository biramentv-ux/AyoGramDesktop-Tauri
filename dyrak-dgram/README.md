# dyrakDGram - Български Telegram Desktop Client

![dyrakDGram Logo](https://repository-images.githubusercontent.com/123456789/abc123)

A custom desktop application forked from Telegram, offering a modern interface with advanced features and full plugin support.

## Features

- 🎨 **Modern Interface** - Clean design with Bulgarian language support
- 🔌 **Plugin Architecture** - Full support for custom plugins
- 💰 **Payment Plugins** - FakePaymentInterceptor & MK_FuckPayments
- ⭐ **Content Unlocking** - Telegram Stars content unlocker
- 💎 **Premium Features** - Local Telegram Premium activation
- 🎵 **SpotyDown** - Direct music downloading from Spotify

## Installation

### Windows Portable
Download the latest portable version from our [GitHub Releases](https://github.com/dyrak-dgram/dyrak-dgram/releases).

### From Source
```bash
git clone https://github.com/dyrak-dgram/dyrak-dgram.git
cd dyrak-dgram
cargo tauri build
```

## Plugins

### Fake Payment Interceptor
Simulates payment transactions to bypass real payment systems. Perfect for testing financial applications.

### MK_FuckPayments
Bypasses payment systems and enables premium features without actual payment.

### Unlock Stars Content
Unlocks premium Telegram content using Stars currency programmatically.

### Local Telegram Premium
Enables local Telegram Premium features without requiring a subscription.

### SpotyDown
Downloads music directly from Spotify servers with direct API integration.

## Development

### Project Structure
```
dyrak-dgram/
├── src-tauri/       # Tauri backend (Rust)
├── web/            # Web frontend (HTML/CSS/JS)
└── plugins/        # Plugin implementations
```

### Running in Development
```bash
cargo tauri dev
```

## License

This project is licensed under the MIT License.

## Acknowledgements

- Telegram Desktop for the base architecture
- Tauri framework for cross-platform desktop development
- All plugin authors and contributors

## Contact

For support, feature requests, or contributions, please open an issue on GitHub.
