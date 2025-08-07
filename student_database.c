#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INITIAL_CAPACITY 80 //Capacidad inicial del arreglo de estudiantes
#define INCREMENT 10 // Incremento de capacidad para redimensionamiento dinámico

//Estructura que representa a un estudiante

struct Student {
	char name[40]; //Nombre del estudiante
	int id; // ID del estudiante
	float grades[3]; // Tres calificaciones del estudiante
};

//Lista de nombres predefinidos para asignación aleatoria
const char* studentNames[] = {
	"Andrea", "Juan", "Sofía", "Marco", "Elena",
		"Diego", "Carla", "Pablo", "Valeria", "Luis"
};

/*
 Limpia la pantalla de la terminal
 Usa comandos del sistema para limpiar, cls para windows y clear en linux
*/


void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

/* Imprime una calificación con un color distinto dependiendo de su valor
Rojo < 7 | Amarillo {7.0,...,8.5} | Verde > 8.5
*/

void printGrade(float grade) {
	if (grade < 7.0) {
		printf("\033[0;31m%.1f\033[0m", grade); // Red for < 7.0
	} else if (grade <= 8.5) {
		printf("\033[0;33m%.1f\033[0m", grade); // Yellow for 7.0-8.5
	} else {
		printf("\033[0;32m%.1f\033[0m", grade); // Green for > 8.5
	}
}


/* 
 Llenar un arreglo de estudiantes con datos aleatorios
 nombres, matrículas, 3 calificaciones entre 0 y 10
*/

void fillRandomStudents(struct Student *students, int count) {
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		strcpy(students[i].name, studentNames[rand() % 10]);
		students[i].id = 10000 + rand() % 90000;
		for (int j = 0; j < 3; j++) {
			students[i].grades[j] = (rand() % 101) / 10.0;
		}
	}
}

void registerNewStudent(struct Student **students, int *count, int *capacity) {
	clearScreen();
	if (*count >= *capacity) {
		*capacity += INCREMENT;
		*students = realloc(*students, *capacity * sizeof(struct Student));
		if (*students == NULL) {
			printf("Memory allocation failed!\n");
			exit(1);
		}
	}
	struct Student *newStudent = &(*students)[*count];
	printf("Enter student name: ");
	scanf(" %[^\n]", newStudent->name);
	printf("Enter student ID (5 digits): ");
	scanf("%d", &newStudent->id);
	printf("Enter 3 grades (0-100, e.g., 67 for 6.7): ");
	for (int i = 0; i < 3; i++) {
		int inputGrade;
		scanf("%d", &inputGrade);
		newStudent->grades[i] = inputGrade / 10.0; // Convert to decimal
	}
	printf("Student registered successfully!\n");
	(*count)++;
}

/* 
Muestra todos los registros de estudiantes
incluye nombre, matrícula y calificaciones coloreadas
*/


void viewAllRecords(struct Student *students, int count) {
	clearScreen();
	if (count == 0) {
		printf("No students registered.\n");
	} else {
		for (int i = 0; i < count; i++) {
			printf("Name: %s, ID: %d, Grades: ", students[i].name, students[i].id);
			for (int j = 0; j < 3; j++) {
				printf("UNIT %d | ", j + 1);
				printGrade(students[i].grades[j]);
				if (j < 2) printf(", ");
			}
			printf("\n");
		}
	}
	printf("\nPress 'e' to return to menu: ");
	while (getchar() != 'e'); // Espera al usuario para volver
}


/* 
Calcula y muesta estadísticas generales: promedio general, cantidad de aprobados y reprobados por unidad, estudiante con mejor promedio
*/


void calculateStatistics(struct Student *students, int count) {
	clearScreen();
	if (count == 0) {
		printf("No students registered.\n");
	} else {
		float generalSum = 0;
		int approved[3] = {0}, failed[3] = {0};
		float maxAvg = -1;
		char bestStudent[40];
		int bestID;
		
		for (int i = 0; i < count; i++) {
			float sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += students[i].grades[j];
				if (students[i].grades[j] >= 7.0) { // Changed to 7.0
					approved[j]++;
				} else {
					failed[j]++;
				}
			}
			generalSum += sum;
			float avg = sum / 3;
			if (avg > maxAvg) {
				maxAvg = avg;
				strcpy(bestStudent, students[i].name);
				bestID = students[i].id;
			}
		}
		printf("General Average: %.2f\n", generalSum / (count * 3));
		for (int j = 0; j < 3; j++) {
			printf("Unit %d - Approved: %d, Failed: %d\n", j + 1, approved[j], failed[j]);
		}
		printf("Best Student: %s (ID: %d, Avg: %.2f)\n", bestStudent, bestID, maxAvg);
	}
	printf("\nPress 'e' to return to menu: ");
	while (getchar() != 'e');
}

/*
Busca a un esstudiante por su matrícula. Si lo encuentra, muestra su información
Permite buscar múltiples veces hasta que salga
*/ 

void searchStudentByID(struct Student *students, int count) {
	clearScreen();
	while (1) {
		printf("Enter student ID (or 'e' to return): ");
		char input[10];
		scanf(" %[^\n]", input);
		if (input[0] == 'e') break;
		int id = atoi(input);
		int found = 0;
		for (int i = 0; i < count; i++) {
			if (students[i].id == id) {
				printf("Name: %s, ID: %d, Grades: ", students[i].name, students[i].id);
				for (int j = 0; j < 3; j++) {
					printf("UNIT %d | ", j + 1);
					printGrade(students[i].grades[j]);
					if (j < 2) printf(", ");
				}
				printf("\n");
				found = 1;
				break;
			}
		}
		if (!found) printf("Student not found.\n");
	}
}


/*
Muestra el menú principal del sistema y permite al usuario seleccionar una opcíon
*/


void displayMenu() {
	clearScreen();
	printf("1. Register new student\n");
	printf("2. View all records\n");
	printf("3. Calculate statistics\n");
	printf("4. Search student by ID\n");
	printf("5. Exit\n");
	printf("Choose an option: ");
}


/* Funcion principal del programa, inicia datos
muestra menú e interacción con el usuario
*/

int main() {
	int capacity = INITIAL_CAPACITY;
	struct Student *students = malloc(capacity * sizeof(struct Student));
	if (students == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}
	int count = 80; //Número inicial de estudiantes con datos aleatorios
	fillRandomStudents(students, count);
	int option;
	do {
		displayMenu();
		scanf("%d", &option);
		getchar(); //Limpia el bufer
		switch (option) {
		case 1: registerNewStudent(&students, &count, &capacity); break;
		case 2: viewAllRecords(students, count); break;
		case 3: calculateStatistics(students, count); break;
		case 4: searchStudentByID(students, count); break;
		case 5: printf("Exiting...\n"); break;
		default: printf("Invalid option. Try again.\n"); getchar();
		}
	} while (option != 5);
	free(students); // Libera memoria antes de salir
	return 0;
}
