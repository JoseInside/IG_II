#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
#include <GL/glut.h>

#include <iostream>
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

//VARIABLES
GLUquadricObj *obj;

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

// Scene variables
GLfloat angX, angY, angZ; 

void buildSceneObjects() {	 
    angX=0.0f;
    angY=0.0f;
    angZ=0.0f;	

	obj = gluNewQuadric();
}

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
      
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	buildSceneObjects();

	// Light0
	glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);
    GLfloat d[]={0.7f,0.5f,0.5f,1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[]={1.0f,1.0f,1.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
	glFrustum(xLeft, xRight, yBot, yTop, N, F);
	//glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  	
 }


//MÉTODOS
void dibujaArbol(int tipo) {

	glPushMatrix();
	glRotatef(-90.0f, 1, 0, 0);
	glScalef(0.5f, 0.5f, 0.5f);
	gluCylinder(obj, 1, 0.5, 10, 30, 30);

	glPopMatrix();

	switch (tipo) {
		//ABETOS
	case (1) :
		glPushMatrix();
		glTranslatef(0.0f, 4.0f, 0.0f);
		glScalef(0.4f, 0.4f, 0.4f);
		glRotatef(-90.0f, 1, 0, 0);
		gluCylinder(obj, 3, 0, 10, 30, 30);
		
		glPopMatrix();
		break;
		//PINOS
	case(2):
		glPushMatrix();
		glTranslatef(0.0f, 4.0f, 0.0f);
		glScalef(0.4f, 0.4f, 0.4f);
		glRotatef(-90.0f, 1, 0, 0);
		gluCylinder(obj, 3, 0, 10, 30, 30);
		glRotatef(90.0f, 1, 0, 0);

		glTranslatef(0.0f, 4.0f, 0.0f);
		glRotatef(-90.0f, 1, 0, 0);
		gluCylinder(obj, 3, 0, 10, 30, 30);
		glRotatef(90.0f, 1, 0, 0);
		glPopMatrix();
		break;
		//ROBLES
	case(3):
		glPushMatrix();
		glTranslatef(0.0f, 5.0f, 0.0f);
		glScalef(0.5f, 0.5f, 0.5f);
		gluSphere(obj, 3, 30, 30);
		glPopMatrix();
		break;
		//ÁLAMOS
	case(4):
		glPushMatrix();
		glTranslatef(-0.6f, 5.0f, 0.6f);
		glScalef(0.5f, 0.5f, 0.5f);
		gluSphere(obj, 3, 30, 30);
		glTranslatef(0.6f, -5.0f, -0.6f);
		glTranslatef(2.0f, 5.0f, -2.0f);
		gluSphere(obj, 2.5, 30, 30);
		glPopMatrix();
		break;
	}
}

void dibujaCoche(){

	glPushMatrix();

	glutSolidCube(2);
	

	//FARO DERECHA
	glScalef(0.4f, 0.4f, 0.4f);
	glTranslatef(1.5f, 0.0f, 2.5f);
	gluCylinder(obj, 1, 1, 1, 30, 30);
	glTranslatef(-1.5f, 0.0f, -2.5f);

	//FARO IZQUIERDA
	glTranslatef(-1.5f, 0.0f, 2.5f);
	gluCylinder(obj, 1, 1, 1, 30, 30);
	glTranslatef(1.5f, 0.0f, -2.5f);

	//RUEDAS


	glPopMatrix();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	 
	glMatrixMode(GL_MODELVIEW);	 
	glPushMatrix();	 
		// Rotating the scene
		glRotatef(angX, 1.0f, 0.0f, 0.0f);
        glRotatef(angY, 0.0f, 1.0f, 0.0f);
        glRotatef(angZ, 0.0f, 0.0f, 1.0f);
		
		glLineWidth(1.5f);
		// Drawing axes
		glBegin( GL_LINES );			
			glColor3f(1.0,0.0,0.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(20, 0, 0);	     
	 
			glColor3f(0.0,1.0,0.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(0, 20, 0);	 
	 
			glColor3f(0.0,0.0,1.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 20);	     
		glEnd();
		 		
		// Drawing the scene	 		 
		glColor3f(1.0, 1.0, 1.0);
		//dibujaArbol(2);
		dibujaCoche();
		//gluSphere(6, 50, 60); //Sphere: radius=6, meridians=50, parallels=60
	glPopMatrix();
 
	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;		 
		case 'a': angX=angX+5; break;
		case 'z': angX=angX-5; break; 
		case 's': angY=angY+5; break;
		case 'x': angY=angY-5; break;
		case 'd': angZ=angZ+5; break;
		case 'c': angZ=angZ-5; break;  		 
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (0, 0);
	//glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	system("PAUSE"); 
   
	return 0;
}
