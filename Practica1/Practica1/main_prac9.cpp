﻿//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): González Colín Fernando	******//
//*************	Ejercicio pendiente de clase, práctica 6  ****//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int lunaM = 0;
int jupiter = 0;
int lunaJ1 = 0;
int lunaJ2 = 0;
int saturno = 0;
int anillo1 = 0;
int anillo2 = 0;
int lunaS1 = 0;
int lunaS2 = 0;
int urano = 0;
int nepturno = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

float angX = 0.0;
float angY = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara
	glRotatef(angX, 1.0, 0.0, 0.0);					//Para cambiar "angulo de vista"
	glRotatef(angY, 0.0, 0.0, 1.0);

	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje	
	glColor3f(0.9, 0.9, 0.3);	//Sol amarillo
	glutWireSphere(1.9, 12, 12);  //Draw Sun (radio,H,V);
	glPopMatrix();

	glPushMatrix(); //Merecurio	
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glTranslatef(2.5, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glutWireSphere(0.15, 12, 12);
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Venus	
	glRotatef(venus, 0.0, 1.0, 0.0);
	glTranslatef(3.5, 0.0, 0.0);
	glColor3f(0.9, 0.5, 0.0);
	glPushMatrix();
	glRotatef(venus, 0.0, 1.0, 0.0);
	glutWireSphere(0.20, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Tierra
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glTranslatef(4.5, 0.0, 0.0);
	glColor3f(0.1, 0.6, 0.9);
	glPushMatrix();
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glutWireSphere(0.20, 12, 12);
	glPopMatrix();
	glPushMatrix();//Luna	
	glRotatef(luna, 0.0, 0.0, 1.0);
	glTranslatef(0.4, 0.0, 0.0);
	glColor3f(0.4, 0.4, 0.4);
	glRotatef(luna + 2, 0.0, 0.0, 1.0);
	glutWireSphere(0.1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Marte
	glRotatef(marte, 0.0, 1.0, 0.0);
	glTranslatef(5.5, 0.0, 0.0);
	glColor3f(0.9, 0.75, 0.4);
	glPushMatrix();
	glRotatef(marte, 0.0, 1.0, 0.0);
	glutWireSphere(0.18, 12, 12);
	glPopMatrix();
	glPushMatrix();//Luna
	glRotatef(lunaM, 0.0, 1.0, 1.0);
	glTranslatef(0.4, 0.0, 0.0);
	glColor3f(0.4, 0.4, 0.4);
	glRotatef(lunaM, 0.0, 0.0, 1.0);
	glutWireSphere(0.1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Jupiter
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glTranslatef(8.0, 0.0, 0.0);
	glColor3f(0.9, 0.0, 0.0);
	glPushMatrix();
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glutWireSphere(0.5, 12, 12);
	glPopMatrix();
	glPushMatrix();//Luna
	glRotatef(lunaJ1, 0.0, 1.0, 0.0);
	glTranslatef(0.7, 0.0, 0.0);
	glColor3f(0.4, 0.4, 0.4);
	glRotatef(lunaJ1, 0.0, 0.0, 1.0);
	glutWireSphere(0.1, 12, 12);
	glPopMatrix();

	glPushMatrix();//Luna
	glRotatef(lunaJ2, 0.0, 0.0, 1.0);
	glTranslatef(1.2, 0.0, 0.0);
	glColor3f(0.4, 0.4, 0.4);
	glRotatef(lunaJ2, 0.0, 0.0, 1.0);
	glutWireSphere(0.1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Saturno
	glRotatef(saturno, 0.0, 1.0, 0.0);
	glTranslatef(12.5, 0.0, 0.0);
	glColor3f(0.7, 0.7, 0.1);
	glPushMatrix();
	glRotatef(saturno, 0.0, 1.0, 0.0);
	glutWireSphere(0.45, 12, 12);
	glPopMatrix();
	glPushMatrix();//anillo
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.0);
	glColor3f(0.4, 0.4, 0.4);
	glRotatef(anillo1, 0.0, 0.0, 1.0);
	glutWireTorus(0.07, 0.65, 12, 12);
	glPopMatrix();

	glPushMatrix();//anillo
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.0);
	glColor3f(0.4, 0.4, 0.4);
	glRotatef(anillo2, 0.0, 0.0, 1.0);
	glutWireTorus(0.07, 0.9, 12, 12);
	glPopMatrix();

	glPushMatrix();//luna
	glRotatef(lunaS1, 0.0, 1.0, 1.0);
	glTranslatef(1.2, 0.0, 0.0);
	glColor3f(0.4, 0.4, 0.4);
	glRotatef(lunaS1, 0.0, 0.0, 1.0);
	glutWireSphere(0.07, 12, 12);
	glPopMatrix();

	glPushMatrix();//luna
	glRotatef(lunaS2, 0.0, 0.0, 1.0);
	glTranslatef(1.6, 0.0, 0.0);
	glColor3f(0.4, 0.4, 0.4);
	glRotatef(lunaS2, 0.0, 0.0, 1.0);
	glutWireSphere(0.07, 12, 12);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix(); //Urano
	glRotatef(urano, 0.0, 1.0, 0.0);
	glTranslatef(17.0, 0.0, 0.0);
	glColor3f(0.3, 0.3, 0.9);
	glPushMatrix();
	glRotatef(urano, 0.0, 1.0, 0.0);
	glutWireSphere(0.38, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Nepturno
	glRotatef(nepturno, 0.0, 1.0, 0.0);
	glTranslatef(19.5, 0.0, 0.0);
	glColor3f(0.5, 0.75, 1.0);
	glPushMatrix();
	glRotatef(nepturno, 0.0, 1.0, 0.0);
	glutWireSphere(0.41, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 2) % 360;
		mercurio = (mercurio - 5) % 360;
		venus = (venus - 4) % 360;
		tierra = (tierra + 4) % 360;
		luna = (luna + 2) % 360;
		marte = (marte - 3) % 360;
		jupiter = (jupiter - 2) % 360;
		saturno = (saturno + 2) % 360;
		urano = (urano + 1) % 360;
		nepturno = (nepturno - 1) % 360;

		lunaM = (lunaM + 4) % 360;
		lunaJ1 = (lunaJ1 + 4) % 360;
		lunaJ2 = (lunaJ2 + 5) % 360;
		anillo1 = (anillo1 + 5) % 360;
		anillo2 = (anillo2 - 5) % 360;
		lunaS1 = (lunaS1 + 5) % 360;
		lunaS2 = (lunaS2 - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':
		break;

	case 'k':
	case 'K':
		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angX += 5.0;
		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angX -= 5.0;
		break;
	case GLUT_KEY_LEFT:
		angY += 5.0;
		break;
	case GLUT_KEY_RIGHT:
		angY -= 5.0;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}