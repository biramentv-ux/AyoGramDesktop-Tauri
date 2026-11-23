// dyrakDGram Web Application JavaScript

document.addEventListener('DOMContentLoaded', () => {
    // Initialize application
    initApp();
});

function initApp() {
    console.log('dyrakDGram Web App initialized');
    
    // Smooth scrolling for anchor links
    document.querySelectorAll('a[href^="#"]').forEach(anchor => {
        anchor.addEventListener('click', function (e) {
            e.preventDefault();
            const target = document.querySelector(this.getAttribute('href'));
            if (target) {
                target.scrollIntoView({
                    behavior: 'smooth'
                });
            }
        });
    });
    
    // Menu toggle for mobile
    const menuToggle = document.querySelector('.menu-toggle');
    const navMenu = document.querySelector('.nav-menu');
    
    if (menuToggle && navMenu) {
        menuToggle.addEventListener('click', () => {
            navMenu.classList.toggle('active');
        });
    }
    
    // Download button click handler
    const downloadBtns = document.querySelectorAll('.btn-download');
    downloadBtns.forEach(btn => {
        btn.addEventListener('click', (e) => {
            e.preventDefault();
            console.log('Download initiated');
            showDownloadNotification();
        });
    });
}

function showDownloadNotification() {
    // Show download notification
    const notification = document.createElement('div');
    notification.className = 'download-notification';
    notification.innerHTML = `
        <div class="notification-content">
            <div class="notification-icon">⬇️</div>
            <div class="notification-text">
                <strong>Download Started</strong>
                <p>Your download will begin shortly...</p>
            </div>
            <button class="notification-close" onclick="this.parentElement.remove()">×</button>
        </div>
    `;
    document.body.appendChild(notification);
    
    // Auto remove after 3 seconds
    setTimeout(() => {
        if (notification.parentNode) {
            notification.style.opacity = '0';
            setTimeout(() => {
                if (notification.parentNode) {
                    notification.parentNode.removeChild(notification);
                }
            }, 300);
        }
    }, 3000);
}

// Initialize GitHub API integration
async function fetchGitHubInfo() {
    try {
        const response = await fetch('https://api.github.com/repos/dyrakdev/dyrakDGram');
        const data = await response.json();
        
        if (data) {
            console.log('Repository info:', data);
            updateGitHubStats(data);
        }
    } catch (error) {
        console.error('Error fetching GitHub data:', error);
    }
}

function updateGitHubStats(repoData) {
    // Update GitHub stars and forks count
    const starsEl = document.getElementById('github-stars');
    const forksEl = document.getElementById('github-forks');
    
    if (starsEl && repoData.stargazers_count) {
        starsEl.textContent = repoData.stargazers_count;
    }
    
    if (forksEl && repoData.forks_count) {
        forksEl.textContent = repoData.forks_count;
    }
}

// Telegram Web App integration
if (window.Telegram && window.Telegram.WebApp) {
    const telegramWebApp = window.Telegram.WebApp;
    
    telegramWebApp.ready();
    telegramWebApp.expand();
    
    console.log('Telegram Web App initialized');
}

// Export functions for external use
export { initApp, showDownloadNotification, fetchGitHubInfo };
