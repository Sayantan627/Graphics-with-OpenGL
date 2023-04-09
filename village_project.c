#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define PI 3.1416

int i, j, k;
float sun_spin = 0;
float ax = 0, bx = 0, cx = 0, dx = 0;
float spin = 0.0;

void init(void)
{
    glClearColor(.40, .110, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void triangle(float a, float b, float c, float d, float e, float f)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glEnd();
}

void quads(float a, float b, float c, float d, float e, float f, float g, float h)
{

    glBegin(GL_QUADS);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glEnd();
}

///*** Circle_Model***///
void circle(double rad)
{
    int points = 50;
    double delTheta = (2.0 * PI) / (double)points;
    double theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for (i = 0; i <= 50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta), rad * sin(theta));
        }
    }
    glEnd();
}
void draw_circle(float a, float b, float c) //(a,b) => coordinate of translated origin; c => radius of circle
{
    glPushMatrix();
    glTranslatef(a, b, 0);
    circle(c);
    glPopMatrix();
}
void movingSun()
{
    glPushMatrix();
    glRotatef(-sun_spin, 0, 0, -1);
    glTranslatef(500, 0, 0);
    circle(30);
    glPopMatrix();
}
///*** Cloud_Model***///
void drawCloud1()
{
    glColor3f(1.25, 0.924, 0.930);
    draw_circle(320, 210, 15); // Top left
    draw_circle(340, 225, 16); // Top
    draw_circle(360, 210, 16); // Right
    // middle_Fill
    draw_circle(355, 210, 16);
    draw_circle(350, 210, 16);
    draw_circle(345, 204, 10);
    draw_circle(340, 204, 10);
    draw_circle(335, 204, 10);
    draw_circle(330, 204, 10);
    draw_circle(325, 204, 10);
    draw_circle(320, 204, 10);
    draw_circle(315, 204, 10);
    draw_circle(305, 204, 10);
}

void drawCloud2()
{
    glColor3f(1.25, 0.924, 0.930);
    draw_circle(305, 205, 10); // Left Part
    draw_circle(320, 210, 15); // Top
    draw_circle(334, 207, 10); // Right
    draw_circle(320, 207, 10); // Bottom
}

void drawCloud3()
{
    glColor3f(1.25, 0.924, 0.930);
    draw_circle(300, 200, 15); // Left part
    draw_circle(320, 210, 15); // Top left
    draw_circle(340, 220, 16); // Top
    draw_circle(360, 210, 15); // Top right
    draw_circle(380, 200, 15); // Right
    draw_circle(360, 190, 20); // Bottom right
    draw_circle(320, 190, 20); // Bottom left
    draw_circle(340, 190, 20); // Bottom
}

void hillBig()
{
    glColor3f(0.38, 0.41, 0.36);
    triangle(70, 70, 200, 225, 330, 70);
    // Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(200, 225);
    glVertex2i(230, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 190);
    glVertex2i(190, 180);
    glVertex2i(170, 190);
    glEnd();
}
void hillSmall()
{
    glColor3f(0.11, 0.23, 0.36);
    triangle(250, 100, 310, 175, 370, 100);
    // Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(290, 150);
    glVertex2i(310, 175);
    glVertex2i(330, 150);
    glVertex2i(325, 140);
    glVertex2i(310, 150);
    glVertex2i(300, 140);
    glEnd();
}
///*** Tilla_Model ***///
void tillaModel1()
{
    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.0);
    glVertex2i(125, 70);
    glVertex2i(150, 80);
    glVertex2i(160, 90);
    glVertex2i(170, 90);
    glVertex2i(180, 100);
    glVertex2i(190, 105);
    glVertex2i(200, 108);
    glVertex2i(300, 110);
    glVertex2i(300, 70);
    glEnd();
}

void tillaModel2()
{

    glColor3f(0.1, 1.293, 0.0);
    /// Left_Part
    draw_circle(430, 90, 30);
    draw_circle(420, 87, 30);
    draw_circle(410, 80, 30);
    draw_circle(400, 80, 30);
    draw_circle(390, 70, 30);
    /// Right_Part
    draw_circle(445, 80, 30);
    draw_circle(455, 75, 30);
    draw_circle(465, 70, 30);
    draw_circle(470, 65, 30);
    draw_circle(480, 60, 30);
    draw_circle(485, 55, 20);
}
///*** House_Model ***///
void house()
{
    // House_Roof
    glColor3f(0.19, 0.20, 0.81);
    quads(285, 105, 285, 130, 380, 115, 380, 105);
    // House_Roof_Shadow
    glColor3f(.890, 0.0, 0.0);
    quads(285, 105, 285, 120, 380, 105, 380, 105);
    // House_Fence
    glColor3f(.555, 1.0, 1.0);
    quads(290, 70, 290, 104, 375, 104, 375, 70);
    // House_Fence_Shadow
    glColor3f(.555, 0.924, 0.930);
    quads(310, 70, 350, 104, 375, 104, 375, 70);
    // House_Door
    glColor3f(0.38, 0.41, 0.36);
    quads(330, 70, 330, 100, 350, 100, 350, 70);
    // House_Window1
    glColor3f(0.38, 0.21, 0.26);
    quads(295, 75, 295, 90, 310, 90, 310, 75);
    // House_Window2
    glColor3f(0.38, 0.21, 0.26);
    quads(312, 75, 312, 90, 327, 90, 327, 75);
    // House_Window3
    glColor3f(0.38, 0.21, 0.26);
    quads(355, 75, 355, 90, 370, 90, 370, 75);
    // House_Small_Roof
    glColor3f(1.0, 0.0, 0.0);
    quads(250, 90, 257, 104, 290, 104, 290, 90);
    // House_Small_Fence
    glColor3f(.555, .724, .930);
    quads(255, 70, 255, 90, 290, 90, 290, 70);
    // House_Small_Door
    glColor3f(0.11, 0.23, 0.36);
    quads(260, 70, 260, 80, 285, 80, 285, 70);
}
///*** Field_Model ***///
void field()
{
    // Field
    glColor3f(0.533, 1.293, 0.0);
    quads(0, 50, 0, 70, 1000, 70, 1000, 50);
    // Field_Shadow
    glColor3f(0.1, 1.293, 0.0);
    quads(0, 0, 0, 50, 1000, 50, 1000, 0);
}
///*** Tree_Model ***///
void treeModel1()
{
    draw_circle(110, 110, 15);
    draw_circle(110, 100, 15);
    glColor3f(0.38, 0.21, 0.26);
    quads(109, 70, 109, 90, 111, 90, 111, 70);
}

