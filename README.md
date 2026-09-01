
# InternMatch

### DSA & OOP Based Internship Recommendation & Skill-Gap Analysis System

**InternMatch** is a C++ based project that helps students find suitable internship opportunities based on their skills, CGPA, branch, and eligibility requirements.

---

## Problem Statement

Students often have to manually search through multiple internship opportunities and compare their skills with different internship requirements. This process can take a lot of time, and students may apply for internships that do not match their profile.

---

## Proposed Solution

InternMatch aims to make the internship search process easier by checking student eligibility and matching their skills with internship requirements.

The system will:

- **Check Eligibility** based on CGPA and branch
- **Compare Skills** between the student and internship requirements
- **Calculate Match Percentage**
- **Identify Skill Gaps**
- **Rank Internships** based on match percentage
- **Display suitable internship opportunities**

---

## Proposed Workflow

```text
┌─────────────────────┐
│   Student Profile   │
│ CGPA, Branch, Skills│
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│  Eligibility Check  │
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│   Skill Matching    │
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│     Match Score     │
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│     Skill Gap       │
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│ Ranked Internships  │
└─────────────────────┘
Key Features
Student profile input
CGPA and branch based eligibility checking
Internship data fetching
Skill matching
Match percentage calculation
Skill-gap identification
Internship ranking
Technologies Used
C++ – Main programming language
Data Structures – Used for storing, searching, sorting, and matching internship data
OOP – Classes, objects, constructors, and encapsulation
libcurl – Used for making HTTP requests
nlohmann/json – Used for parsing JSON data
Arbeitnow Job Board API – Used for fetching internship/job listing data
Git & GitHub – Used for version control and project management
DSA & OOP Concepts
Data Structures
Arrays
Linked Lists
Searching
Sorting
OOP Concepts
Classes and Objects
Constructors
Encapsulation
API and Library Usage

The project uses external libraries and an API for fetching and processing internship data.

Arbeitnow Job Board API – Used to obtain internship/job listing data.
libcurl – Used to send HTTP requests and receive data from the API.
nlohmann/json – Used to parse and handle JSON responses.

All external resources are properly acknowledged in the References section.

Project Structure
InternMatch/
│
├── README.md
├── .gitignore
│
├── Phase-1/
│   ├── PPT/
│   └── Report/
│
├── Phase-2/
│   └── Code/
│
└── Phase-3/
    ├── Final-Code/
    ├── Testing/
    └── Output/
Project Phases
Phase 1 – Planning and Design
Problem identification
Requirement analysis
Proposed solution
System workflow
Technology selection
Project design
Phase 2 – Implementation
API integration
Data processing
DSA implementation
OOP implementation
Eligibility checking
Skill matching
Match percentage calculation
Skill-gap identification
Internship ranking
Phase 3 – Testing and Final Implementation
Testing of all modules
Error handling
Output verification
Final implementation
Final report and presentation
References
libcurl Documentation – https://curl.se/libcurl/
nlohmann/json Library – https://github.com/nlohmann/json
Arbeitnow Job Board API – https://www.arbeitnow.com/api/job-board-api
Team

Team ID: DSCPP-III-2026-T024

Team Members:

Jigyasa Rana – 2510380058 – ML2 – Team Lead
Masoom Singh – 2510370548 – ML1
Kashvi Pandey – 2510012207 – Cyber Security

Mentor: Dr. Siddhant Thapliyal

Department

Department of Computer Science & Engineering
Graphic Era (Deemed to be University), Dehradun

Academic Session: 2026–27
