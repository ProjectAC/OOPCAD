#include "../stdafx.h"

#include "../include/definitions.h"

using namespace std;

namespace ACCAD
{

    Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    istream & ACCAD::operator>>(istream & in, Color & color)
    {
        //in >> color.r >> color.b >> color.g >> color.a;
        in.read((char *)&(color.r), sizeof(char) * 4);
        return in;
    }

    ostream & ACCAD::operator<<(ostream & out, const Color & color)
    {
        //out << color.r << color.b << color.g << color.a;
        out.write((const char*)&(color.r), sizeof(char) * 4);
        return out;
    }

}