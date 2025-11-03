 Descripción
Este proyecto implementa un simulador completo de red de enrutadores que calcula rutas óptimas usando el algoritmo de Dijkstra. El sistema permite crear, modificar y analizar topologías de red de manera dinámica, con una interfaz gráfica desarrollada en Qt.
✨ Características Principales

✅ Modelamiento completo usando Programación Orientada a Objetos
✅ Implementación del Algoritmo de Dijkstra para cálculo de rutas óptimas
✅ Uso extensivo de contenedores STL (vector, map, priority_queue, pair, set)
✅ Interfaz gráfica profesional con Qt Framework
✅ Carga y guardado de topologías desde archivos
✅ Generación aleatoria de redes para pruebas
✅ Actualización dinámica de rutas en tiempo real
✅ Visualización de tablas de enrutamiento


🏗️ Arquitectura del Sistema
┌─────────────────────────────────────────────────────────────┐
│                    INTERFAZ GRÁFICA (Qt)                    │
│                       MainWindow.cpp                         │
└────────────────────────┬────────────────────────────────────┘
                         │
                         ▼
┌─────────────────────────────────────────────────────────────┐
│                    CAPA DE LÓGICA                           │
│  ┌──────────┐  ┌──────────────┐  ┌──────────┐             │
│  │   Red    │──│  Enrutador   │──│   Ruta   │             │
│  └──────────┘  └──────────────┘  └──────────┘             │
│       │                 │                                    │
│       └─────────────────┴──── Enlace                       │
└─────────────────────────────────────────────────────────────┘
                         │
                         ▼
┌─────────────────────────────────────────────────────────────┐
│                  CONTENEDORES STL                           │
│  vector | map | priority_queue | pair | set                │
└─────────────────────────────────────────────────────────────┘

📦 Estructura del Proyecto
SimuladorRed/
│
├── 📄 Ruta.h                    # Estructura para almacenar rutas
├── 📄 Enlace.h                  # Clase que representa conexiones
├── 📄 Enrutador.h              # Clase con tabla de enrutamiento
├── 📄 Red.h                     # Clase principal del sistema
├── 📄 Red.cpp                   # Implementación + Dijkstra
│
├── 🖥️ MainWindow.h             # Interfaz Qt (header)
├── 🖥️ MainWindow.cpp           # Interfaz Qt (implementación)
├── 🚀 main.cpp                  # Punto de entrada
│
├── ⚙️ SimuladorRed.pro          # Archivo de proyecto Qt
├── 🎯 ejemplo_consola.cpp       # Versión alternativa por consola
│
├── 📋 ejemplo_topologia.txt     # Ejemplo de red de la guía
└── 📚 README.md                 # Este archivo
📊 Métricas del Proyecto
MétricaValorLíneas de código~1,500Clases implementadas5Contenedores STL usados6Funciones públicas25+Archivos fuente8Complejidad algorítmicaO((V+E) log V)

🎯 Objetivos Cumplidos

 ✅ Modelamiento de objetos (Enrutador, Red, Enlace, Ruta)
 ✅ Uso de contenedores STL (vector, map, priority_queue, pair, set)
 ✅ Implementación de algoritmo de caminos más cortos (Dijkstra)
 ✅ Actualización dinámica de topología
 ✅ Carga desde archivo
 ✅ Generación aleatoria
 ✅ Interfaz gráfica Qt
 ✅ Código documentado y mantenible


🚀 Posibles Extensiones
Nivel Básico

 Soporte para múltiples métricas (latencia, ancho de banda)
 Exportar tablas a CSV/PDF
 Modo oscuro en la interfaz

Nivel Intermedio

 Algoritmo de Floyd-Warshall (alternativa a Dijkstra)
 Visualización gráfica de la topología
 Simulación de paquetes viajando por la red

Nivel Avanzado

 Soporte para redes jerárquicas (OSPF areas)
 Balanceo de carga (ECMP)
 Detección de fallos y reconfiguración automática


👨‍💻 Autores
Nombre: Sergio Andres Chaves Roa
Nombre: Mauricio Aguas Ramirez
Curso: Informática II 
Profesor: Erika 
Semestre: 2025-2

📚 Referencias

Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley Professional.
Meyers, S. (2014). Effective Modern C++. O'Reilly Media.
Qt Documentation. (2024). Qt 6 Documentation. https://doc.qt.io/
ISO/IEC. (2017). ISO/IEC 14882:2017 - Programming Languages — C++.
