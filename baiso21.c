
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}
int bb = 0;
float trans = -2;
float alpha = 0;
float scale =  1;
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity (); 
	gluLookAt (0, 0.0, 5, 0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	
	GLfloat step = 3.14 / 5;
	register int i;
	GLfloat angle, r;
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glRotatef(alpha,0,0,1);
	glScalef(scale,scale,scale);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 10; ++i) {
		r = (i % 2 == 0 ? 0.5 : 1);
		angle = i * step;
		float x = r * cos(angle);
		float y = r * sin(angle)+0.75;
		glVertex3f(x+bb, y-0.75 ,0.0);
	}
	glEnd();
	
	step = 3.14/20;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 40; ++i) {
		angle = i * step;
		float x = cos(angle);
		float y = sin(angle)+0.75;
		glVertex3f(x+bb, y-0.75 ,0.0);
	}
	glEnd();
	
	glutSwapBuffers();
	glFlush ();
}


void spin()
{
	
		alpha += 0.03;
		if (alpha>360) alpha -=360;
		glutPostRedisplay();		
}

void scalee()
{
	
		if (scale > 0.5) scale-=0.00005;
		glutPostRedisplay();		
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		bb = 1;
		glutIdleFunc(spin);
	}
				
	if (key == 'b') 
	{
		glutIdleFunc(scalee);
	}
		
}


void mouse(int Button, int state, int x, int y)
{
	if (Button == GLUT_LEFT_BUTTON)
	{
		bb = 0;
		glutIdleFunc(spin);
//		trans += 0.5;
//		if (trans > 2)
//		{
//			trans = -2;
//			glutPostRedisplay();
//		 } 		
	}
}



void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode (GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
