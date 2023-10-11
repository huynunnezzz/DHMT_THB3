#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}
float alpha = 5.0;
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	//mau doi tuong
	glColor3f(1.0,1.0,1.0);
	// ma tran don vi
	glLoadIdentity();
//	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	
	glTranslatef(0,0,0);
	glScalef(alpha,alpha,alpha);
	glTranslatef(0,0,0);
	GLfloat step = 3.14 / 5.0;
	register int i;
	GLfloat angle, r;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 10; ++i) {
		r = (i % 2 == 0 ? 7 : 3);
		angle = i * step;
		glVertex3f((r * cos(angle)), r * sin(angle),0.0);
	}
	glEnd();
	glutSwapBuffers();
	glFlush();
}

//click a
void spincanh(){
	if(alpha > 3.5){
		alpha -= 0.0001;
		glutPostRedisplay();
	}
}
void keyboard(unsigned char key,int x,int y){
	if(key == 'b'){
		glutIdleFunc(spincanh);
	}
}
void reshape(int w,int h){
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//cau lenh phep chieu khoi canh
//	glFrustum(-2.0,2.0,-2.0,2.0,4.0,20.0);
	//phep chieu song song
	glOrtho(-35.0, 35.0, -35.0, 35.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}



