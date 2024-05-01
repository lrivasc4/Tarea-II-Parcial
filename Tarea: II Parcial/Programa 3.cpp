//
//  Programa 3.cpp
//  Tarea: II Parcial
//
//  Created by Luis Rivas on 1/05/24.
//

#include <iostream>
#include <fstream>
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

void guardarEstudiantes(Estudiante* estudiantes, int numEstudiantes) {
    ofstream outFile("notas.dat", ios::binary);

    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<char*>(estudiantes), numEstudiantes * sizeof(Estudiante));
        outFile.close();
    } else {
        cout << "Error: No se pudo abrir el archivo." << endl;
    }
}

void cargarEstudiantes(Estudiante* estudiantes, int& numEstudiantes) {
    ifstream inFile("notas.dat", ios::binary);

    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(estudiantes), sizeof(Estudiante));

        while (!inFile.eof()) {
            numEstudiantes++;
            inFile.read(reinterpret_cast<char*>(estudiantes + numEstudiantes), sizeof(Estudiante));
        }

        inFile.close();
    } else {
        cout << "Error: No se pudo abrir el archivo." << endl;
    }
}

void actualizarEstudiante(Estudiante* estudiantes, int numEstudiantes) {
    int id;
    bool encontrado = false;

    cout << "Ingrese el ID del estudiante a actualizar: ";
    cin >> id;

    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].id == id) {
            obtenerDatosEstudiante(&estudiantes[i]);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Error: Estudiante no encontrado." << endl;
    }
}

void eliminarEstudiante(Estudiante* estudiantes, int& numEstudiantes) {
    int id;
    bool encontrado = false;

    cout << "Ingrese el ID del estudiante a eliminar: ";
    cin >> id;

    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].id == id) {
            for (int j = i; j < numEstudiantes - 1; j++) {
                estudiantes[j] = estudiantes[j + 1];
            }
            numEstudiantes--;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Error: Estudiante no encontrado." << endl;
    }
}

int main() {
    int opcion;
    int numEstudiantes = 0;
    Estudiante* estudiantes = new Estudiante[100];

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Actualizar estudiante" << endl;
        cout << "3. Eliminar estudiante" << endl;
        cout << "4. Mostrar estudiantes" << endl;
        cout << "5. Guardar estudiantes en archivo" << endl;
        cout << "6. Cargar estudiantes desde archivo" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                obtenerDatosEstudiante(&estudiantes[numEstudiantes]);
                numEstudiantes++;
                break;
            case 2:
                if (numEstudiantes > 0) {
                    actualizarEstudiante(estudiantes, numEstudiantes);
                } else {
                    cout << "No hay estudiantes para actualizar." << endl;
                }
                break;
            case 3:
                if (numEstudiantes > 0) {
                    eliminarEstudiante(estudiantes, numEstudiantes);
                } else {
                    cout << "No hay estudiantes para eliminar." << endl;
                }
                break;
            case 4:
                if (numEstudiantes > 0) {
                    for (int i = 0; i < numEstudiantes; i++) {
                        cout << "\nDatos del estudiante " << i + 1 << ":" << endl;
                        imprimirDatosEstudiante(&estudiantes[i]);
                    }
                } else {
                    cout << "No hay estudiantes para mostrar." << endl;
                }
                break;
            case 5:
                if (numEstudiantes > 0) {
                    guardarEstudiantes(estudiantes, numEstudiantes);
                } else {
                    cout << "No hay estudiantes para guardar." << endl;
                }
                break;
            case 6:
                cargarEstudiantes(estudiantes, numEstudiantes);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);

    delete[] estudiantes;

    return 0;
}
