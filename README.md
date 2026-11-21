# InternMatch

## DSA & OOP-Based Internship Recommendation System

**InternMatch** is a C++-based internship recommendation system that helps students discover relevant job and internship opportunities based on their skills and academic profile.

The system retrieves job listings from the Arbeitnow Job Board API, processes the available data, compares student skills with job-related information, calculates a skill-match percentage, and displays the top 5 matching opportunities.

It also provides a web-based GUI where students can enter their profile details, upload a text-based resume (`.txt`), and view recommended opportunities.

The project demonstrates the practical application of **Data Structures and Algorithms (DSA)** and **Object-Oriented Programming (OOP)**.

## Project Objectives

- Retrieve job and internship listings using a public API.
- Collect student profile information and skills.
- Match student skills with relevant job information.
- Calculate a skill-match percentage.
- Rank opportunities according to their matching scores.
- Display the top 5 recommendations.
- Manage internship records using a linked-list data structure.
- Provide a simple web-based interface for students.

## Technologies Used

- **C++17** – Core programming language and backend logic.
- **Data Structures and Algorithms** – Linked lists, vectors, searching, and sorting.
- **Object-Oriented Programming** – Classes, objects, encapsulation, and inheritance.
- **libcurl** – Sending HTTP requests to the API.
- **nlohmann/json** – Parsing JSON responses.
- **cpp-httplib** – Creating the local HTTP server.
- **HTML, CSS, JavaScript** – Frontend interface.
- **Arbeitnow Job Board API** – Retrieving job listing data.
- **Git and GitHub** – Version control and collaboration.

## DSA and OOP Concepts

### Data Structures and Algorithms

- **Singly Linked List:** Stores and manages internship records.
- **Vectors:** Stores and processes internship data for ranking.
- **Linear Searching:** Compares student skills with job-related information.
- **Sorting:** Arranges opportunities according to their match percentages.
- **Top 5 Selection:** Displays the five highest-ranked matching opportunities.

### Object-Oriented Programming

- Classes and objects
- Constructors
- Encapsulation
- Inheritance
- Header files (`.h`) and implementation files (`.cpp`)

### Main Classes and Components

- **Person:** Base class containing common personal information.
- **Student:** Represents the student profile and skills. Inherits from `Person`.
- **Internship:** Stores information about individual job opportunities.
- **LinkedList:** Manages internship records using linked-list operations.
- **MatchEngine:** Handles API data retrieval, filtering, skill matching, match percentage calculation, and ranking.

## System Workflow

1. The student enters their name, branch, academic year, CGPA, and skills.
2. Alternatively, the student can upload a `.txt` resume to detect supported skills automatically.
3. The frontend sends the student profile to the C++ backend.
4. The backend retrieves job listings from the Arbeitnow API using libcurl.
5. The JSON response is parsed using nlohmann/json.
6. Internship records are processed and stored using the linked-list structure.
7. The matching engine compares student skills with relevant job information.
8. Match percentages are calculated and opportunities are sorted.
9. The top 5 recommendations are returned and displayed on the GUI.

## API and Libraries

- **Arbeitnow Job Board API:** Provides job listing data.
- **libcurl:** Handles HTTP requests to retrieve API data.
- **nlohmann/json:** Parses JSON data received from the API.
- **cpp-httplib:** Provides the local server that connects the frontend with the C++ backend.

**Note:** The public API does not necessarily provide college-specific eligibility information such as minimum CGPA or eligible branches. The student profile collects these details, but the current recommendation workflow primarily uses skill matching. The system should not be treated as an official eligibility verification platform.

## Resume Upload Feature

InternMatch includes a basic resume skill-detection feature.

- Accepts text files (`.txt`).
- Detects supported technical skills using predefined keywords.
- Automatically fills the skills field.
- Allows students to enter or edit their remaining profile information manually.

**Note:** This is keyword-based detection, not an AI-powered resume parser. PDF and DOCX resume parsing are not currently supported.

## Project Progress

