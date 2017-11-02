// Melanie Vértiz Jiménez A01169675 


#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"

Camera _camera;
Mesh _mesh;
Transform _transform;
Transform _transform2; 
ShaderProgram _shaderProgram;

// Función que va a inicializar toda la memoria del programa.
void Initialize()
{
	// Vamos a crear una lista que va a almacenar las posiciones
	// en 2 dimensiones de un triángulo.
	// Esto es en CPU y RAM.
	std::vector<glm::vec3> positions;
	// Cara frontal
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f)); //C		0
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f)); //D		1
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f)); //B		2
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f)); //A		3
	// Cara lateral derecha
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f)); //D		4
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f)); //H		5
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f)); //F		6
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f)); //B		7
	// Cara trasera 
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f)); //G	8
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f)); //E		9
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f)); //F		10
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f)); //H		11
	//Cara Lateral izquierda 
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f)); //A		12	
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f)); //E		13
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f)); //C		14	
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f)); //G	15
	// Tapa inferior 
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f)); //C		16
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f)); //G	17
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f)); //H		18
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f)); //D		19
	// Tapa superior 
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f)); //A		20
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f)); //B		21
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f)); //E		22
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f)); //F		23

	// Vamos a crear una lista para almacenar colores RGB
	// Esta lista está en CPU y RAM
	std::vector<glm::vec3> colors;
	// Cara frontal
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	// Cara lateral derecha
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	// Cara trasera 
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Cara lateral izquierda 
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	//Tapa inferior 
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	// Tapa superior 
	colors.push_back(glm::vec3(0.50f, 0.1f, 0.3f));
	colors.push_back(glm::vec3(0.50f, 0.1f, 0.3f));
	colors.push_back(glm::vec3(0.50f, 0.1f, 0.3f));
	colors.push_back(glm::vec3(0.50f, 0.1f, 0.3f));

	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 11, 8, 10, 12, 13, 15, 12, 15, 14, 16, 17, 18, 16, 18, 19, 22, 20, 23, 20, 21, 23};

	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.LinkProgram();

	_transform.SetPosition(-10.0f, 0.0f, -20.0f);
	_transform2.SetPosition(10.0f, 0.0f, -20.0f);

}
void MainLoop()
{
	// Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_transform.Rotate(0.01f, 0.01f, 0.001f, true);
	_shaderProgram.Activate();
	_transform2.Rotate(0.03f, 0.02f, 0.004f, true);
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform2.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.Deactivate();
	_shaderProgram.Deactivate();

	// Intercambiar los buffers (el que se estaba rendereando con el que se estaba
	// mostrando).
	glutSwapBuffers();
}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
	//camera.setpersective y mandar llamar el 
}

int main(int argc, char* argv[])
{
	// Inicializamos freeglut. 
	// Freeglut se encarga de generar y manejar ventanas.
	// Utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);
	// Tenemos que informar que queremos trabajar con el pipeline
	// programable (OpenGL moderno).
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// de color true color RGBA, un buffer de profundidad y un segundo buffer 
	// para rendererar (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(1200, 800);
	// Creamos y abrimos la ventana con un título personalizado.
	glutCreateWindow("Hello World OpenGL");
	// Asociar una función de render. Esta función se mandará a llamar para 
	// dibujar un frame.
	glutDisplayFunc(MainLoop);
	// Asociamos una función para el cambio de resolución
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaño de la venta.
	glutReshapeFunc(ReshapeWindow);
	
	// Asociamos la función que se mandará a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializamos GLEW. Esta librería se encarga de obtener el API
	// de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// COnfigurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometrías.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Configurar la memoria que la aplicación va a necesitar.
	Initialize();

	// Iniciamos la aplicacion gráfica. El main se pausará en estea línea
	// hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;
}