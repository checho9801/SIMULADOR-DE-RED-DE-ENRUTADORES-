# Simulación de una red de enrutadores

Proyecto de la Práctica 4 (Informática II) para modelar y simular una red de enrutadores usando programación orientada a objetos y contenedores de la STL. El objetivo es construir tablas de enrutamiento y calcular caminos y costos entre enrutadores con base en una topología dada.

## Objetivos de la práctica
- Modelar objetos: enrutador y red.
- Usar contenedores de la STL.
- Calcular caminos y costos entre enrutadores.
- Actualizar topología y tablas en tiempo de ejecución.

## Requerimientos funcionales
1. Modelar un enrutador capaz de almacenar y actualizar su tabla de enrutamiento.
2. Modelar una red que permita:
   - Agregar y remover enrutadores.
   - Actualizar tablas de enrutamiento al cambiar la topología.
   - Cargar una topología desde archivo.
3. Consultar el costo de enviar un paquete de un origen a un destino.
4. Mostrar el camino eficiente entre un origen y un destino.
5. (Opcional) Generar redes de forma aleatoria para pruebas.

## Estructura del proyecto
- `red.h` / `red.cpp`: lógica de modelado de la red y enrutadores (agregar/eliminar, modificar costos, cargar desde archivo, cálculo de ruta).
- `main.cpp`: interfaz por consola para cargar topología y ejecutar consultas.
- `doc.txt`: topología de ejemplo utilizada por `main.cpp` para la opción de carga.

## Formato de archivo de topología
Cada línea describe un enrutador y sus enlaces:
```
<ENRUTADOR>:<N> - <VECINO_1>:<COSTO_1>,<VECINO_2>:<COSTO_2>, ...
```
Ejemplo:
```
A:3-B:10,C:20,D:30,
B:2-A:10,C:5,
```

## Compilación y ejecución
Usando qmake (Qt):
```
qmake PRACTICA4.pro
make
./SimuladorRed
```

## Uso (modo consola)
- Cargar red desde `doc.txt` (opción 1 del menú).
- Agregar/eliminar enrutadores y modificar costos.
- Calcular camino y costo entre dos enrutadores.

## Notas de implementación
- Se emplean contenedores de la STL: `map`, `vector`, `priority_queue`.
- El cálculo de rutas usa una variante de búsqueda por prioridad para obtener el camino de menor costo.
- Los costos deben ser no negativos.

## Autores y curso
- Sergio Andrés Chaves Roa
- Mauricio Aguas Ramírez
- Curso: Informática II (Práctica 4)
- Universidad de Antioquia, 2025-2