### Phase 1 – Completed

- Finalized the problem statement and project objectives.
- Designed the initial project workflow.
- Created the `Student` and `Internship` classes.
- Integrated the Arbeitnow Job Board API.
- Implemented API data retrieval and JSON parsing.

### Phase 2 – Completed

- Organized the code into header (`.h`) and implementation (`.cpp`) files.
- Implemented the `Person` base class and `Student` inheritance.
- Developed a linked-list structure for internship data management.
- Implemented skill matching and match percentage calculation.
- Added sorting and ranking of internship opportunities.
- Integrated the matching engine with the internship data structure.

### Phase 3 – Implemented

- Developed a menu-driven C++ interface.
- Created a web-based GUI using HTML, CSS, and JavaScript.
- Integrated the GUI with the C++ backend using cpp-httplib.
- Added student profile submission through the web interface.
- Implemented `.txt` resume upload with keyword-based skill detection.
- Added recommendation cards with match percentages.
- Added sample demo resumes for testing.

## Repository Structure

```text
InternMatch/
├── Code/
│   ├── main.cpp
│   ├── Student.h
│   ├── Student.cpp
│   ├── Person.h
│   ├── Person.cpp
│   ├── Internship.h
│   ├── Internship.cpp
│   ├── LinkedList.h
│   ├── LinkedList.cpp
│   ├── MatchEngine.h
│   ├── MatchEngine.cpp
│   ├── json.hpp
│   └── httplib.h
│
├── web/
│   ├── index.html
│   ├── style.css
│   └── app.js
│
├── demo_resumes/
│   ├── ML_Student.txt
│   ├── Web_Developer.txt
│   └── Data_Science.txt
│
└── README.md
```

## How to Compile and Run

### Prerequisites

- C++ compiler supporting C++17
- libcurl installed
- Internet connection for API access

### Compile

Run the following command from the project root directory:

```bash
g++ -std=c++17 -ICode Code/*.cpp -o internmatch_test -lcurl -pthread
```

### Run

```bash
./internmatch_test
```

### Available Menu Options

1. Enter Student Profile
2. Find Internship Matches
3. Open GUI
4. Exit

To access the GUI:

1. Run the compiled program.
2. Select option `3`.
3. Open the following address in your browser:

```text
http://localhost:8080
```

Keep the terminal running while using the GUI.

## Assumptions and Limitations

- Recommendations depend on the job data available through the Arbeitnow API.
- The API may not provide complete or standardized skill requirements.
- Matching depends on the skills entered by the student and relevant information extracted from job listings.
- Resume skill detection currently supports `.txt` files and predefined keywords.
- Name, branch, academic year, and CGPA must be entered manually when using resume upload.
- The current system does not perform official CGPA-based or branch-based eligibility verification.
- The recommendation score indicates skill relevance and should not be interpreted as a guarantee of selection.

## Future Scope

- Support PDF and DOCX resume parsing.
- Implement more detailed skill-gap analysis.
- Add configurable eligibility criteria for CGPA and branch.
- Improve matching using advanced NLP techniques.
- Add filters for location, job type, and experience level.
- Store student profiles and application history.

## References

- [libcurl Documentation](https://curl.se/libcurl/)
- [nlohmann/json Library](https://github.com/nlohmann/json)
- [cpp-httplib](https://github.com/yhirose/cpp-httplib)
- [Arbeitnow Job Board API](https://www.arbeitnow.com/api/job-board-api)

## Team

**Team ID:** DSCPP-III-2026-T024

- **Jigyasa Rana** – ML2 – Team Lead
- **Masoom Singh** – ML1
- **Kashvi Pandey** – Cyber Security

**Mentor:** Dr. Siddhant Thapliyal

---

## About

InternMatch demonstrates how DSA and OOP concepts can be applied to build a practical internship recommendation system. By combining API-based job retrieval, skill matching, linked-list management, ranking algorithms, and a web-based interface, it helps students explore opportunities relevant to their technical skills.
