#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Producto {
public:
    string Grupo;
    string Codigo_de_Barras;
    string Articulo;
    string Deposito1;
    string Deposito2;
    string Deposito3;
    string Deposito4;
};

int main() {
    const string Nombre_Archivo = "C:\\Users\\Juan Arcando\\OneDrive\\Escritorio\\ProytectoFinalProgramacion3\\Inventariado Fisico.csv";

    ifstream archivo(Nombre_Archivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string linea;
    char delimitador = ',';

    vector<Producto> productos; // Almacenar los productos en un vector

    // Leer la primera línea (encabezados) y descartarla si es necesario
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream stream(linea);
        Producto producto;

        // Leer y asignar los campos a los atributos del objeto Producto
        getline(stream, producto.Grupo, delimitador);
        getline(stream, producto.Codigo_de_Barras, delimitador);
        getline(stream, producto.Articulo, delimitador);
        getline(stream, producto.Deposito1, delimitador);
        getline(stream, producto.Deposito2, delimitador);
        getline(stream, producto.Deposito3, delimitador);
        getline(stream, producto.Deposito4, delimitador);

        // Agregar el producto al vector
        productos.push_back(producto);
    }

    archivo.close();

    // Iterar a través del vector y mostrar los productos en el orden del archivo CSV
    cout << "Productos en el orden en el que aparecen en el archivo CSV:" << endl;

    for (const Producto& producto : productos) {
        cout << "Grupo: " << producto.Grupo << endl;
        cout << "Código de Barras: " << producto.Codigo_de_Barras << endl;
        cout << "Artículo: " << producto.Articulo << endl;
        cout << "Depósito 1: " << producto.Deposito1 << endl;
        cout << "Depósito 2: " << producto.Deposito2 << endl;
        cout << "Depósito 3: " << producto.Deposito3 << endl;
        cout << "Depósito 4: " << producto.Deposito4 << endl;
        cout << "---------------------" << endl;
    }

    return 0;
}
