// dyrakDGram Web Scripts

// Smooth scrolling for anchor links
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();
        const target = document.querySelector(this.getAttribute('href'));
        if (target) {
            target.scrollIntoView({ behavior: 'smooth' });
        }
    });
});

// Contact form submission handler
const contactForm = document.querySelector('.contact-form');
if (contactForm) {
    contactForm.addEventListener('submit', function(e) {
        e.preventDefault();
        alert('Благодарим ви за съобщението! Ще се свържем с вас скоро.');
        contactForm.reset();
    });
}

// Platform detection for download
const platforms = document.querySelectorAll('.platform-link');
platforms.forEach(platform => {
    platform.addEventListener('click', function(e) {
        const platformName = this.innerText.toLowerCase();
        console.log(`Download selected: ${platformName}`);
        // This would normally trigger a download
    });
});

// Mobile responsive adjustments
window.addEventListener('resize', function() {
    if (window.innerWidth < 768) {
        document.querySelector('.hero h1').style.fontSize = '2rem';
    }
});
