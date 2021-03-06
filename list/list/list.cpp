// list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <gl/glut.h>
#include <math.h>

const GLint WIDTH = 400;
const GLint HEIGHT = 400;
GLfloat angle = 0.0f;

#define ColoredVertex(c,v)do{glColor3fv(c);glVertex3fv(v);}while(0)

/*
void MaterialVertex()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);


}
*/
void setNormal(GLfloat* Point1, GLfloat* Point2, GLfloat* Point3)
{
	GLfloat normal[3];
	int i;
	for (i = 0; i < 3; i++)
	{
		normal[i] = (Point1[i] + Point2[i] + Point3[i]) / 3;

	}

	glNormal3fv(normal);


}
void myDisplay()
{
	static int list = 0;
	if (list == 0)
	{


		GLfloat
			PointA[] = { 0.5f, -sqrt(6.0f) / 12, -sqrt(3.0f) / 6 },
			PointB[] = { -0.5f, -sqrt(6.0f) / 12, -sqrt(3.0f) / 6 },
			PointC[] = { 0.0f, -sqrt(6.0f) / 12, -sqrt(3.0f) / 3 },
			PointD[] = { 0.0f, -sqrt(6.0f) / 4, 0 };


		GLfloat
			ColorR[] = { 1,0,0 },
			ColorG[] = { 0,1,0 },
			ColorB[] = { 0,0,1 },
			ColorY[] = { 1,1,0 };


		list = glGenLists(1);
		glNewList(list, GL_COMPILE);

		glBegin(GL_TRIANGLES);
		//ABC
		ColoredVertex(ColorR, PointA);
		ColoredVertex(ColorG, PointB);
		ColoredVertex(ColorB, PointC);

		ColoredVertex(ColorR, PointA);
		ColoredVertex(ColorB, PointC);
		ColoredVertex(ColorY, PointD);

		ColoredVertex(ColorB, PointC);
		ColoredVertex(ColorG, PointB);
		ColoredVertex(ColorY, PointD);

		ColoredVertex(ColorG, PointB);
		ColoredVertex(ColorB, PointA);
		ColoredVertex(ColorY, PointD);


		//glVertex2fv(PointA);
		//glVertex2fv(PointB);

		glEnd();
		glEndList();

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);

	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	glPushMatrix();
	glRotatef(angle, 1, 0.5, 0);
	glCallList(list);


	glPopMatrix();

	glutSwapBuffers();
}

void myIdle()
{
	++angle;
	if (angle >= 360.0f)
	{
		angle = 0.0f;
	}
	myDisplay();
}


void myDisplay2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();

	gluLookAt(1.0, 1.0, 4, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(1.0, 0.5, 1.0);
	glutWireCube(3.0);

	glutSwapBuffers();
}

void reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);

}

void myDisplay3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 0, 0, 0.5);
	glRectf(-1, -1, 0.5, 0.5);
	glColor4f(0, 1, 0, 0.5);
	glRectf(-0.5, -0.5, 1, 1);

	glutSwapBuffers();



}
void setLight()
{
	static const GLfloat light_position[] = { 1.0f,1.0f,-1.0f,1.0f };
	static const GLfloat light_ambient[] = { 0.2f,0.2f,0.2f,1.0f };
	static const GLfloat light_diffuse[] = { 1.0f,1.0f,1.0f,1.0f };
	static const GLfloat light_specular[] = { 1.0f,1.0f,1.0f,1.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}
void setMatirial(const GLfloat mat_diffuse[4],  GLfloat *mat_shininess)
{
	static const GLfloat mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	static const GLfloat mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void myDisplay4()
{
	const static GLfloat red_color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	const static GLfloat green_color[] = { 0.0f, 1.0f, 0.0f, 0.3f };
	const static GLfloat blue_color[] = { 0.0f, 0.0f, 1.0f, 0.5f };


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);

	setLight();
	GLfloat mat_shininess[] = { 0.0f, 0.0f, 0.0f, 30.0f };
	setMatirial(red_color, mat_shininess);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.5f);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

	glDepthMask(GL_FALSE);
	GLfloat mat_shininess2[] = { 0.0f, 0.0f, 0.0f, 30.0f };
	setMatirial(blue_color, mat_shininess2);
	glPushMatrix();
	glTranslatef(0.2f, 0.0f, -0.5f);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();

	GLfloat mat_shininess3[] = { 0.0f, 0.0f, 0.0f, 30.0f };
	setMatirial(green_color, mat_shininess3);
	glPushMatrix();
	glTranslatef(0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.15, 30, 30);
	glPopMatrix();

	glDepthMask(GL_TRUE);

	glutSwapBuffers();
}

