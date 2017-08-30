// Melanie Vértiz Jiménez A01169675 




#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector> //lista de objetos
//identificador del manager de VBOs para un conjunto de vertices. 
GLuint vao; 

void Initialize() {
	//vamos a crear una lista que va a almacenar las posiciones en dos dimensiones de un triangulo. Esto es en CPU y RAM. 
	std::vector<glm::vec2>positions;
	positions.push_back(glm::vec2(-1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, -1.0f));	//Pushback sirve para agregar objetos a la lista 
	positions.push_back(glm::vec2(0.0f, 1.0f)); 

	//vamos a hacer una lista para almacenar colores RGB
	std::vector<glm::vec3>colors; 
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); 
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f)); 
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0)); 

	//Creamos un VAO y almacenamos el id en la variable vao. Este es el manager de VBOs
	glGenVertexArrays(1, &vao); 
	//Le decimos a OpenGL que queremos utilizar el manager, todos los VBOs que creemos a partir de este punto y hasta que desactivemos este VAO, se van a asociar a este manager 
	glBindVertexArray(vao); 



	//Identificador del VBO de posiciones 
	GLuint positionsVBO;
	//Creamos un VBO y almacenamos el ide de la variable positionsVBO
	glGenBuffers(1, &positionsVBO); //& para modificar 
	//Le decimos a OpenGL que lo queremos utilizar en cada atributo 
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO); 
	//Asignamos los datos al bufffer y los mandamos a la tarjeta de video
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW); 
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	//Identificador del VBO de colores 
	GLuint colorsVBO; 
	glGenBuffers(1, &colorsVBO); 
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO); 
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW); 
	glEnableVertexAttribArray(1); 
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr); 

	glEnableVertexAttribArray(0); 
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr); 

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	//Ya no quiero usar VAO
	glBindVertexArray(0); 

	}
void MainLoop() {
	//Borramos el buffer de color y profundidad siempre al inico de un nuevo frame 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	//TODO: renderear 

	//Paso 1 no lo podemos hacer auyn 
	//Paso 2 Activar un VAO 
	glBindVertexArray(vao);
	//PAso 3 Dibujamos 
	glDrawArrays(GL_TRIANGLES, 0, 3); 
	//Paso 4 Desactivamos el VAO 
	glBindVertexArray(0); 
	//Paso 5 aun no lo podemos hacer 




	glutSwapBuffers(); 

}

int main(int argc, char*argv[])
{
	//Inicializamos freeglut 
	//freeglut genera ventanas 
	glutInit(&argc, argv); 
	//Estamos informando que usaremos el pipeline programable (Open GL moderno) 

	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	// nos permite configurar eventos que pasan en la ventana, como cuando alguien la abre o la cierra

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS); 
	
	// Configuramos un frambuffer de color, uno de profundidad y uno extras para hacer render 

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); 
	//Solicitamos una ventana de 400px
	glutInitWindowSize(400, 400); 
	//Creamos una ventana con titulo personalizado
	glutCreateWindow("Hello World OpenGL"); 
	//Asociar una funcion de render. Esta funcion mandara llamar para dibujar un frame 
	glutDisplayFunc(MainLoop); 

	//Inicializamos GLEW. Esta libreria se encarga de obtener el API de OpenGL nuestra tarjeta de video 
	glewInit(); 
	//Configurar OpenGl, color por default del buffer de color 
	glClearColor(1.0f, 1.0f, 0.5f, 0.1f); 
	
	

	//Configurar la memoria que la 
	Initialize(); 
	//Iniciamos la aplicacion grafica. El main se pausara en esta linea hasta que se cierre la ventana de OpenGL
	glutMainLoop(); 
	return 0;
}
 