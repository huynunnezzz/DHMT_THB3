#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}
float angle = 0.0;
float alpha = 0.0;
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	//mau doi tuong
	glColor3f(1.0,1.0,1.0);
	// ma tran don vi
	glLoadIdentity();
	//thong so nguoi quan sat
	gluLookAt(0.0,10.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0);

	
	glPushMatrix();
	glTranslatef(2,0,0);
	glRotatef(angle,0,0,1);
	glTranslatef(-2,0,0);
	glutWireSphere(1,16,20);
	glPopMatrix();
	
	glTranslatef(2,0,0);
	glPushMatrix();
	glRotatef(alpha,1,0,0);
	glutWireSphere(1,16,20);
	glPopMatrix();

	glutSwapBuffers();
	glFlush();
}

//click chuot
void spin(){
	angle += 0.01;
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON){
		glutIdleFunc(spin);
	}
}
//phim a
void spincanh(){
	alpha += 0.01;
	glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y){
	if(key == 'a'){
		glutIdleFunc(spincanh);
	}
}
void reshape(int w,int h){
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//cau lenh phep chieu khoi canh
//	glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);
	//phep chieu song song
	glOrtho(-5.0,5.0,-5.0,5.0,1.5,20.0);
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
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}



