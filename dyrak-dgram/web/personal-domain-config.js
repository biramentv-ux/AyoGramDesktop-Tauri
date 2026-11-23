// Personal Domain Configuration for dyrakDGram Web
// This file configures the web app to work with a custom domain

const config = {
  // Base URL for the personal domain
  baseUrl: '/',
  
  // Application settings
  appName: 'dyrakDGram Mobile',
  appVersion: '2.0.0',
  
  // Custom domain settings (update these for your domain)
  domain: {
    main: 'https://yourdomain.com',  // Replace with your actual domain
    cdn: 'https://cdn.yourdomain.com',
    api: 'https://api.yourdomain.com'
  },
  
  // Feature flags
  features: {
    darkMode: true,
    notifications: true,
    offlineMode: true
  },
  
  // API configuration
  api: {
    baseUrl: 'https://api.telegram.org/bot',
    timeout: 30000
  },
  
  // Storage configuration
  storage: {
    type: 'local',
    maxSize: 1024 * 1024 * 100  // 100MB
  },
  
  // Update configuration
  updates: {
    enabled: true,
    interval: 3600000, // 1 hour in milliseconds
    autoDownload: true
  }
};

// Export configuration for use in the app
export default config;

// Usage example:
// import config from './personal-domain-config.js';
// console.log(config.domain.main);
