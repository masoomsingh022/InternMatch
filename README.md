# InternMatch

## DSA & OOP Based Internship Recommendation & Skill-Gap Analysis System

InternMatch is a C++-based project that helps students find suitable internship opportunities based on their CGPA, branch, and skills.

## Project

The project focuses on:

* Internship Recommendation
* Eligibility Checking
* Skill Matching
* Skill-Gap Analysis
* Internship Ranking

The system uses DSA and OOP concepts to process internship data and provide relevant recommendations.

## Technologies Used

* C++
* DSA
* OOP
* libcurl – For HTTP requests
* nlohmann/json – For JSON parsing
* Arbeitnow Job Board API – For internship/job data
* Git & GitHub

## DSA & OOP Concepts

### DSA

* Arrays
* Linked Lists
* Searching
* Sorting

### OOP

* Classes and Objects
* Constructors
* Encapsulation
* Inheritance

### Classes Implemented

* Person
* Student
* Internship
* LinkedList

## API and Libraries Used

* Arbeitnow Job Board API – Used to fetch internship/job data.
* libcurl – Used to make HTTP requests.
* nlohmann/json – Used to parse JSON responses.

## Project Progress

**Phase 1 – Completed**

* Problem statement and objectives finalized
* Project workflow designed
* Internship data prepared
* Student data requirements finalized
* Student class created and tested
* Internship class created and tested
* Real-time API integration working

**Phase 2 – In Progress**

* Code separated into `.h` (declaration) and `.cpp` (implementation) files
* Person base class and Student inheritance implementation
* Linked List implementation for internship data storage
* Eligibility checking based on CGPA and branch
* Skill matching using linear searching
* Match percentage calculation
* Internship ranking using sorting based on match percentage
* Top internship recommendations

**Phase 3 – Planned**

* Complete system testing
* Final implementation and integration
* Output verification
* Final documentation

## Repository Structure

```text
InternMatch/
├── Code/
│   ├── Phase-1/
│   └── Phase-2/
├── Phase-1/
│   ├── PPT/
│   └── Report/
├── Phase-2/
│   ├── PPT/
│   └── Report/
└── README.md
```

## How to Compile and Run

```bash
g++ main.cpp Student.cpp Internship.cpp -I/opt/homebrew/opt/curl/include -L/opt/homebrew/opt/curl/lib -lcurl -o main ./main
```

## Assumptions

Since public APIs do not provide college-specific fields such as minimum CGPA or eligible branch, fixed representative values are used for these fields for demonstration purposes.

## References

* libcurl Documentation – https://curl.se/libcurl/
* nlohmann/json Library – https://github.com/nlohmann/json
* Arbeitnow Job Board API – https://www.arbeitnow.com/api/job-board-api

## Team

**Team ID:** DSCPP-III-2026-T024

* Jigyasa Rana – ML2 – Team Lead
* Masoom Singh – ML1
* Kashvi Pandey – Cyber Security

**Mentor:** Dr. Siddhant Thapliyal

## About

DSA & OOP based internship recommendation and skill-gap analysis system.
