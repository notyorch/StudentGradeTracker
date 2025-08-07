Student Grade Tracking System

Project Overview
This project is a Student Grade Tracking System developed in C as part of the Programming course in the second semester of the Data Engineering program (TSU in Data Science) at UPY. The program manages student information, including names, matriculas, and grades for three subjects. It features a menu-driven interface with options to register students, view all records, calculate statistics (overall average, passed/failed per subject, and highest average), and search by matricula.
Author: Jorge Enrique Vargas PechMatricula: 2409244Career: TSU in Data ScienceSemester: SecondCourse: ProgrammingEmail: 
Features

Register New Student: Add a student with name, matricula (10000–99999), and grades (0–10) with input validation.
View All Records: Display all registered students with their names, matriculas, grades, and averages.
Calculate Averages: Compute the overall average, number of students who passed/failed each subject (passing grade ≥ 6), and identify the student with the highest average.
Search by Matricula: Find and display a student's details by their matricula.
Random Data Generation: Initialize up to 80 students with random names, matriculas, and grades.

Project Structure

student_grades.c: Main C source file containing the program implementation.
report.tex: LaTeX file for the project report (PDF generated with latexmk).
program_flow.mmd: Mermaid flowchart illustrating the program's workflow.

Setup Instructions

Clone the Repository:git clone https://github.com/your-username/student-grade-tracking-system.git


Compile the C Program:
Ensure you have a C compiler (e.g., gcc) installed.
Run:gcc student_grades.c -o student_grades




Run the Program:
Execute the compiled program:./student_grades




Generate the Report (optional):
Install latexmk and a LaTeX distribution (e.g., TeX Live).
Compile the report:latexmk -pdf report.tex




View the Flowchart:
Use a Mermaid-compatible tool (e.g., Mermaid Live Editor) to render program_flow.mmd.



Usage

Launch the program to access the main menu.
Select an option (1–5):
1: Register a new student (prompts for name, matricula, and grades).
2: View all student records.
3: Display general statistics (overall average, passed/failed counts, best student).
4: Search for a student by matricula.
5: Exit the program.


Follow prompts and ensure valid inputs (e.g., matricula between 10000–99999, grades between 0–10).

Project Report
The report (report.tex) is included in the repository and covers:

Description: Overview of the program's functionality and implementation.
Screenshots: Placeholder for program execution screenshots (menu, registration, records, statistics, search).
Challenges and Learnings: Discussion of challenges (e.g., input validation, modularization) and lessons learned (e.g., efficient use of structures, clear code organization).

To view the report, compile report.tex using latexmk or include the generated report.pdf in the repository.
Flowchart
The program_flow.mmd file contains a Mermaid flowchart illustrating the program's workflow, including menu navigation, input validation, and processing for each option. Render it using a Mermaid-compatible tool.
Requirements

C Compiler: GCC or any standard C compiler.
LaTeX Distribution: TeX Live for compiling the report (optional).
Mermaid Tool: For rendering the flowchart (optional).

Evaluation Criteria

Functionality: 30/100
Structures/Arrays: 20/100
Modularization: 15/100
Code Robustness: 15/100
Report: 10/100
Presentation/Clarity: 10/100

License
This project is for educational purposes and is not licensed for commercial use.

Contact: For questions or feedback, reach out via email.
