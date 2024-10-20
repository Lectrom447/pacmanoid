# Pacmanoid
Se trata de un juego construido totalmente en el leguaje C++ y usando la librería graphito.cpp que a su vez utiliza la API de Windows. En este proyecto se busca poner practica los conocimientos adquiridos sobre programación en C++ y programación orientada a objetos.
### Funcionamiento
En este juego el objetivo es conseguir destruir todos los fantasmas usando un cañón, para que esto ocurra el proyectil debe tener el mismo color del fantasma.  
Al momento que el proyectil rebota este cambia de color de acuerdo con la lista de colores de la parte de abajo.
Esta lista cambia de forma aleatoria en cada ronda.
### Construir el Proyecto
Para construir el proyecto ejecuta el siguinte comando
```
g++ -fdiagnostics-color=always -g *.cpp -lgdi32 -o pacmanoid.exe
```
