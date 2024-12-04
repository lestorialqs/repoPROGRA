# **Programación III: Proyecto Final (2024-2)**

Este proyecto fue realizado por los siguientes integrantes:

- **Henry Rutber Quispe Sutta**  
- **Anel Mi Lucero Rojas Martinez**  
- **Luis Anthony Romero Padilla**

Cada integrante contribuyó en distintas áreas del proyecto, y estas contribuciones fueron integradas en este repositorio final.

---

## **Movie Search Application**

Esta es una aplicación innovadora de búsqueda de películas diseñada para ofrecer a los usuarios una experiencia rápida y eficiente. Sus principales características incluyen:

- **Búsqueda por frases en película**: Permite buscar películas utilizando palabras clave en títulos o sinopsis.  
- **Exploración por frases en sinopsis**: Facilita la búsqueda de películas categorizadas por etiquetas asociadas (géneros o temas).  
- **Optimización con Trie**: Implementa la estructura de datos **Trie**, que garantiza búsquedas muy rápidas y precisas.  
- **Gestión personalizada**: Incluye una lista intuitiva de "Ver Más Tarde" para planificar visualizaciones futuras.

La aplicación optimiza el proceso de búsqueda y gestión de películas mediante nodos, mejorando la exploración por películas con su atributo.

---

## **Características principales**

- **Búsqueda por palabra clave**:  
  Los usuarios pueden buscar películas ingresando una palabra o frase que se buscará tanto en el título como en la sinopsis. Los resultados se presentan tanto para las películas y para la sinopsis.

- **Lista "Ver Más Tarde"**:  
  Los usuarios pueden guardar películas en una lista personalizada llamada "Ver Más Tarde". Esto les ayuda a realizar un seguimiento de las películas que desean ver posteriormente, creando una experiencia personalizada.

- **Interfaz de usuario basada en consola**:  
  La aplicación cuenta con un menú simple en la consola que permite a los usuarios navegar por las opciones disponibles, realizar búsquedas y explorar detalles de las películas.

- **Trie para búsqueda rápida**:  
  La estructura de datos **Trie** se utiliza para almacenar y buscar palabras y frases clave en los títulos y sinopsis de las películas, mejorando significativamente la velocidad y precisión de las búsquedas.

- **Indexación por etiquetas**:  
  Las películas están organizadas mediante un sistema de indexación por etiquetas, lo que permite realizar búsquedas rápidas y eficientes por categorías específicas.

---

## **Tecnologías y herramientas**

- **C++**:  
  Lenguaje de programación principal utilizado para el desarrollo de la aplicación, aprovechando su rendimiento y capacidad para manejar estructuras complejas.

- **Trie**:  
  Estructura de datos clave para optimizar la búsqueda de palabras y frases clave dentro de los títulos y sinopsis, asegurando búsquedas rápidas incluso con grandes volúmenes de datos.

- **Archivos CSV**:  
  Los datos de las películas, como títulos, sinopsis y etiquetas, se cargan desde un archivo **CSV**, asegurando integración y actualización sencilla de la base de datos.

- **Archivos de texto**:  
  La lista de películas guardadas en "Ver Más Tarde", permitiendo que se el usuario este al tanto de las películas a ver luego.

---

## **Flujo de funciones**

### **1. Carga de datos**:
- Antes de realizar la carga de datos lo que haceos es limpiar a base de datos y la convertimos en limpio2.csv para un mayor orden y claridad.
- La aplicación lee los datos desde un archivo CSV que contiene información sobre cada película (título, sinopsis, etiquetas).  
- Estos datos se almacenan en el Trie para facilitar búsquedas rápidas.

### **2. Búsqueda por palabra clave**:
- El usuario ingresa una palabra clave.
- La aplicación recorre el Trie para buscar coincidencias en los títulos y sinopsis.
- Los resultados se ordenan por relevancia antes de ser presentados al usuario.
  

### **4. Gestión de la lista "Ver Más Tarde"**:
- Los usuarios pueden agregar películas desde los resultados de búsqueda a su lista personalizada.
- La lista asegura que las preferencias del usuario se guarden de manera correcta.

### **5. Interacción mediante consola**:
- Los usuarios interactúan con un menú basado en consola que les permite buscar películas, explorar sus detalles, y gestionar la lista "Ver Más Tarde" de manera intuitiva.


## **Enlace al repositorio de archivos**

[Accede a los archivos del proyecto aquí](https://drive.google.com/drive/folders/1-kPJKkIW7BSCg5TwVfUNt1xEOYV6Wbk3?usp=sharing)

---

## **Video de exposición**

Mira el video de presentación del proyecto en el siguiente enlace:  
[Video de exposición](https://drive.google.com/drive/folders/1-kPJKkIW7BSCg5TwVfUNt1xEOYV6Wbk3?usp=sharing)

---


---

### **Notas finales**

Este README está diseñado para ofrecer una descripción clara y detallada de las características, tecnologías y flujo de funciones principales de la aplicación. Con un enfoque en la eficiencia y la personalización, esta herramienta es ideal para explorar y gestionar películas de manera rápida y sencilla.

