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

## Team

| Name | Role | Student ID |
|---|---|
| Jigyasa Rana | Team Lead |
| Masoom Singh | Member | 
| Kashvi Pandey | Member |

**Project ID:** DSCPP-III-2026-T024
**Mentor:** Dr. Siddhant Thapliyal

## Technologies Used
- C++
- DSA (Linked List, Sorting, Searching)
- OOP (Classes, Encapsulation)
- libcurl
- nlohmann/json
- Arbeitnow Job Board API

## Project Roadmap

**Phase 1 (Ongoing)**
- Finalize requirements and workflow
- Design Student and Internship classes
- Implement real-time internship data fetching using a public API
- Handle fetched data using JSON

**Phase 2**
- Store internship data in a Linked List
- Check eligibility based on CGPA and branch
- Implement skill searching and matching
- Calculate match percentage and skill gap
- Implement sorting

**Phase 3**
- Recommend internships based on match percentage
- Show skill gap as final output
- Test with multiple student profiles
- Complete final documentation

## Repository Structure

```
InternMatch/
├── Phase-1/
│   ├── PPT/
│   ├── Report/
│   └── Code/
└── README.md
```

## How to Compile and Run

```bash
g++ main.cpp -I/opt/homebrew/opt/curl/include -L/opt/homebrew/opt/curl/lib -lcurl -o main
./main
```

## Assumptions

Since public APIs do not provide college-specific fields such as minimum CGPA or eligible branch, fixed representative values are used for these fields for demonstration purposes.

## References
- libcurl Documentation: https://curl.se/libcurl/
- nlohmann/json Library: https://github.com/nlohmann/json
- Arbeitnow Job Board API: https://www.arbeitnow.com/api/job-board-api
```
