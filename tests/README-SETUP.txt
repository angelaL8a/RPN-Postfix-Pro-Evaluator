Para clonar el repositorio de Google Test y compilarlo manualmente en Windows, sigue estos pasos:

### Paso 1: Clonar el repositorio de Google Test

1. Abre PowerShell o Command Prompt.
2. Navega a la carpeta donde deseas clonar el repositorio de Google Test.
3. Ejecuta el siguiente comando para clonar el repositorio:

    ```sh
    git clone https://github.com/google/googletest.git
    ```

### Paso 2: Configurar y compilar Google Test con CMake

1. Instala CMake si aún no lo tienes. Puedes descargarlo desde [aquí](https://cmake.org/download/).
2. Abre PowerShell o Command Prompt.
3. Navega al directorio clonado de Google Test:

    ```sh
    cd googletest
    ```

4. Crea un directorio de compilación y navega a él:

    ```sh
    mkdir build
    cd build
    ```

5. Ejecuta CMake para configurar el proyecto:

    ```sh
    cmake ..
    ```

6. Compila el proyecto con el siguiente comando. Esto generará las bibliotecas de Google Test:

    ```sh
    cmake --build . --config Release
    ```

### Paso 3: Crear y compilar el archivo de prueba

1. Con el archivo llamado `test_stack.cpp` en el directorio `tests`.

    ```cpp
    #include "Stack.hpp"
    #include <gtest/gtest.h>

    // Tests...
    ```

2. Crea un archivo `CMakeLists.txt` en el directorio principal con el siguiente contenido:

    ```
        cmake_minimum_required(VERSION 3.10)
        project(StackTests)

        set(CMAKE_CXX_STANDARD 11)

        # Ruta a los archivos de encabezado de Google Test
        include_directories(C:/Users/aloza/googletest/googletest/include)

        # Ruta a los archivos de biblioteca de Google Test
        link_directories(C:/Users/aloza/googletest/build/lib/Release)

        # Configurar la construcción para usar la misma biblioteca de tiempo de ejecución
        foreach(flag_var
                CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
            if(${flag_var} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
            endif()
        endforeach()

        # Ejecutable para las pruebas de stack
        add_executable(test_stack 
            tests/test_stack.cpp
        )

        # Enlazar con las bibliotecas de Google Test
        target_link_libraries(test_stack gtest gtest_main)
    ```

3. Configura y compila tu proyecto de prueba.

    1. Abre PowerShell o Command Prompt.
    2. Navega al directorio que contiene `CMakeLists.txt`.
    3. Crea un directorio de compilación y navega a él:

        ```sh
        mkdir build
        cd build
        ```

    4. Ejecuta CMake para configurar el proyecto:

        ```sh
        cmake ..
        ```

    5. Compila el proyecto con el siguiente comando:

        ```sh
        cmake --build . --config Release
        ```

### Paso 4: Ejecutar las pruebas

1. Después de compilar, ejecuta tu archivo de prueba:

    ```sh
    cd Release
    ./Release/test_stack.exe
    ```

Estos pasos te permitirán clonar, compilar y ejecutar Google Test en Windows. 



