# Student Grade Tracking System

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Project Overview
This project is a **Student Grade Tracking System** developed in C as part of the Programming course in the second semester of the Data Engineering program (TSU in Data Science) at UPY. The program manages student information, including names, matriculas, and grades for three subjects. It features a menu-driven interface with options to register students, view all records, calculate statistics (overall average, passed/failed per subject, and highest average), and search by matricula.

**Author**: Jorge Enrique Vargas Pech  
**Matricula**: 2409244  
**Career**: TSU in Data Science  
**Semester**: Second  
**Course**: Programming  
**Email**: <a href="mailto:2409244@upy.edu.mx"><img src="https://img.shields.io/badge/Contact%20Me-Email-blue?style=for-the-badge" alt="Contact Me"></a>

## Features
- **Register New Student**: Add a student with name, matricula (10000–99999), and grades (0–10) with input validation.
- **View All Records**: Display all registered students with their names, matriculas, grades, and averages.
- **Calculate Averages**: Compute the overall average, number of students who passed/failed each subject (passing grade ≥ 6), and identify the student with the highest average.
- **Search by Matricula**: Find and display a student's details by their matricula.
- **Random Data Generation**: Initialize up to 80 students with random names, matriculas, and grades.

## Project Structure
- `student_grades.c`: Main C source file containing the program implementation.
- `report.tex`: LaTeX file for the project report (PDF generated with `latexmk`).
- `program_flow.mmd`: Mermaid flowchart illustrating the program's workflow.

## Setup Instructions
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/notyorch/StudentGradeTracker.git
