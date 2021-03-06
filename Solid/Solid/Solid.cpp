// Solid.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <gl/glut.h>

GLint WIDTH = 400;
GLint HEIGHT = 400;



void init()
{
	//glClear()


}


void display()
{
	//glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 1, 1, 20);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(1.0, 0.0, 0.0);

	//glTranslated(0.0, 1.0, 2.0);
	///glRotatef(90, 1.0, 0.0, 0.0);
	//glutWireTetrahedron();
	//glutWireTeapot(1.0);
	//glTranslated(1.0, 0.0, 0.0);
	//glutWireTeapot(1.0);
	//glFlush();
	//glLoadIdentity();
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glTranslated(-2.0, 0.0, 0.0);
	//glutWireTeapot(1.0);

	glRotatef(25, 1.0, 0.0, 0.0);
	glScalef(2.0, 2.0, 2.0);
	//glutWireIcosahedron();
	//glutSolidSphere(1.0, 25, 25);
	glutWireSphere(1.0,25, 25);

	glOrtho(-1.5, 1.5, -1.5, 1.5, -10, 10);
	glPopMatrix();
	glutSwapBuffers();
}


void myReshape(GLint newWidth, GLint newHeght)
{
	glViewport(0, 0, newWidth, newHeght);
	glMatrixMode()


}
int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n"; 

	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);

	glutCreateWindow("show");
	init();
	glutDisplayFunc(&display);
	//glutMouseFunc(&myMouse);
	//glutSpecialFunc(&myKeyboardSpecial);
	//glutIdleFunc(&myIdle);
	glutReshapeFunc(&myReshape);
	//glutButtonBoxFunc(&buttonBoxFcn);
	//glutDialsFunc(&dialsFcn);
	//createGLUTMenus();
	glutMainLoop();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
