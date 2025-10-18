// Wait until the page is fully loaded
window.onload = function() {

  // 1️⃣ Change header color when clicked
  const header = document.querySelector("h1");
  if (header) {
    header.addEventListener("click", function() {
      header.style.color = "blue";
      alert("You clicked the header! 🌍");
    });
  }

  // 2️⃣ Show a welcome message when the page opens
  alert("Welcome to Travel Along! ✈️ Explore the world with us.");

  // 3️⃣ Simple hover effect for logo
  const logo = document.querySelector(".logo");
  if (logo) {
    logo.addEventListener("mouseenter", function() {
      logo.style.color = "aqua";
    });
    logo.addEventListener("mouseleave", function() {
      logo.style.color = "white";
    });
  }
};
