let searchForm = document.querySelector('.search-form');
let shoppingCart = document.querySelector('.cart-items-container');
let menuContainer = document.querySelector('.menu-container');

// Toggle Search
document.querySelector('.search-icon').onclick = () => {
    searchForm.classList.toggle('active');
    shoppingCart.classList.remove('active');
    menuContainer.classList.remove('active');
};

// Toggle Cart
document.querySelector('.cart-icon').onclick = () => {
    shoppingCart.classList.toggle('active');
    searchForm.classList.remove('active');
    menuContainer.classList.remove('active');
};

// Toggle Menu
document.querySelector('.menu-icon').onclick = () => {
    menuContainer.classList.toggle('active');
    searchForm.classList.remove('active');
    shoppingCart.classList.remove('active');
};

// Close all on scroll
window.onscroll = () => {
    searchForm.classList.remove('active');
    shoppingCart.classList.remove('active');
    menuContainer.classList.remove('active');
};
// Existing elements
let authModal = document.querySelector('#auth-modal');
let userIcon = document.querySelector('#user-profile-icon');

// 1. Open Auth Modal when clicking Login/Signup in your Menu Container
document.querySelectorAll('.menu-container a').forEach(link => {
    if(link.innerText === "Login/Signup") {
        link.onclick = (e) => {
            e.preventDefault();
            authModal.classList.add('active');
            menuContainer.classList.remove('active'); // Close menu
        }
    }
});

// 2. Close Modal
document.querySelector('#close-auth').onclick = () => {
    authModal.classList.remove('active');
};

// 3. Toggle between Login and Signup inside Modal
document.querySelector('#go-to-signup').onclick = () => {
    document.querySelector('.login').style.display = 'none';
    document.querySelector('.signup').style.display = 'block';
};

document.querySelector('#go-to-login').onclick = () => {
    document.querySelector('.signup').style.display = 'none';
    document.querySelector('.login').style.display = 'block';
};

// 4. Simulate Completion (Login/Signup)
const handleAuth = () => {
    authModal.classList.remove('active');
    userIcon.style.display = 'inline-block'; // Show the Profile Picture Icon!
    alert("Profile Created Successfully!");
    authModal.classList.remove('active');
    userIcon.style.display = 'flex'; 
    
    // If user didn't upload anything, use a default image
    if (!uploadInput.files[0]) {
        navbarProfileImg.src = "https://cdn-icons-png.flaticon.com/512/3135/3135715.png";
    }
    
    alert("Profile Created with your custom photo!");
};

document.querySelector('#login-submit-btn').onclick = handleAuth;
document.querySelector('#signup-submit-btn').onclick = handleAuth;
// Trigger hidden file input when clicking the circle
uploadPreview.onclick = () => uploadInput.click();

// Handle file selection and preview
uploadInput.onchange = function() {
    const file = this.files[0];
    if (file) {
        const reader = new FileReader();
        
        reader.onload = function(e) {
            // Update the preview in the signup form
            previewImg.src = e.target.result;
            previewImg.style.display = 'block';
            cameraIcon.style.display = 'none';
            
            // Set this image as the navbar icon for when they finish
            navbarProfileImg.src = e.target.result;
        }
        
        reader.readAsDataURL(file);
    }
}
// 1. Select the elements
const uploadInput = document.querySelector('#profile-upload-input');
const uploadContainer = document.querySelector('#upload-preview');
const previewImg = document.querySelector('#preview-img');
const cameraIcon = uploadContainer.querySelector('i');
const navAvatar = document.querySelector('#nav-avatar'); // The icon in your navbar

// 2. When the camera circle is clicked, trigger the hidden file input
uploadContainer.onclick = () => {
    uploadInput.click();
};

// 3. When the user selects a file
let uploadedImageData = ""; // Global variable to store the image

// 1. Handle the File Selection
document.getElementById('profile-upload-input').onchange = function() {
    const file = this.files[0];
    if (file) {
        const reader = new FileReader();
        reader.onload = function(e) {
            // Update the preview in the Signup box
            document.getElementById('preview-img').src = e.target.result;
            document.getElementById('preview-img').style.display = 'block';
            document.getElementById('camera-icon').style.display = 'none';
            
            // Store the data for later
            uploadedImageData = e.target.result;
        }
        reader.readAsDataURL(file);
    }
};

// 2. The "Create Profile" Button Logic
document.getElementById('signup-submit-btn').onclick = function() {
    const navIconContainer = document.getElementById('user-profile-icon');
    const navImg = document.getElementById('nav-avatar');
    const modal = document.getElementById('auth-modal');

    // Set the navbar image to the one uploaded
    if (uploadedImageData !== "") {
        navImg.src = uploadedImageData;
    }

    // Show the navbar icon and close the modal
    navIconContainer.style.display = 'flex';
    modal.classList.remove('active');
    
    alert("Profile Created Successfully!");
};