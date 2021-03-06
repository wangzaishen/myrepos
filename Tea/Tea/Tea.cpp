// Tea.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <gl/glut.h>

GLint WIDTH = 400;
GLint HEIGHT = 400;


GLfloat anglex = 0.0;
GLfloat angley = 0.0;
GLfloat anglez = 0.0;
const GLint wWidth = 16;
const GLint wHeight = 16;

#define BITMAP_ID 0x4D42

GLuint texture[3];
GLint textureIndex = 0;

GLubyte image[wHeight][wWidth][3];
GLubyte image2[wHeight][wWidth][3];
GLubyte image3[wHeight][wWidth][3];

void setLight()
{

	GLfloat sun_light_postion[] = { 1.8f, 1.8f,1.8f,1.0f };
	GLfloat sun_light_ambient[] = { 0.2f, 0.2f,0.2f,1.0f };
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


void setMatrial()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(1.8, 1.8, 1.8);
	
	GLfloat sun_mat_ambient[] = { 1.0f, 1.0f,1.0f,0.5f };
	GLfloat sun_mat_diffuse[] = { 1.0f, 1.0f,1.0f,0.2f };
	GLfloat sun_mat_specular[] = { 1.0f, 1.0f,1.0f,0.5f };
	GLfloat sun_mat_emission[] = { 1.0f, 1.0f,1.0f,0.9f };
	GLfloat sun_mat_shininess = 110.0f;

	glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, sun_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, sun_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, sun_mat_shininess);
	
	//glColor3f(0.0, 1.0, 1.0);
	glutSolidSphere(0.1, 250, 250);

	glPopMatrix();
	glFlush();
}
#include <stdio.h>

const GLint BMP_Header_Length = 54;

GLint load_texture(const char* file_name)
{
	GLint width, height, total_bytes;
	GLubyte *pixels = 0;
	GLint last_texture_ID;
	GLuint texture_ID = 0;


	FILE* pFile;
	fopen_s(&pFile, file_name, "rb");
	if (pFile == 0)
	{
		exit(0);
	}

	fseek(pFile, 0x0012, SEEK_SET);
	fread(&width, 4, 1, pFile);
	fread(&height, 4, 1, pFile);
	fseek(pFile, BMP_Header_Length, SEEK_SET);

	{
		GLint line_bytes = width * 3;
		while (line_bytes % 4 != 0)
		{
			++line_bytes;

		}
		total_bytes = line_bytes * height;

		pixels = (GLubyte*)malloc(total_bytes);
		if (pixels == 0)
		{
			fclose(pFile);

			return 0;

		}

		if (fread(pixels, total_bytes, 1, pFile) <= 0)
		{
			free(pixels);
			fclose(pFile);
			return 0;

		}

		glGenTextures(1, &texture_ID);
		if (texture_ID == 0)
		{
			free(pixels);
			fclose(pFile);
			return 0;

		}

		glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture_ID);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
		glBindTexture(GL_TEXTURE_2D, texture[0]);

		free(pixels);

		return texture_ID;


	}


	//glBindTexture(GL_TEXTURE_2D, texture);


}

GLuint texface;


static GLint imagewidth;
static GLint imageheight;
static GLint pixellength;
static GLubyte *pixeldata;

void display()
{
	/*GLfloat dx = (GLfloat)mx / (GLfloat)WIDTH;
	GLfloat dy = (GLfloat)my / (GLfloat)HEIGHT;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f + dx, 0.0f + dy);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f + dx, 0.0f + dy);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f + dx, 1.0f + dy);
	glEnd();


	glPixelZoom(-0.5f, -0.5f);
	glRasterPos2i(1, 1);
	glCopyPixels(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2, GL_COLOR);
	*/
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);

	//glColor3f(0.0, 1.0, 0.0);
	glLoadIdentity();
	gluPerspective(75, 1, 1, 21);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//gluLookAt(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glBindTexture(GL_TEXTURE_2D, texface);

	setLight();
	setMatrial();

	//glBindTexture(GL_TEXTURE_2D, texface);
	GLfloat earth_mat_ambient[] = { 1.0f, 0.5f,0.5f,1.0f };
	GLfloat earth_mat_diffuse[] = { 0.5f, 0.5f,0.5f,1.0f };
	GLfloat earth_mat_specular[] = { 0.5f, 0.0f,1.0f,1.0f };
	GLfloat earth_mat_emission[] = { 0.0f, 0.0f,0.0f,1.0f };

	GLfloat earth_mat_shininess = 30.0f;

	glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);

	//glRotatef(angle, 0.0f, -1.0f, 0.0f);
	//glTranslatef(5.0f, 0.0f, 0.0f);
	glRotatef(anglex, 1.0, 0.0, 0.0);
	glRotatef(angley, 0.0, 1.0, 0.0);
	glRotatef(anglez, 1.0, 0.0, 1.0);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[textureIndex]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODELVIEW);
	//glutWireTeapot(1.5);
	glutSolidTeapot(1.5);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[textureIndex]);
	glBegin(GL_QUADS);
