#include "../include/Renderer.h"
#include <GL/freeglut.h>

using namespace ACCAD;

void Renderer::render(const Vec2 &center, float theta, const Color &cborder, const Color &cinner, const std::vector<Vec2> &vertices)
{
    glPushMatrix();

    glTranslatef(center.x, center.y, 0);
    glRotatef(theta, 0, 0, 1);

    glColor4b(cborder.r, cborder.g, cborder.b, cborder.a);
    glBegin(GL_LINE_LOOP);
    for (auto &v : vertices)
        glVertex2f(v.x, v.y);
    glEnd();

    if (cinner.a)
    {
        glColor4b(cinner.r, cinner.g, cinner.b, cinner.a);
        glBegin(GL_POLYGON);
        for (auto &v : vertices)
            glVertex2f(v.x, v.y);
        glEnd();
    }

    glPopMatrix();

    return;
}