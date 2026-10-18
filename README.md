# InternMatch

## DSA & OOP-Based Internship Recommendation and Skill-Gap Analysis System

**InternMatch** is a C++-based internship recommendation system that helps students identify suitable internship opportunities based on their CGPA, branch, and skills. It analyzes student profiles, checks eligibility, matches skills with internship requirements, and calculates a skill-match percentage to support relevant recommendations.

The project demonstrates the practical application of Data Structures and Algorithms (DSA) and Object-Oriented Programming (OOP).

## Project Objectives

- Recommend suitable internships based on student profiles.
- Check eligibility using CGPA and branch requirements.
- Match student skills with required internship skills.
- Calculate the percentage of matching skills.
- Identify missing skills to support skill-gap analysis.
- Rank internships based on their relevance to the student.
- Use linked lists and other DSA concepts to manage and process internship data.

## Technologies Used

- **C++** – Core programming language
- **Data Structures and Algorithms (DSA)** – Linked lists, searching, and sorting
- **Object-Oriented Programming (OOP)** – Classes, objects, encapsulation, and inheritance
- **libcurl** – For making HTTP requests
- **nlohmann/json** – For parsing JSON responses
- **Arbeitnow Job Board API** – For retrieving job and internship listings
- **Git and GitHub** – For version control and collaboration

## DSA and OOP Concepts

### Data Structures and Algorithms

- Arrays and vectors
- Linked lists for internship data management
- Linear searching for skill matching
- Sorting and ranking internships based on match percentage

### Object-Oriented Programming

- Classes and objects
- Constructors
- Encapsulation
- Inheritance
- Header files (`.h`) and implementation files (`.cpp`)

### Main Classes and Components

- **Person** – Base class for common personal information
- **Student** – Represents student details and skills
- **Internship** – Stores internship-related information and requirements
- **LinkedList** – Manages internship records using linked-list operations
- **MatchEngine** – Contains functions for eligibility checking, skill matching, and match percentage calculation

## API and Libraries

- **Arbeitnow Job Board API:** Provides job and internship listing data.
- **libcurl:** Handles HTTP requests to retrieve API data.
- **nlohmann/json:** Parses JSON data received from the API.

The project uses representative CGPA and branch requirements for demonstration because these fields are not necessarily provided by the public job-board API.

## Project Progress

### Phase 1 – Completed

- Finalized the problem statement and project objectives.
- Designed the initial project workflow.
- Created and tested the `Student` and `Internship` classes.
- Defined the student information and internship requirements.
- Integrated the Arbeitnow Job Board API.
- Implemented API data retrieval and JSON parsing.

### Phase 2 – In Progress

- Organized the code into header (`.h`) and implementation (`.cpp`) files.
- Implemented the `Person` base class and `Student` inheritance.
- Developed a linked-list structure for internship data management.
- Implemented eligibility checking based on CGPA and branch.
- Implemented skill matching using linear searching.
- Added match percentage calculation.
- Worked on internship ranking and top recommendations based on match percentage.
- Continued integrating the matching engine with the internship data structure.

### Phase 3 – Planned

- Complete integration of all modules.
- Test eligibility and skill-matching functions with different inputs.
- Verify internship ranking and recommendation results.
- Complete skill-gap analysis and output verification.
- Prepare final documentation and project demonstration.

## Repository Structure

```text
InternMatch/
├── Code/
│   ├── Phase-1/
│   │   ├── Student.h
│   │   ├── Internship.h
│   │   ├── MatchEngine.h
│   │   └── main.cpp
│   └── Phase-2/
│       ├── LinkedList.h
│       ├── LinkedList.cpp
│       ├── MatchEngine.h
│       └── MatchEngine.cpp
├── Phase-1/
│   ├── PPT/
│   └── Report/
├── Phase-2/
│   ├── PPT/
│   └── Report/
└── README.md
```

## How to Compile and Run

Compilation depends on the source files, header dependencies, and installed libraries.

For example, if the required source files and include paths are configured correctly:

```bash
g++ -std=c++17 main.cpp Student.cpp Internship.cpp \
-I/opt/homebrew/opt/curl/include \
-L/opt/homebrew/opt/curl/lib \
-lcurl -o main
```

Run the compiled program:

```bash
./main
```

## Assumptions and Limitations

- The public job-board API may not provide college-specific eligibility fields such as minimum CGPA or eligible branch.
- Representative values are used for these fields for demonstration purposes.
- Skill matching depends on the skills provided in the student profile and internship requirements.
- Recommendation accuracy depends on the availability and quality of internship data.

## References

- [libcurl Documentation](https://curl.se/libcurl/)
- [nlohmann/json Library](https://github.com/nlohmann/json)
- [Arbeitnow Job Board API](https://www.arbeitnow.com/api/job-board-api)

## Team

**Team ID:** DSCPP-III-2026-T024

- **Jigyasa Rana** – ML2 – Team Lead
- **Masoom Singh** – ML1
- **Kashvi Pandey** – Cyber Security

**Mentor:** Dr. Siddhant Thapliyal

## About

InternMatch applies DSA and OOP concepts to internship recommendation and skill-gap analysis, helping students explore opportunities aligned with their qualifications and skills.
