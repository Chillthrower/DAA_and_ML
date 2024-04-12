let signup = document.querySelector(".signup");
let login = document.querySelector(".login");
let slider = document.querySelector(".slider");
let foSection = document.querySelector(".form-section");

signup.addEventListener("click", () => {
    slider.classList.add("moveslider");
    foSection.classList.add("form-section-move");
});

login.addEventListener("click", () => {
    slider.classList.remove("moveslider");
    foSection.classList.remove("form-section-move");
});

function Validate() {
    var email = document.querySelector(".login-box .email").value;
    var password = document.querySelector(".login-box .password").value;

    if (email.trim() === '' || password.trim() === '') {
        alert("Error");
        return false;
    } else {
        // Removed the event binding from here
        return true; // Added a return statement to indicate validation success
    }
}

// Bind click event to login button
document.querySelector(".clkbtn").addEventListener("click", function() {
    if (Validate()) {
        // If validation succeeds, redirect to newPage.html
        window.location.href = "newPage.html";
    }
});
