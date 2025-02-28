#include <iostream>
#include "Sistema.h"

#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"



std::string readLine() {
    std::string line;
    std::cin >> line;
    return line;
}

void readFile(Sistema* sistema) {
        //something something lasdfkjasd

}

void menu(Sistema * sistema) {
    int opcion;
    int op1;
    std::string linea;
    std::string codigo;
    std::string arg3;
    std::string arg4;
    std::string arg5;
    std::cout << "¿Desea cargar memoria?"<<std::endl;
    std::cout << "(No: 0/Sí: 1)"<< std::endl;
    do {
        std::cin >> op1;
        switch(op1){
            case 0:
                std::cout << "Iniciando sistema . . ." << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~ ◈ ~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                break;

            case 1:
                readFile(sistema);
                std::cout << "Iniciando sistema . . ." << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~ ◈ ~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

                break;

            default:
                std::cout << "Opción no válida. Intente nuevamente."<< std::endl;
                break;

        }

    } while(op1!=1 && op1!=0);
    do {
        std::cout << "---------MENÚ---------\n";
        std::cout << "Seleccione una opción:\n";
        std::cout << "1. Agregar libro\n";
        std::cout << "2. Agregar revista\n";
        std::cout << "3. Mostrar Información de los materiales\n";
        std::cout << "4. Buscar material\n";
        std::cout << "5. Prestar Material\n";
        std::cout << "6. Devolver Material\n";
        std::cout << "7. Crear usuario\n";
        std::cout << "8. Buscar usuario\n";
        std::cout << "9. Eliminar usuario\n";
        std::cout << "10. Salir\n";
        std::cout << "-----------------------\n";
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                std::cout << "Ingrese el título del libro" << std::endl;
                linea = readLine();
                std::cout << "Ingrese el código ISBN del libro" << std::endl;
                codigo = readLine();
                std::cout << "Ingrese el autor del libro" << std::endl;
                arg3 = readLine();
                std::cout << "Ingrese fecha de publicación" << std::endl;
                arg4 = readLine();
                std::cout << "Ingrese resumen" << std::endl;
                arg5 = readLine();
                if(sistema->agregarMaterial(new Libro(linea,codigo,arg3,false,arg4,arg5))) {
                    std::cout << "Libro agregado con éxito" << std::endl;
                }  else std::cout << "Ha ocurrido un problema: biblioteca llena" << std::endl;
                break;
            case 2:
                std::cout << "Ingrese el título de la revista" << std::endl;
                linea = readLine();
                std::cout << "Ingrese el código ISBN de la revista" << std::endl;
                codigo = readLine();
                std::cout << "Ingrese el autor de la revista" << std::endl;
                arg3 = readLine();
                std::cout << "Ingrese numero de edición" << std::endl;
                arg4 = readLine();
                std::cout << "Ingrese mes de publicación" << std::endl;
                arg5 = readLine();
                if(sistema->agregarMaterial(new Revista(linea,codigo,arg3,false,arg4,arg5))) {
                    std::cout << "Revista agregado con éxito" << std::endl;
                }  else std::cout << "Ha ocurrido un problema: biblioteca llena" << std::endl;
                break;
            case 3:
                sistema -> mostrarMateriales();
                break;
            case 4:
                std::cout << "Ingrese título o autor para filtrar el material" << std::endl;
                linea = readLine();
                sistema -> filtrarMaterial(linea);
            case 5:
                std::cout << "Ingrese ID de usuario:" << std::endl;
                linea = readLine();
                std::cout << "Ingrese código ISBN del material a prestar:" << std::endl;
                codigo = readLine();
                if(sistema->buscarUsuario(linea)==nullptr) {
                    std::cout << "Usuario no existente"<< std::endl;
                    break;}
                if(sistema->buscarMaterial(codigo)==nullptr) {
                    std::cout << "Material no existente"<< std::endl;
                    break;}
                if(sistema->prestarMaterial(sistema->buscarUsuario(linea),sistema->buscarMaterial(codigo))) {
                    std::cout << "Material prestado con éxito" << std::endl;
                } else std::cout << "Ha ocurrido un error al prestar el material" << std::endl;
                break;
            case 6:
                std::cout << "Ingrese código ISBN del material a devolver:" << std::endl;
                codigo = readLine();
                if(sistema->buscarMaterial(codigo)==nullptr) {
                    std::cout << "Material no existente"<< std::endl;
                    break;}
                if(sistema->devolverMaterial(sistema->buscarMaterial(codigo))) {
                    std::cout << "Material devuelto con éxito" << std::endl;
                } else std::cout << "Ha ocurrido un error al devolver el material"<< std::endl;
                break;
            case 7: 
                std::cout << "Ingrese el nombre del usuario" << std::endl;
                linea = readLine();
                std::cout << "Ingrese ID de usuario" << std::endl;
                codigo = readLine();
                if(sistema->crearUsuario(new Usuario(linea,codigo))) {
                    std::cout << "Usuario creado con éxito" << std::endl;
                } else std::cout << "Ha ocurrido un error al crear el usuario: capacidad máxima alcanzada." << std::endl;
                break;
            case 8:
                std::cout << "Ingrese ID del usuario a buscar" << std::endl;
                linea = readLine();
                if(sistema->buscarUsuario(linea)==nullptr) {
                    std::cout << "Usuario no existente"<< std::endl;
                    break;
                }
                sistema->buscarUsuario(linea)->mostrarMaterialesPrestados();
                break;
            case 9:
                std::cout << "Ingrese ID del usuario a eliminar" << std::endl;
                linea = readLine();
                if(sistema->eliminarUsuario(sistema->buscarUsuario(linea))==true) {
                    
                    std::cout << "Usuario eliminado con éxito" << std::endl; 
                } else std::cout << "Usuario no encontrado" << std::endl;
                break;
            case 10:
                std::cout << "Guardando . . ." << std::endl;
                sistema->updateTxt();
                std::cout << "¡Gracias por preferirnos!"<< std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente."<< std::endl;
                break;
        }
    } while(opcion != 10); 
}


int main() {
    Sistema* sistema = new Sistema();

    if(sistema -> agregarMaterial(new Libro("Harry potter","123","J.K Rowling",false,"26 de junio 1997","magia!"))) std::cout<<"Material agregado con éxito."<<std::endl;
    sistema -> agregarMaterial(new Libro("La mónada","321","J.K Rowling",false,"26 de junio 1987","filosofía!"));
    sistema -> agregarMaterial(new Revista("les bateaux","69","pepite",false,"99","janvier"));   

    menu(sistema);

    







    return 0;
}