GLfloat ori[2];
GLfloat next[2];

static GLfloat M_PI = 3.14f;

static GLfloat c = M_PI / 180.0f;

static GLfloat r = 1.5f, h = 0.0f;



void myDisplay5()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();
	//glMatrixMode(GL_PROJECTION);
	gluLookAt(0.1, 0.1, 0.1, 0, 0, 0, 0, 1, 0);

	glColor3f(0.5f, 0.5f, 0.5f);
	glutWireTeapot(0.5f);
	glFlush();
	
	//glColor4f(1, 0, 0, 0.5);
	//glRectf(-1, -1, 0.5, 0.5);
	/*
	glBegin(GL_LINES);
	glVertex2f(ori[0], ori[1]);
	glVertex2f(next[0], next[1]);
	
	glEnd();
	*/


	glutSwapBuffers();

}

void upKey()
{
	next[1] += 0.1;

}

void downKey()
{
	next[1] -= 0.1;

}

void leftKey()
{
	next[0] -= 0.1;

}

void rightKey()
{
	next[0] += 0.1;

}

void resetKey()
{
	next[0] = 0.5;
	next[1] = 0.5;

}
void myKeyboard(GLubyte key, GLint x, GLint y)
{
	switch (key)
	{
	case 'u':
		upKey();

		glutPostRedisplay();

		break;
	case 'd':

		downKey();
		glutPostRedisplay();

		break;
	case 'l':

		leftKey();
		glutPostRedisplay();

		break;
	case 'r':

		rightKey();
		glutPostRedisplay();

		break;
	case 'o':
		
		resetKey();
		glutPostRedisplay();

		break;


	}


}

void myKeyboardSpecial(GLint key, GLint x, GLint y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		leftKey();
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:

		upKey();
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		rightKey();
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:

		downKey();
		glutPostRedisplay();
		
		break;



	}


}

GLint oldmx;
GLint oldmy;

void myMouse(GLint button, GLint state, GLint x, GLint y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			oldmx = x;
			oldmy = y;
			//downKey();
			//glutPostRedisplay();
		}

		if (state == GLUT_UP)
		{
			if (x > oldmx)
			{
				rightKey();
			}
			if (x > oldmx)
			{
				leftKey();
			}
			if (y > oldmy)
			{
				upKey();

			}
			if (y < oldmy)
			{
				downKey();
			}
			glutPostRedisplay();
		}
		break;

	case  GLUT_MIDDLE_BUTTON:

		break;

	case GLUT_RIGHT_BUTTON:

		break;

	}


}

void myMouseMove(GLint x, GLint y)
{
	std::cout << "x->" << x << "y->" << y << std::endl;
	//oldmx = x;
	//oldmy = y;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glEnable(GL_DEPTH_TEST);
	//glShadeModel(GL_FLAT);
	ori[0] = 0.0;
	ori[1] = 0.0;
	next[0] = 0.5;
	next[1] = 0.5;

	oldmx = 0.0;
	oldmy = 0.0;
}
int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE |GLUT_DEPTH);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE );
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("OPenGL Windows");
	init();
	//glutDisplayFunc(&myDisplay5);
	glutDisplayFunc(&myDisplay5);
	//glutIdleFunc(&myIdle);
	//glutReshapeFunc(reshape);
	//glutKeyboardFunc(&myKeyboard);
	//glutSpecialFunc(&myKeyboardSpecial);
	//glutMouseFunc(&myMouse);
	//glutMotionFunc(&myMouseMove);


	glutMainLoop();

    std::cout << "Hello World!\n"; 

	return 0;
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
