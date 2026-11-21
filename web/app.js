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
    company.textContent = "Company: " + internship.company;

    const skills = document.createElement("p");
    skills.textContent = "Relevant Keywords: " + internship.skills.join(", ");

    const score = document.createElement("p");
    score.className = "score";
    score.textContent = "Match Score: " + internship.score + "%";

    const progress = document.createElement("div");
    progress.style.height = "8px";
    progress.style.marginTop = "10px";
    progress.style.background = "#e8edf5";
    progress.style.borderRadius = "10px";
    progress.style.overflow = "hidden";

    const bar = document.createElement("div");
    bar.style.height = "100%";
    bar.style.width = Math.max(0, Math.min(100, internship.score)) + "%";
    bar.style.background = "#3975dc";
    bar.style.borderRadius = "10px";

    progress.appendChild(bar);

    card.appendChild(rank);
    card.appendChild(title);
    card.appendChild(company);
    card.appendChild(skills);
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
