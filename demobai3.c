#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}
int angle = 0;
float alpha = 0.0;
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	//mau doi tuong
	glColor3f(1.0,1.0,1.0);
	// ma tran don vi
	glLoadIdentity();
	//thong so nguoi quan sat
	gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);

	
	glPushMatrix();
	glTranslatef(-0.3,1,0);
	
	glRotatef(150,0,0,1);
	glRotatef(80,1,1,0);
	glRotatef(alpha,0,0,1);
	glutWireSphere(1,18,10);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(0,-1,0);
	glRotatef(10,1,0,1);
	glRotatef(10,0,1,0);
	glScalef(1,2,1);
	glutWireCube(1.0);
	glPopMatrix();
	
	glutSwapBuffers();
	glFlush();
}

//click chuot
void spin(){
	alpha = alpha + 0.02;
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON){
		glutIdleFunc(spin);
	}
}
void reshape(int w,int h){
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//cau lenh phep chieu khoi canh
//	glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);
	//phep chieu song song
	glOrtho(-3.0,3.0,-3.0,3.0,1.5,20.0);
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
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}