void treeModel2()
{
    triangle(125, 123, 133, 145, 141, 123);
    glColor3f(0.38, 0.21, 0.26);
    quads(132, 110, 132, 124, 134, 124, 134, 110);
}

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model()
{
    glColor3f(0.38, 0.41, 0.36);
    quads(375, 100, 380, 240, 384, 240, 390, 100);
}

///*** Windmill_Blades_Model ***///
void Windmill_Blade()
{
    // Blade_One
    glPushMatrix();
    glRotatef(spin, 0, 0, 90);
    quads(-5, 0, -85, -36, -83, -37, -3, -8);
    glPopMatrix();
    // Blade_Two
    glPushMatrix();
    glRotatef(spin, 0, 0, 90);
    quads(0, 5, 45, 70, 50, 73, 5, 0);
    glPopMatrix();
    // Blade_Three
    glPushMatrix();
    glRotatef(spin, 0, 0, 90);
    quads(68, -78, 0, 0, 5, 5, 70, -77);
    glPopMatrix();
}
///*** Windmill_Final_Model ***///
void Windmill()
{
    // Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();
    // Windmill_Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380, 250, 0);
    circle(10);
    glPopMatrix();
    // Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380, 251, 0);
    Windmill_Blade();
    glPopMatrix();
}
// Object

///*** Sun ***///
void Sun()
{
    glColor3f(1, 1, 0);
    glPushMatrix();
    movingSun();
    glPopMatrix();
}

void cloud_two()
{
    glPushMatrix();
    glTranslatef(bx + 100, 150, 0);
    drawCloud1();
    glPopMatrix();
}

void cloud_four()
{
    glPushMatrix();
    glTranslatef(dx + 300, 125, 0);
    drawCloud2();
    glPopMatrix();
}

void house_one()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_two()
{
    glPushMatrix();
    glTranslatef(480, 0, 0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_three()
{
    glPushMatrix();
    glTranslatef(320, 37, 0);
    house();
    glPopMatrix();
}
///*** Hill_big_One ***///
void Hill_Big_One()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    hillBig();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two()
{
    glPushMatrix();
    glTranslatef(550, -20, 0);
    hillBig();
    glPopMatrix();
}
///*** Hill_Small_One ***///
void Hill_Small_One()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    hillSmall();
    glPopMatrix();
}
/// *** Tilla_One_Model_One ***///

void Tilla_One()
{

    glPushMatrix();
    glTranslatef(0, 0, 0);
    tillaModel1();
    glPopMatrix();
}
/// *** Tilla_Two_Model_Two ***///
void Tilla_Two()
{

    glPushMatrix();
    glTranslatef(0, 0, 0);
    tillaModel2();
    glPopMatrix();
}
/// *** Tilla_Four_Model_One ***///
void Tilla_Four()
{

    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380, 0, 0);
    tillaModel1();
    glPopMatrix();
}
///*** Tree_1 ***///
void Tree_One()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    treeModel1();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(540, 0, 0);
    treeModel1();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750, 0, 0);
    treeModel1();
    glPopMatrix();
}
void Tree_Ten()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(90, -2, 0);
    treeModel2();
    glPopMatrix();
}
void Tree_Eleven()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125, 0, 0);
    treeModel2();
    glPopMatrix();
}
void Tree_Twelve()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(408, -22, 0);
    treeModel2();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0, -10, 0);
    Windmill();
    glPopMatrix();
}

void Windmill_Two()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508, -70, 0);
    Windmill();
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    ///*** Object_Layer ***///
    Sun();
    Hill_Big_One();
    Tilla_Four();
    house_three();
    Hill_Big_Two();
    Hill_Small_One();
    cloud_four();
    Windmill_One();
    Windmill_Two();
    Tilla_One();
    Tilla_Two();
    house_one();
    house_two();
    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();
    cloud_two();
    field();
    glFlush();
}

void timer(int value)
{
    sun_spin += 0.001;
    spin += 0.1;
    ax += 0.03;
    bx += 0.05;
    cx += 0.07;
    dx += 0.10;
    if (cx > 1000)
    {
        cx = -300;
    }
    if (bx > 1000)
    {
        bx = -400;
    }
    if (cx > 1000)
    {
        cx = -400;
    }
    if (dx > 1000)
    {
        dx = -500;
    }
    glutPostRedisplay();
    glutTimerFunc(2, timer, 0);
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1800, 1800);
    glutCreateWindow("A Village Scene");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
}