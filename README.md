
# dyrakDGram

**Enhanced Telegram Client with 105 Powerful Plugins**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Stars](https://img.shields.io/github/stars/biramentv-ux/dyrakDGram?style=social)](https://github.com/biramentv-ux/dyrakDGram)
[![Windows](https://img.shields.io/badge/OS-Windows-blue)](https://www.microsoft.com/windows/)

## 🚀 About This Project

dyrakDGram is a powerful, enhanced Telegram client built on the Telegram Desktop foundation, featuring **105 pre-installed plugins** that extend functionality far beyond the standard client. It's designed for users who want complete control over their messaging experience with advanced features, automation capabilities, and security enhancements.

## 🎯 Key Features

### ✨ Core Functionality
- **100% Compatible** with official Telegram API
- **Portable Mode** - Run from any USB drive
- **Multi-account Support** - Manage multiple accounts seamlessly
- **Advanced UI** - Modern, customizable interface

### 🔧 Plugin System
- **105 Pre-installed Plugins** covering every use case
- **Easy Plugin Management** - Enable/disable at runtime
- **Auto-update** - Keep all plugins current
- **Custom Plugin Support** - Create your own extensions

### 🛡️ Security & Privacy
- **Fake Payment Interceptor** - Bypass payment requirements
- **Unlock Stars Content** - Access premium content
- **Local Premium Activation** - Full Telegram Premium features
- **End-to-End Encryption** - For all your conversations

### 🎵 Multimedia Enhancements
- **SpotyDown Integration** - Download music in MP3/AAC/WAV
- **Enhanced Media Viewer** - Better photo/video handling
- **File Encryption** - Secure your attachments

## 📦 Included Plugins (105 Total)

### 🔥 Core Plugins (Always Enabled)
1. **MK_FuckPaymentsPlugin** - Eliminate payment requirements
2. **FakePaymentInterceptorPlugin** - Bypass payment gates
3. **UnlockStarsContentPlugin** - Access premium content
4. **LocalTelegramPremiumPlugin** - Local premium activation
5. **SpotyDown** - Spotify music integration

### 🛠️ Utility Plugins (25)
6-30. Message scheduling, auto-reply, message templates, batch operations, message search, quick replies, message filtering, message statistics, auto-cleanup, backup manager, import/export, dark mode, theme customizer, notification manager, power saving, battery monitor, performance monitor, memory optimizer, startup manager, system integration, quick launch, desktop shortcuts, file manager

### 🌐 Social Media Integration (10)
31-40. Facebook integration, Twitter integration, Instagram integration, YouTube integration, TikTok integration, Reddit integration, LinkedIn integration, Pinterest integration, Snapchat integration, Discord integration

### 💼 Productivity Tools (10)
41-50. Calendar integration, task manager, note taking, document editor, spreadsheet viewer, presentation viewer, PDF viewer, code editor, terminal emulator, system monitor

### 🎵 Multimedia Enhancements (10)
51-60. Audio player, video player, image editor, GIF maker, screen recorder, voice recorder, audio converter, video converter, image converter, media organizer

### 🛡️ Security & Privacy (10)
61-70. Message encryption, file encryption, VPN integration, ad blocker, tracker blocker, privacy manager, security auditor, password manager, two-factor authentication, biometric authentication

### 🤖 Automation (5)
71-75. Auto-responder, message scheduler, chat bot, workflow automation, macro recorder

### 👨‍💻 Developer Tools (5)
76-80. API tester, WebSocket client, HTTP client, code debugger, terminal

### 🎮 Entertainment (5)
81-85. Game center, emoji picker, sticker maker, meme generator, joke generator

### 📰 News & Information (5)
86-90. News feed, weather, stocks, cryptocurrency, sports

### 💰 Finance (5)
91-95. Budget tracker, expense manager, tax calculator, investment tracker, crypto wallet

### 🎓 Education (5)
96-100. Language learner, flashcards, calculator, unit converter, dictionary

### ❤️ Health & Wellness (5)
101-105. Fitness tracker, meditation guide, water reminder, sleep tracker, habit tracker

## 📥 Инсталация

### Бърза инсталация (Windows)

1. **Свали** най-новата версия от [GitHub Releases](https://github.com/biramentv-ux/dyrakDGram/releases)
2. **Разархивирай** ZIP файла
3. **Стартирай** `install_dyrakDGram.bat` като Администратор
4. **Следи** инструкциите на екрана
5. **Стартирай** dyrakDGram от менюто "Старт" или от бутона на работния плот

### Ръчна инсталация

```bash
# Клонирай репозитория
git clone https://github.com/biramentv-ux/dyrakDGram.git

# Отиди в директорията
cd dyrakDGram

# Инсталирай зависимости
npm install

# Инсталирай плъгините
npm run install:plugins

# Стартирай приложението
npm start
```

## 🎨 Configuration

### First Run Setup

When you first launch dyrakDGram, you'll be prompted to:
1. Enter your Telegram API ID
2. Enter your Telegram API Hash
3. Enter your phone number
4. Enable/disable plugins
5. Configure plugin settings

### Configuration Files

- `config/app.json` - Main application configuration
- `config/plugins.json` - Plugin-specific settings
- `config/accounts.json` - Multiple account management

## 🔧 Plugin Management

### Enable/Disable Plugins

```json
// In config/app.json
"plugins": {
  "enabled": [
    "MK_FuckPaymentsPlugin",
    "FakePaymentInterceptorPlugin",
    "Plugin_1",
    "Plugin_2"
  ],
  "disabled": [
    "Plugin_3",
    "Plugin_4"
  ]
}
```

### Update Plugins

```bash
# Update all plugins
npm run update:plugins

# Update specific plugin
npm run update:plugin -- Plugin_1
```

## 💡 Usage Examples

### Bypass Payment Requirements
```json
"MK_FuckPaymentsPlugin": {
  "enabled": true,
  "bypass_all_payments": true,
  "auto_approve": true
}
```

### Access Premium Content
```json
"UnlockStarsContentPlugin": {
  "enabled": true,
  "auto_unlock": true,
  "download_premium": true
}
```

### Local Premium Activation
```json
"LocalTelegramPremiumPlugin": {
  "enabled": true,
  "features": [
    "large_files",
    "fast_downloads",
    "voice_to_text",
    "advanced_search"
  ]
}
```

### Spotify Integration
```json
"SpotyDown": {
  "enabled": true,
  "format": "mp3",
  "bitrate": 320,
  "auto_download": false
}
```

## 📚 Documentation

### Plugin Development

Create your own plugins by following the [plugin development guide](docs/plugin_development.md).

### API Reference

Learn about the [dyrakDGram API](docs/api_reference.md) for integration with other applications.

### Configuration Options

See all available [configuration options](docs/configuration.md).

## 🤝 Contributing

We welcome contributions! Please see our [contributing guidelines](CONTRIBUTING.md) for details.

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

## 🌟 Stargazers

Thank you to all our contributors and stargazers! 🎉

## 📞 Support

- **GitHub Issues**: [Report bugs](https://github.com/biramentv-ux/dyrakDGram/issues)
- **Discord**: Join our community [Discord server](https://discord.gg/dyrakDGram)
- **Email**: support@dyrakarmy.eu

## 🔗 Related Projects

- [Telegram Desktop](https://desktop.telegram.org/)
- [AyoGram](https://github.com/ayoGram)
- [exDekstop](https://github.com/exDekstop)

## 📊 Statistics

- **Total Plugins**: 105
- **Core Plugins**: 5
- **Utility Plugins**: 25
- **Social Media Plugins**: 10
- **Productivity Plugins**: 10
- **Multimedia Plugins**: 10
- **Security Plugins**: 10
- **Other Plugins**: 45

## 🎉 Thank You

Thank you for choosing dyrakDGram! We hope you enjoy using our enhanced Telegram client with its powerful plugin system.

**Happy messaging!** 🚀

## 🎨 NSFW Image Generator (Ново!)

### Overview
The **NSFW Image Generator** is an advanced image-to-image plugin that allows you to generate uncensored, high-quality images using Stable Diffusion. This feature is perfect for creating custom NSFW content with full control over the output.

### Features
- ✅ Image-to-Image generation
- ✅ Uncensored content generation
- ✅ Batch generation support
- ✅ Custom prompt control
- ✅ Strength and guidance parameters
- ✅ Telegram server integration for model loading
- ✅ GPU acceleration support

### How to Use

#### Basic Usage
1. Open the **NSFW Image Generator** from the menu
2. Select an input image
3. Enter your prompt describing the desired output
4. Adjust strength (0-1) and guidance scale (0-20)
5. Click "Generate" to create your image

#### Advanced Usage
```python
from plugins.nsfw_image_generator.nsfw_image_generator import NSFWImageGenerator

# Initialize generator
generator = NSFWImageGenerator(
    model_id="runwayml/stable-diffusion-v1-5",
    device="cuda"
)

# Generate single image
output_path = generator.generate(
    init_image="input.jpg",
    prompt="detailed description of desired output",
    negative_prompt="unwanted elements",
    strength=0.75,
    guidance_scale=7.5,
    num_inference_steps=50,
    seed=42
)

# Generate batch of variations
prompts = [
    "variation 1 description",
    "variation 2 description",
    "variation 3 description"
]
outputs = generator.generate_batch(
    init_image="input.jpg",
    prompts=prompts,
    strength=0.75,
    guidance_scale=7.5
)
```

### Parameters
| Parameter | Type | Description | Default |
|-----------|------|-------------|---------|
| `init_image` | str | Path to input image | Required |
| `prompt` | str | Description of desired output | Required |
| `negative_prompt` | str | What to avoid | "" |
| `strength` | float | How much to transform (0-1) | 0.75 |
| `guidance_scale` | float | Prompt influence (0-20) | 7.5 |
| `num_inference_steps` | int | Number of denoising steps | 50 |
| `seed` | int | Random seed for reproducibility | None |

### Requirements
- Python 3.8+
- PyTorch
- diffusers
- Pillow
- CUDA GPU recommended (but CPU works too)

### Installation
```bash
pip install torch diffusers pillow
```

### Telegram Server Integration
The plugin can load model configurations from Telegram servers for remote model management:
```python
from plugins.nsfw_image_generator.nsfw_image_generator import load_model_from_telegram_server

# Load model config from Telegram
load_model_from_telegram_server()
```

### Examples

#### Example 1: Basic Image-to-Image
```python
generator = NSFWImageGenerator()
output = generator.generate(
    init_image="photo.jpg",
    prompt="beautiful portrait with detailed features",
    strength=0.5,
    guidance_scale=7.5
)
```

#### Example 2: Batch Generation
```python
generator = NSFWImageGenerator()
prompts = [
    "artistic style with vibrant colors",
    "realistic style with natural lighting",
    "anime style with detailed features"
]
outputs = generator.generate_batch(
    init_image="base_image.jpg",
    prompts=prompts
)
```

### Troubleshooting
- **GPU Memory Issues**: Reduce `num_inference_steps` or use `strength=0.5`
- **Slow Generation**: Enable CUDA or reduce image resolution
- **Model Loading Error**: Check internet connection for model download

### Version History
- **v1.0.0**: Initial release with image-to-image support
- **v1.0.1**: Added batch generation and Telegram server integration

## 🌐 Custom Domain: dyrakarmy.eu

### GitHub Pages Configuration
The project now uses `dyrakarmy.eu` as the custom domain for GitHub Pages.

### DNS Setup Required
Add these DNS records to your domain registrar:

| Type | Name | Value | TTL |
|------|------|-------|-----|
| A | @ | 185.199.108.153 | Auto |
| A | @ | 185.199.109.153 | Auto |
| A | @ | 185.199.110.153 | Auto |
| A | @ | 185.199.111.153 | Auto |
| CNAME | www | dyrakarmy.eu | Auto |

### GitHub Repository Settings
1. Go to **Settings** > **Pages**
2. Under **Custom domain**, enter: `dyrakarmy.eu`
3. Click **Save**
4. Wait for DNS propagation

### URLs
- **Main Site**: https://dyrakarmy.eu
- **WWW Version**: https://www.dyrakarmy.eu
- **GitHub Pages**: https://dyrakarmy.eu

### SSL Certificate
GitHub automatically provisions an SSL certificate for custom domains. It may take up to 24 hours to activate.
