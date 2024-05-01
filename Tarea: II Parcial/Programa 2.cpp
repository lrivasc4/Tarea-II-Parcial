//
//  Programa 2.cpp
//  Tarea: II Parcial
//
//  Created by Luis Rivas on 1/05/24.
//

#include <iostream>
using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float promedio;
    bool aprobado;
};

void obtenerDatosEstudiante(Estudiante* estudiante) {
    cout << "Ingrese el ID del estudiante: ";
    cin >> estudiante->id;

    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante->nombre;

    cout << "Ingrese el apellido del estudiante: ";
    cin >> estudiante->apellido;

    cout << "Ingrese la nota 1: ";
    cin >> estudiante->nota1;

    cout << "Ingrese la nota 2: ";
    cin >> estudiante->nota2;

    cout << "Ingrese la nota 3: ";
    cin >> estudiante->nota3;

    cout << "Ingrese la nota 4: ";
    cin >> estudiante->nota4;

    estudiante->promedio = (estudiante->nota1 + estudiante->nota2 + estudiante->nota3 + estudiante->nota4) / 4;

    if (estudiante->promedio >= 60) {
        estudiante->aprobado = true;
    } else {
        estudiante->aprobado = false;
    }
}

void imprimirDatosEstudiante(Estudiante* estudiante) {
    cout << "ID del estudiante: " << estudiante->id << endl;
    cout << "Nombre del estudiante: " << estudiante->nombre << endl;
    cout << "Apellido del estudiante: " << estudiante->apellido << endl;
    cout << "Nota 1: " << estudiante->nota1 << endl;
    cout << "Nota 2: " << estudiante->nota2 << endl;
    cout << "Nota 3: " << estudiante->nota3 << endl;
    cout << "Nota 4: " << estudiante->nota4 << endl;
    cout << "Promedio: " << estudiante->promedio << endl;

    if (estudiante->aprobado) {
        cout << "Aprobado" << endl;
    } else {
        cout << "No aprobado" << endl;
    }
}

int main() {
    int numEstudiantes;
    Estudiante* estudiantes;

    cout << "Ingrese el número de estudiantes: ";
    cin >> numEstudiantes;

    estudiantes = new Estudiante[numEstudiantes];

    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nIngrese los datos del estudiante " << i + 1 << ":" << endl;
        obtenerDatosEstudiante(&estudiantes[i]);
    }

    cout << "\nDatos de los estudiantes:" << endl;
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        imprimirDatosEstudiante(&estudiantes[i]);
    }

    delete[] estudiantes;

    return 0;
}
