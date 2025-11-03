# 🌐 Simulador de Red de Enrutadores

<div align="center">

![Version](https://img.shields.io/badge/version-2.0.0-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![C++](https://img.shields.io/badge/C%2B%2B-17-red.svg)
![Qt](https://img.shields.io/badge/Qt-5.15+-orange.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)

*Un simulador completo de red de enrutadores con interfaz gráfica que implementa el algoritmo de Dijkstra para el cálculo de rutas óptimas*

[🚀 Instalación](#-instalación) •
[📖 Uso](#-uso) •
[⚡ Características](#-características-principales) •
[🏗️ Arquitectura](#️-arquitectura) •
[📊 Métricas](#-métricas-del-proyecto) •
[🤝 Contribuir](#-contribuir)

</div>

## 🌟 Descripción

Este proyecto implementa un **simulador profesional de red de enrutadores** que permite modelar, analizar y visualizar topologías de red complejas. Utiliza el algoritmo de **Dijkstra** para calcular rutas óptimas y proporciona una interfaz gráfica intuitiva desarrollada con **Qt Framework**.

### 🎯 ¿Para qué sirve?

- **🎓 Educación**: Ideal para estudiantes de redes y telecomunicaciones
- **🔬 Investigación**: Análisis de comportamiento de algoritmos de enrutamiento
- **🛠️ Prototipado**: Validación de topologías antes de implementación real
- **⚡ Simulación**: Pruebas de rendimiento y optimización de rutas

## ⚡ Características Principales

### 🔥 Funcionalidades Core

- ✅ **Algoritmo de Dijkstra** - Cálculo de caminos más cortos con complejidad O((V+E) log V)
- ✅ **Interfaz Gráfica Profesional** - Desarrollada con Qt Framework
- ✅ **Topologías Dinámicas** - Creación, modificación y análisis en tiempo real
- ✅ **Importación/Exportación** - Carga de topologías desde archivos de texto
- ✅ **Generación Aleatoria** - Creación automática de redes para pruebas
- ✅ **Tablas de Enrutamiento** - Visualización completa de rutas calculadas
- ✅ **Programación Orientada a Objetos** - Diseño modular y extensible

### 🛠️ Tecnologías Utilizadas

- **Lenguaje**: C++17
- **Framework GUI**: Qt 5.15+
- **Contenedores**: STL (vector, map, priority_queue, pair, set)
- **Algoritmos**: Dijkstra, Grafos, Estructuras de Datos
- **Arquitectura**: Orientada a Objetos

## 🚀 Instalación

### 📋 Prerrequisitos

```bash
# Ubuntu/Debian
sudo apt-get install qt5-default build-essential

# CentOS/RHEL
sudo yum install qt5-qtbase-devel gcc-c++

# macOS (con Homebrew)
brew install qt5

# Windows: Descargar Qt desde https://www.qt.io/download
```

### 💻 Compilación

```bash
# Clonar el repositorio
git clone https://github.com/checho9801/SIMULADOR-DE-RED-DE-ENRUTADORES-.git
cd SIMULADOR-DE-RED-DE-ENRUTADORES-

# Compilar con qmake
qmake SimuladorRed.pro
make

# Ejecutar
./SimuladorRed
```

## 📖 Uso

### 🖥️ Interfaz Gráfica

1. **Crear Red**: Agrega nodos y enlaces manualmente
2. **Cargar Topología**: Importa desde archivo `ejemplo_topologia.txt`
3. **Generar Aleatoria**: Crea una red de prueba automáticamente
4. **Calcular Rutas**: Ejecuta el algoritmo de Dijkstra
5. **Visualizar Tablas**: Analiza las tablas de enrutamiento

### 📄 Formato de Archivo de Topología

```
# Formato: origen destino peso
0 1 10
0 2 15
1 2 5
1 3 20
2 3 8
```

### 💡 Ejemplo de Uso por Código

```cpp
#include "Red.h"

int main() {
    Red miRed;
    
    // Agregar enrutadores
    miRed.agregarEnrutador(0);
    miRed.agregarEnrutador(1);
    miRed.agregarEnrutador(2);
    
    // Agregar enlaces
    miRed.agregarEnlace(0, 1, 10);
    miRed.agregarEnlace(1, 2, 15);
    
    // Calcular rutas
    miRed.calcularRutas(0);
    
    // Mostrar tabla de enrutamiento
    miRed.mostrarTablaEnrutamiento(0);
    
    return 0;
}
```

## 🏗️ Arquitectura

### 📊 Diagrama de Componentes

```
┌─────────────────────────────────────────────────────────────┐
│                    INTERFAZ GRÁFICA (Qt)                    │
│                     MainWindow.cpp                          │
│        [Botones] [Tablas] [Gráficos] [Menús]               │
└────────────────────────┬────────────────────────────────────┘
                         │ Señales Qt / Slots
                         ▼
┌─────────────────────────────────────────────────────────────┐
│                    CAPA DE LÓGICA                           │
│  ┌──────────┐  ┌──────────────┐  ┌──────────┐             │
│  │   Red    │◄─│  Enrutador   │◄─│   Ruta   │             │
│  │          │  │              │  │          │             │
│  │ - nodos  │  │ - id         │  │ - origen │             │
│  │ - enlaces│  │ - tabla      │  │ - destino│             │
│  │          │  │ - vecinos    │  │ - costo  │             │
│  └────┬─────┘  └──────────────┘  └──────────┘             │
│       │                 ▲                                  │
│       └─────────────────┴──── Enlace                       │
│                              - origen                       │
│                              - destino                      │
│                              - peso                         │
└─────────────────────────────────────────────────────────────┘
                         │
                         ▼
┌─────────────────────────────────────────────────────────────┐
│                  CONTENEDORES STL                           │
│  vector<Enrutador> | map<int,Ruta> | priority_queue<Node>  │
│  pair<int,int> | set<int> | queue<Enlace>                  │
└─────────────────────────────────────────────────────────────┘
```

### 🗂️ Estructura del Proyecto

```
SimuladorRed/
│
├── 📄 Ruta.h                    # Estructura para almacenar rutas
├── 📄 Enlace.h                  # Clase que representa conexiones
├── 📄 Enrutador.h               # Clase con tabla de enrutamiento
├── 📄 Red.h                     # Clase principal del sistema
├── 📄 Red.cpp                   # Implementación + Dijkstra
│
├── 🖥️ MainWindow.h              # Interfaz Qt (header)
├── 🖥️ MainWindow.cpp            # Interfaz Qt (implementación)
├── 🚀 main.cpp                  # Punto de entrada
│
├── ⚙️  SimuladorRed.pro          # Archivo de proyecto Qt
├── 🎯 ejemplo_consola.cpp       # Versión alternativa por consola
│
├── 📋 ejemplo_topologia.txt     # Ejemplo de red de prueba
└── 📚 README.md                 # Este archivo
```

## 📊 Métricas del Proyecto

| Métrica | Valor |
|---------|--------|
| **Líneas de Código** | ~1,500 |
| **Clases Implementadas** | 5 |
| **Contenedores STL** | 6 |
| **Funciones Públicas** | 25+ |
| **Archivos Fuente** | 8 |
| **Complejidad Temporal** | O((V+E) log V) |
| **Complejidad Espacial** | O(V²) |

## 🎯 Algoritmo de Dijkstra

### 📐 Implementación

El simulador implementa el algoritmo de Dijkstra optimizado para redes de enrutadores:

```cpp
// Pseudocódigo del algoritmo implementado
function dijkstra(grafo, origen):
    // Inicialización
    distancia[origen] = 0
    cola_prioridad.push(origen, 0)
    
    while not cola_prioridad.empty():
        actual = cola_prioridad.pop()
        
        if visitado[actual]: continue
        visitado[actual] = true
        
        for each vecino in grafo.vecinos(actual):
            nueva_distancia = distancia[actual] + peso(actual, vecino)
            
            if nueva_distancia < distancia[vecino]:
                distancia[vecino] = nueva_distancia
                predecesor[vecino] = actual
                cola_prioridad.push(vecino, nueva_distancia)
```

### ⚡ Complejidad

- **Temporal**: O((V + E) log V) usando priority_queue
- **Espacial**: O(V) para almacenar distancias y predecesores

## 🎯 Objetivos Cumplidos

 ✅ **Modelamiento de objetos** (Enrutador, Red, Enlace, Ruta)  
 ✅ **Uso de contenedores STL** (vector, map, priority_queue, pair, set)  
 ✅ **Implementación de algoritmo** de caminos más cortos (Dijkstra)  
 ✅ **Actualización dinámica** de topología  
 ✅ **Carga desde archivo** de configuración  
 ✅ **Generación aleatoria** de redes de prueba  
 ✅ **Interfaz gráfica Qt** profesional  
 ✅ **Código documentado** y mantenible

## 🚀 Posibles Extensiones

### 🔰 Nivel Básico
- [ ] Soporte para múltiples métricas (latencia, ancho de banda)
- [ ] Exportación de tablas a CSV/PDF
- [ ] Tema oscuro en la interfaz
- [ ] Validación avanzada de entrada

### 🔄 Nivel Intermedio
- [ ] Algoritmo de Floyd-Warshall (alternativa a Dijkstra)
- [ ] Visualización gráfica 2D de la topología
- [ ] Simulación de paquetes viajando por la red
- [ ] Análisis de rendimiento y estadísticas

### 🎯 Nivel Avanzado
- [ ] Soporte para redes jerárquicas (OSPF areas)
- [ ] Balanceo de carga (ECMP)
- [ ] Detección de fallos y reconfiguración automática
- [ ] Integración con herramientas de monitoreo

## 🤝 Contribuir

¡Las contribuciones son bienvenidas! Por favor:

1. **Fork** el repositorio
2. **Crea** una rama para tu característica (`git checkout -b feature/nueva-caracteristica`)
3. **Commit** tus cambios (`git commit -am 'Add nueva característica'`)
4. **Push** a la rama (`git push origin feature/nueva-caracteristica`)
5. **Abre** un Pull Request

### 📝 Estándares de Código

- Seguir el estándar **C++17**
- Usar **camelCase** para variables y funciones
- Usar **PascalCase** para clases
- Incluir **documentación** en línea
- Agregar **pruebas** para nuevas funcionalidades

## 👨‍💻 Autores

| Autor | Rol | GitHub |
|-------|-----|--------|
| **Sergio Andrés Chaves Roa** | Desarrollador Principal | [@checho9801](https://github.com/checho9801) |
| **Mauricio Aguas Ramírez** | Colaborador | - |

### 🏫 Información Académica

- **Curso**: Informática II
- **Profesor**: Erika
- **Institución**: Universidad de Antioquia
- **Semestre**: 2025-2

## 📄 Licencia

Este proyecto está licenciado bajo la **Licencia MIT** - ver el archivo [LICENSE](LICENSE) para detalles.

## 📚 Referencias

### 📖 Literatura Académica

1. **Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C.** (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.
2. **Tanenbaum, A. S., & Wetherall, D. J.** (2021). *Computer Networks* (6th ed.). Pearson.
3. **Stroustrup, B.** (2013). *The C++ Programming Language* (4th ed.). Addison-Wesley Professional.
4. **Meyers, S.** (2014). *Effective Modern C++*. O'Reilly Media.
5. **Qt Documentation** (2024). *Qt 6 Documentation*. https://doc.qt.io/
6. **ISO/IEC** (2017). *ISO/IEC 14882:2017 - Programming Languages — C++*.

---

<div align="center">

### ⭐ Si este proyecto te fue útil, ¡considera darle una estrella!

**Simulador desarrollado con ❤️ para el aprendizaje de redes y algoritmos**

*Última actualización: Noviembre 2025*

</div>