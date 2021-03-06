// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<GL/glut.h>
#include<math.h>


const int n = 20;
const GLfloat R = 0.5f;
const GLfloat Pi = 3.14f;

const GLfloat factor = 0.1f;
void myDisplay2(void)
{
	/*GLfloat x;
	std::cout << "Hello" << glEndList;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(1.0f, 0.0f);
	//glVertex2f(0.0f, -1.0f);
	//glVertex2f(0.0f, 1.0f);
	glEnd();
	std::cout << "Hello" << std::endl;
	*/
/*
	glBegin(GL_LINE_STRIP);
	for (x = -1.0f / factor; x < 1.0f / factor; x += 0.01f)
	{
		glVertex2f(x*factor, sin(x)*factor);



	}
	glEnd();
*/	//glFlush;
	
	glClear(GL_COLOR_BUFFER_BIT);
	//glPointSize(5.0f);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(2, 0x0f0f);
	glLineWidth(10.0);

	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.5f, 0.5f);
	glEnd();
	glFlush();

}


void cirDisplay1()
{
	GLfloat a = 1 / (2 - 2 * cos(72 * Pi / 180));
	GLfloat bx = a * cos(18 * Pi / 180);
	GLfloat by = a * sin(18 * Pi / 180);
	GLfloat cy = -a * cos(18 * Pi / 180);
	GLfloat
		PointA[2] = { 0, a },
		PointB[2] = { bx,by },
		PointC[2] = { 0.5,cy },
		PointD[2] = { -0.5,cy },
		PointE[2] = { -bx, by };


	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);


	glVertex2fv(PointA);
	glVertex2fv(PointB);
	glVertex2fv(PointC);
	glVertex2fv(PointD);
	glVertex2fv(PointE);


	glEnd();
	glFlush();


}
void cirDisplay()
{

	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);

	for (i = 0; i < n; i++)
	{
		glVertex2f(R*cos(2 * Pi / n * i), R*sin(2 * Pi / n * i));


	}
	glEnd();
	glFlush();


}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	//glFlush();

	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.5f, 0.5f);
	glEnd();
	glFlush();
}


class wcPt2D
{
public:
	GLfloat x, y;

};


void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);



}

void triangle(wcPt2D *verts)
{
	GLint k;
	glBegin(GL_TRIANGLES);
	for (k = 0; k < 3; k++)
	{
		glVertex2f(verts[k].x, verts[k].y);
	}
	glEnd();


}
void myDisplay3()
{
	wcPt2D verts[3] = { {-50.0, -25.0}, {50.0, -25.0 },{0.0,50.0} };
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glViewport(0, 0, 300, 300);
	triangle(verts);

	glFlush();

	glColor3f(1.0, 0.0, 0.0);
	glViewport(100, 0, 300, 300);
	glRotatef(190.0, 0.0, 0.0, 0.5);
	triangle(verts);
	glFlush();

}
const GLint WIDTH = 400;
const GLint HEIGHT = 400;

static GLfloat angle = 0.0f;
void myDisplay4()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, 1.0f, 1.0f, 20.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 5.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	{
		GLfloat sun_light_postion[] = { 0.0f, 0.0f,0.0f,1.0f };
		GLfloat sun_light_ambient[] = { 0.0f, 0.0f,0.0f,1.0f };
		GLfloat sun_light_diffuse[] = { 1.0f, 1.0f,1.0f,1.0f };
		GLfloat sun_light_specular[] = { 1.0f, 1.0f,1.0f,1.0f };

		glLightfv(GL_LIGHT1, GL_POSITION, sun_light_postion);
		glLightfv(GL_LIGHT1, GL_AMBIENT, sun_light_ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, sun_light_specular);

		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);

	}

	{
		
		GLfloat sun_mat_ambient[] = { 0.0f, 0.0f,0.0f,1.0f };
		GLfloat sun_mat_diffuse[] = { 0.0f, 0.0f,0.0f,1.0f };
		GLfloat sun_mat_specular[] = { 0.0f, 0.0f,0.0f,1.0f };
		GLfloat sun_mat_emission[] = { 0.5f, 0.0f,0.0f,1.0f };
		GLfloat sun_mat_shininess = 10.0f;

		glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
		glMaterialfv(GL_FRONT, GL_AMBIENT, sun_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, sun_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, sun_mat_shininess);

		glutSolidSphere(2.0, 40, 32);

	}


	{
	
		GLfloat earth_mat_ambient[] = { 0.0f, 0.0f,0.5f,1.0f };
		GLfloat earth_mat_diffuse[] = { 0.0f, 0.0f,0.5f,1.0f };
		GLfloat earth_mat_specular[] = { 0.5f, 0.0f,1.0f,1.0f };
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f,0.0f,1.0f };	
	
		GLfloat earth_mat_shininess = 30.0f;

		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);

		glRotatef(angle, 0.0f, -1.0f, 0.0f);
		glTranslatef(5.0f, 0.0f, 0.0f);
		glutSolidSphere(2.0, 40, 32);

	}
	glutSwapBuffers();
}


void myIdle(void)
{
	angle += 1.0f;
	if (angle >= 360.0f)
	{
		angle = 0.0f;
	}

	myDisplay4();
}
int main(int argc, char *argv[] )
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("first OpenGL!");


	//init();

	glutDisplayFunc(&myDisplay4);
	glutIdleFunc(&myIdle);
	glutMainLoop();


    std::cout << "Hello World!\n"; 

	return  0;
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
