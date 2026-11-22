const form = document.getElementById("profileForm");
const resultsDiv = document.getElementById("results");
const submitBtn = document.getElementById("submitBtn");
const resumeInput = document.getElementById("resume");
const resumeMessage = document.getElementById("resumeMessage");
const resultCount = document.getElementById("resultCount");


// Resume se skills detect karna
resumeInput.addEventListener("change", function() {

    const file = resumeInput.files[0];

    if (!file) {
        return;
    }

    if (!file.name.toLowerCase().endsWith(".txt")) {
        resumeMessage.textContent = "Please upload a TXT file.";
        resumeInput.value = "";
        return;
    }

    const reader = new FileReader();

    reader.onload = function() {

        const resumeText = reader.result.toLowerCase();

        const knownSkills = [
            "python", "java", "c++", "c", "sql",
            "html", "css", "javascript", "react",
            "git", "machine learning", "deep learning",
            "data science", "excel", "django",
            "flask", "node.js", "mongodb"
        ];

        const detectedSkills = [];

        knownSkills.forEach(function(skill) {

            const escapedSkill = skill.replace(/[.*+?^${}()|[\]\\]/g, "\\$&");
            const pattern = new RegExp("(^|[^a-z0-9])" + escapedSkill + "([^a-z0-9]|$)", "i");

            if (pattern.test(resumeText)) {
                detectedSkills.push(skill);
            }
        });

        if (detectedSkills.length === 0) {
            resumeMessage.textContent = "No known skills detected. Enter skills manually.";
            return;
        }

        document.getElementById("skills").value = detectedSkills.join(", ");
        resumeMessage.textContent =
            "Detected skills: " + detectedSkills.join(", ");
    };

    reader.onerror = function() {
        resumeMessage.textContent = "Unable to read this file.";
    };

    reader.readAsText(file);
});


// Internship result card banana
function createInternshipCard(internship, index) {

    const card = document.createElement("div");
    card.className = "result-card";

    const rank = document.createElement("p");
    rank.textContent = "MATCH #" + (index + 1);

    const title = document.createElement("h3");
    title.textContent = internship.title;

    const company = document.createElement("p");
    company.className = "company-name";
    company.textContent = "Company: " + internship.company;

    const skillsHeading = document.createElement("p");
    skillsHeading.className = "skills-heading";
    skillsHeading.textContent = "Relevant Keywords";

    const skillsContainer = document.createElement("div");
    skillsContainer.className = "skill-tags";

    internship.skills.forEach(function(skill) {
        const tag = document.createElement("span");
        tag.className = "skill-tag";
        tag.textContent = skill;
        skillsContainer.appendChild(tag);
    });

    const score = document.createElement("p");
    score.className = "score";
    score.textContent = "Match Score: " + internship.score + "%";

    const progress = document.createElement("div");
    progress.className = "match-progress";

    const bar = document.createElement("div");
    bar.className = "match-progress-bar";
    bar.style.width = Math.max(0, Math.min(100, internship.score)) + "%";

    progress.appendChild(bar);

    card.appendChild(rank);
    card.appendChild(title);
    card.appendChild(company);
    card.appendChild(skillsHeading);
    card.appendChild(skillsContainer);
    card.appendChild(score);
    card.appendChild(progress);

    return card;
}


// Student profile submit karna
form.addEventListener("submit", async function(event) {

    event.preventDefault();

    const student = {
        name: document.getElementById("name").value.trim(),
        branch: document.getElementById("branch").value.trim(),
        year: parseInt(document.getElementById("year").value),
        cgpa: parseFloat(document.getElementById("cgpa").value),
        skills: document.getElementById("skills").value.trim()
    };

    submitBtn.disabled = true;
    submitBtn.textContent = "Finding Matches...";
    resultsDiv.innerHTML = "<p>Fetching internships, please wait...</p>";

    try {

        const response = await fetch("/match", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(student)
        });

        const data = await response.json();

        if (!response.ok) {
            throw new Error(data.error || "Something went wrong.");
        }

        resultsDiv.innerHTML = "";

        if (data.length === 0) {

            const empty = document.createElement("div");
            empty.className = "empty-state";

            const heading = document.createElement("h3");
            heading.textContent = "No matching internships found";

            const message = document.createElement("p");
            message.textContent = "Try adding more relevant skills to your profile.";

            empty.appendChild(heading);
            empty.appendChild(message);
            resultsDiv.appendChild(empty);

            resultCount.textContent = "0 MATCHES";
            return;
        }

        data.forEach(function(internship, index) {

            const card = createInternshipCard(internship, index);
            resultsDiv.appendChild(card);

        });

        resultCount.textContent = data.length + " MATCHES";

    }
    catch (error) {

        resultsDiv.innerHTML = "";

        const message = document.createElement("div");
        message.className = "error-message";
        message.textContent = error.message;

        resultsDiv.appendChild(message);
        resultCount.textContent = "ERROR";
    }
    finally {

        submitBtn.disabled = false;
        submitBtn.textContent = "Find My Internships →";
    }
});


// GOOGLE AUTHENTICATION

const loginScreen = document.getElementById("loginScreen");
const googleLoginBtn = document.getElementById("googleLoginBtn");
const loginMessage = document.getElementById("loginMessage");
const navbar = document.querySelector(".navbar");
const mainContainer = document.querySelector("main.container");

const logoutBtn = document.getElementById("logoutBtn");
const userName = document.getElementById("userName");
const userEmail = document.getElementById("userEmail");
const userPhoto = document.getElementById("userPhoto");


// Google login button
googleLoginBtn.addEventListener("click", async function() {

    googleLoginBtn.disabled = true;
    googleLoginBtn.textContent = "Connecting to Google...";
    loginMessage.textContent = "";

    try {

        await window.firebaseReady;

        await window.firebaseAuth.signInWithPopup(
            window.googleProvider
        );

    }
    catch (error) {

        console.error("Google login error:", error);

        loginMessage.textContent =
            error.message || "Unable to sign in. Please try again.";

    }
    finally {

        googleLoginBtn.disabled = false;
        googleLoginBtn.innerHTML =
            "<span>G</span> Continue with Google";
    }
});


// Check login status
window.firebaseAuth.onAuthStateChanged(function(user) {

    if (user) {

        loginScreen.hidden = true;
        navbar.hidden = false;
        mainContainer.hidden = false;

        userName.textContent = user.displayName || "Student";
        userEmail.textContent = user.email || "";

        userPhoto.src =
            user.photoURL || "https://placehold.co/100x100";

    }
    else {

        loginScreen.hidden = false;
        navbar.hidden = true;
        mainContainer.hidden = true;

    }
});


// Logout button
logoutBtn.addEventListener("click", async function() {

    try {

        await window.firebaseAuth.signOut();

    }
    catch (error) {

        alert("Unable to sign out. Please try again.");

    }
});

