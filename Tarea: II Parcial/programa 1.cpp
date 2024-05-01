//
//  programa 1.cpp
//  Tarea: II Parcial
//
//  Created by Luis Rivas on 1/05/24.
//

#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float promedio;
    bool aprobado;
};

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    Estudiante estudiantes[n];

    for (int i = 0; i < n; i++) {
        cout << "Ingrese datos del estudiante " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, estudiantes[i].nombres);
        cout << "Apellidos: ";
        getline(cin, estudiantes[i].apellidos);
        cout << "Nota 1: ";
        cin >> estudiantes[i].nota1;
        cout << "Nota 2: ";
        cin >> estudiantes[i].nota2;
        cout << "Nota 3: ";
        cin >> estudiantes[i].nota3;
        cout << "Nota 4: ";
        cin >> estudiantes[i].nota4;

        estudiantes[i].promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3 + estudiantes[i].nota4) / 4.0;

        if (estudiantes[i].promedio > 60) {
            estudiantes[i].aprobado = true;
        } else {
            estudiantes[i].aprobado = false;
        }
    }

    cout << "Resultados:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << estudiantes[i].id << ": " << estudiantes[i].nombres << " " << estudiantes[i].apellidos << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        if (estudiantes[i].aprobado) {
            cout << "Aprobó" << endl;
        } else {
            cout << "Reprobó" << endl;
        }
        cout << endl;
    }

    return 0;
}
