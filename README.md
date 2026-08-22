# InternMatch

### DSA & OOP Based Internship Recommendation & Skill-Gap Analysis System

**InternMatch** is a C++ based project that helps students identify suitable internship opportunities based on their skills and eligibility.

---

## Problem

Students often have to manually search through multiple internships and compare their skills with different requirements.

## Proposed Solution

InternMatch will:

- **Check Eligibility** based on CGPA and branch
- **Compare Skills** between the student and internship requirements
- **Calculate Match Percentage**
- **Identify Skill Gaps**
- **Rank Internships** based on match percentage

---

## Proposed Workflow

```text
┌─────────────────────┐
│   Student Profile   │
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
