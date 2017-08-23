// Melanie Vértiz Jiménez A01169675 




#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>


void MainLoop() {
	//Borramos el buffer de color y profundidad siempre al inico de un nuevo frame 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	//TODO: renderear 


	// WARNING: Esto es OpenGl clasico y no lo vamos a volver a usar en tood el semestre 
	//Intercambiar os buffers (el que se estaba rendereando con el que se estaba mostrando 
	glBegin(GL_TRIANGLES); 
	//3f porque es RGB
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, -1.0f);
	glColor3f(0.0f, 0.1f, 0.0f); 
	glVertex2f(1.0f, -1.0f); 
	glColor3f(0.0f, 0.0f, 0.1f); 
	glVertex2f(0.0f, 1.0f); 

	glEnd(); 
	//END WARNING 


	glutSwapBuffers(); 

}

int main(int argc, char*argv[])
{
	//Inicializamos freeglut 
	//freeglut genera ventanas 
	glutInit(&argc, argv); 
	//Estamos informando que usaremos el pipeline clasico (OpenGl viejito)
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
	//Iniciamos la aplicacion grafica. El main se pausara en esta linea hasta que se cierre la ventana de OpenGL
	glutMainLoop(); 

	return 0;
}
 