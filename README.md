# InternMatch

## DSA & OOP Based Internship Recommendation & Skill-Gap Analysis System

InternMatch is a C++-based project that helps students find suitable internship opportunities based on their CGPA, branch, and skills.

## Project

The project focuses on:
- Internship Recommendation
- Eligibility Checking
- Skill Matching
- Skill-Gap Analysis

The system uses DSA and OOP concepts to process internship data and provide relevant recommendations.

## Technologies Used
- C++
- DSA
- OOP
- libcurl – For HTTP requests
- nlohmann/json – For JSON parsing
- Arbeitnow Job Board API – For internship/job data
- Git & GitHub

## DSA & OOP Concepts

### DSA
- Arrays
- Linked Lists
- Searching
- Sorting

### OOP
- Classes and Objects
- Constructors
- Encapsulation

### Classes Implemented
- Student
- Internship

## API and Libraries Used
- Arbeitnow Job Board API – Used to fetch internship/job data.
- libcurl – Used to make HTTP requests.
- nlohmann/json – Used to parse JSON responses.

## Project Progress

**Phase 1 – In Progress**
- Problem statement and objectives finalized
- Project workflow designed
- Internship data prepared
- Student data requirements finalized
- Student class created
- Internship class created

**Phase 2 – Planned**
- API integration
- Data processing
- Eligibility checking
- Skill matching
- Match percentage calculation
- Skill-gap analysis
- Internship ranking

**Phase 3 – Planned**
- Testing
- Final implementation
- Output verification
- Final documentation

## Repository Structure

```text
InternMatch/
├── Phase-1/
│   ├── PPT/
│   ├── Report/
│   └── Code/
└── README.md
```


## How to Compile and Run

g++ main.cpp -I/opt/homebrew/opt/curl/include -L/opt/homebrew/opt/curl/lib -lcurl -o main
./main

## Assumptions

Since public APIs do not provide college-specific fields such as minimum CGPA or eligible branch, fixed representative values are used for these fields for demonstration purposes.


## References
- libcurl Documentation – https://curl.se/libcurl/
- nlohmann/json Library – https://github.com/nlohmann/json
- Arbeitnow Job Board API – https://www.arbeitnow.com/api/job-board-api

## Team
**Team ID:** DSCPP-III-2026-T024
- Jigyasa Rana – ML2 – Team Lead
- Masoom Singh – ML1
- Kashvi Pandey – Cyber Security

**Mentor:** Dr. Siddhant Thapliyal
