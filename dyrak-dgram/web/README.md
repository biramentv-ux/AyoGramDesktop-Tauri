# dyrakDGram Web Frontend

This is the React-based web frontend for dyrakDGram - a personalized Telegram client.

## Features

- **Modern UI**: Built with React, Tailwind CSS, and Vite
- **Responsive Design**: Works on desktop and mobile devices
- **Dark Mode Support**: Toggle between light and dark themes
- **Real-time Updates**: Instant message delivery and notifications
- **Customizable Interface**: Personalize your experience

## Tech Stack

- **React 18** - UI library
- **Vite** - Build tool and development server
- **Tailwind CSS** - Styling framework
- **TypeScript** - Type-safe JavaScript
- **React Icons** - Icon components

## Getting Started

### Prerequisites

- Node.js 18+ 
- npm or yarn

### Installation

```bash
# Navigate to the web directory
cd dyrak-dgram/web

# Install dependencies
npm install
```

### Development

```bash
# Start development server
npm run dev

# Build for production
npm run build

# Preview production build
npm run preview
```

## Project Structure

```
web/
├── src/
│   ├── assets/
│   │   └── logo.svg
│   ├── App.jsx          # Main application component
│   ├── main.jsx         # Application entry point
│   └── index.css        # Global styles and Tailwind imports
├── index.html           # HTML template
├── vite.config.js       # Vite configuration
├── tailwind.config.js   # Tailwind CSS configuration
├── postcss.config.js    # PostCSS configuration
└── package.json         # Dependencies and scripts
```

## Development

The web frontend is designed to work seamlessly with the Tauri desktop application and mobile versions. It includes:

- Responsive layout for all screen sizes
- Dark mode toggle functionality  
- Message chat interface
- Contact list management
- Settings panel
- Mobile sidebar navigation

## Deployment

The web app can be deployed to any static hosting service:

- Vercel
- Netlify
- GitHub Pages
- Your personal domain

## License

MIT License - See LICENSE file for details.

---

**Note**: This web frontend is part of the larger dyrakDGram project and integrates with all desktop plugins including:
- FakePaymentInterceptorPlugin
- MKFuckPaymentsPlugin  
- UnlockStarsContentPlugin
- LocalTelegramPremiumPlugin
- SpotyDownPlugin