/*	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-6.0f, -3.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-6.0f, -3.0f, 1.5f);
	glTexCoord2f(5.0f, 1.0f);
	glVertex3f(6.0f, -3.0f, 1.5f);
	glTexCoord2f(5.0f, 0.0f);
	glVertex3f(6.0f, -3.0f, 0.0f);
*/
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-6.0f, -1.5f, -1.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-6.0f, -1.5f, 1.5f);
	glTexCoord2f(5.0f, 1.0f);
	glVertex3f(6.0f, -1.5f, 1.5f);
	glTexCoord2f(5.0f, 0.0f);
	glVertex3f(6.0f, -1.5f, -1.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();



	//glDrawPixels(imagewidth, imageheight, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixeldata);
	glFlush();
	glutSwapBuffers();
	//grab();

}
void upKey()
{
	anglez += 10.0;
	if (anglez > 360.0f)
	{
		anglez -= 360.0f;
	}
	//next[1] += 0.1;

}

void downKey()
{
	//next[1] -= 0.1;
	anglez -= 10.0;
	if (anglez < 0.0f)
	{
		anglez += 360.0f;
	}
}

void leftKey()
{
	//next[0] -= 0.1;
	angley -= 10.0;
	if (angley < 0.0f)
	{
		angley += 360.0f;
	}
}

void rightKey()
{
	//next[0] += 0.1;
	angley += 10.0;
	if (angley > 360.0f)
	{
		angley -= 360.0f;
	}
}

void resetKey()
{
	//next[0] = 0.5;
	//next[1] = 0.5;
	angley = 0.0;
	anglez = 0.0;
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
	case GLUT_KEY_F1:

		resetKey();
		glutPostRedisplay();

		break;



	}


}
void updateView(GLint width, GLint height)
{


}

void myReshape(GLint width, GLint height)
{
	if (height == 0)
	{

		height = 1;
	}

	HEIGHT = height;
	WIDTH = width;

	updateView(WIDTH, HEIGHT);

	
}


void myIdle()
{
	glutPostRedisplay();


}
void generateTex()
{
	for (GLint i = 0; i < wHeight; i++)
	{
		for (int j = 0; j < wWidth; j++)
		{
			int x = ((i & 4) ^ (j & 4)) * 255;
			image[i][j][0] = (GLubyte)x;
			image[i][j][1] = 0;
			image[i][j][2] = 0;

		}

	}
	for (GLint i = 0; i < wHeight; i++)
	{
		for (int j = 0; j < wWidth; j++)
		{
			int x = ((i & 4) ^ (j & 4)) * 255;
			image2[i][j][0] = 0;
			image2[i][j][1] = (GLubyte)x;
			image2[i][j][2] = 0;

		}

	}
	for (GLint i = 0; i < wHeight; i++)
	{
		for (int j = 0; j < wWidth; j++)
		{
			int x = ((i & 4) ^ (j & 4)) * 255;
			image3[i][j][0] = 0;
			image3[i][j][1] = 0;
			image3[i][j][2] = (GLubyte)x;

		}

	}
}

void buttonBoxFcn(GLint button, GLint action)
{



}

void dialsFcn(GLint dial, GLint degreeValue)
{



}
void init()
{

	glGenTextures(3, texture);
	generateTex();

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, wWidth, wHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, wWidth, wHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, wWidth, wHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glBindTexture(GL_TEXTURE_2D, last_texture_ID);


	glClearColor(0.0, 0.0, 0.0, 0.1);
	
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_TEXTURE_2D);

	setLight();
	texface = load_texture("tea4.bmp");
	FILE *pfile;
	fopen_s(&pfile, "tea6.bmp", "rb");
	if (pfile == 0)
	{
		exit(0);
	}

	fseek(pfile, 0x0012, SEEK_SET);
	fread(&imagewidth, sizeof(imagewidth), 1, pfile);
	fread(&imageheight, sizeof(imageheight), 1, pfile);
	pixellength = imagewidth * 3;
	while (pixellength%4 != 0)
	{
		pixellength++;
	}
	pixellength *= imageheight;

	pixeldata = (GLubyte*)malloc(pixellength);
	if (pixeldata == 0)
	{
		exit(0);
	}

	fseek(pfile, 54, SEEK_SET);
	fread(pixeldata, pixellength, 1, pfile);

	fclose(pfile);

}
#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4
void processMenuEvents(GLint option)
{
	switch (option)
	{
	case RED:
		textureIndex = 0;
		glutPostRedisplay();
		break;
	case GREEN:
		textureIndex = 1;
		glutPostRedisplay();
		break;
	case BLUE:
		textureIndex = 2;
		glutPostRedisplay();
		break;


	}


}

void createGLUTMenus()
{
	GLint menu;
	menu = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Red", RED);
	glutAddMenuEntry("Blue", BLUE);
	glutAddMenuEntry("Green", GREEN);


	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA |GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);

	glutCreateWindow("show");
	init();
	glutDisplayFunc(&display);
	//glutMouseFunc(&myMouse);
	glutSpecialFunc(&myKeyboardSpecial);
	glutIdleFunc(&myIdle);
	glutReshapeFunc(&myReshape);
	glutButtonBoxFunc(&buttonBoxFcn);
	glutDialsFunc(&dialsFcn);
	createGLUTMenus();
	glutMainLoop();

    std::cout << "Hello World!\n"; 
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
