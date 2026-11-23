// Initialize application
document.addEventListener('DOMContentLoaded', () => {
    console.log('dyrakDGram web interface loaded');
    
    // Add event listeners for all interactive elements
    document.querySelectorAll('.btn').forEach(button => {
        button.addEventListener('click', (e) => {
            const pluginName = e.target.closest('.plugin-card').querySelector('.plugin-name').textContent;
            console.log(`Button clicked in ${pluginName}`);
        });
    });
    
    // Auto-focus search inputs
    document.getElementById('spotifyTrackId').addEventListener('focus', () => {
        console.log('Focus on Spotify Track ID input');
    });
});

// Theme toggle functionality
function toggleTheme() {
    const body = document.body;
    if (body.style.backgroundColor === '#17212b') {
        body.style.backgroundColor = '#ffffff';
        body.style.color = '#17212b';
    } else {
        body.style.backgroundColor = '#17212b';
        body.style.color = '#ffffff';
    }
}

// Responsive design
function resizeHandler() {
    const screenWidth = window.innerWidth;
    if (screenWidth < 768) {
        console.log('Mobile view activated');
    } else {
        console.log('Desktop view activated');
    }
}

window.addEventListener('resize', resizeHandler);
