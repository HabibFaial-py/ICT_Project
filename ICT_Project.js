window.onload = function() {
  const header = document.querySelector("h1");
  if (header) {
    header.addEventListener("click", function() {
      header.style.color = "blue";
      alert("You clicked the header! 🌍");
    });
  }
  alert("Welcome to Travel Along! ✈️ Explore the world with us.");
};

function openPopup(){
  document.getElementById("bookingOverlay").style.display="flex";
}
function closePopup(){
  document.getElementById("bookingOverlay").style.display="none";
}

function submitForm(){
    const name = document.getElementById("name").value;
    const email = document.getElementById("email").value;
    const destination = document.getElementById("destination").value;
    if (name === "" || email === "" || destination === "") {
        alert("Please fill in all fields before submitting the form.");
    } else {
      alert(`Thank you, ${name}! Your booking to ${destination} has been received. We will contact you at ${email}. ✈️`);
      closePopup();
    }
}
