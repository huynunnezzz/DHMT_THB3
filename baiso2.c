#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}
float alpha1 = 0.0,alpha2 = 0.0,alpha3 = 1.0,alphachiadoi = alpha3/2;
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	//mau doi tuong
	glColor3f(1.0,1.0,1.0);
	// ma tran don vi
	glLoadIdentity();
//	gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);
	//cau a
	
	glRotatef(alpha1,0,0,1);

	//cau b
	glTranslatef(5,0,0);
	glRotatef(alpha2,0,0,1);
	glTranslatef(-5,0,0);
	//cau c

	glScalef(alpha3,alpha3,alpha3);

	
	GLfloat step = 3.14 / 5.0;
	register int i;
	GLfloat angle, r;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 10; ++i) {
		r = (i % 2 == 0 ? 5 : 2);
		angle = i * step;
		glVertex3f((r * cos(angle)), r * sin(angle),0.0);
	}
	glEnd();
	
	step = 3.14/20;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= 40; ++i) {
		angle = i * step;
		glVertex3f(cos(angle)*5, sin(angle)*5 ,0.0);
	}
	glEnd();
	
	glutSwapBuffers();
	glFlush();
}


//click chuot
void spin(){
	alpha1 += 0.01;
	glutPostRedisplay();
	
}
void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON){
		glutIdleFunc(spin);
		
	}
}
void spincanhb(){
	alpha2 += 0.01;
	glutPostRedisplay();
}
void spincanhc(){
	if(alpha3 > alphachiadoi){
		alpha3 -= 0.0001;
		glutPostRedisplay();
	}
}
void keyboard(unsigned char key,int x,int y){
	if(key == 'a'){
		glutIdleFunc(spincanhb);
	}
	if(key == 'b'){
		glutIdleFunc(spincanhc);
	}
}
void reshape(int w,int h){
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//cau lenh phep chieu khoi canh
//	glFrustum(-2.0,2.0,-2.0,2.0,4.0,20.0);
	//phep chieu song song
	glOrtho(-10, 10.0, -10.0, 10.0, -1.0, 1.0);
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



