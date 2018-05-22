#include "..\include\definitions.h"

using namespace std;
using namespace ACCAD;

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

istream & ACCAD::operator>>(stream & in, Color & color)
{
    //in >> color.r >> color.b >> color.g >> color.a;
    in.read(&(color.r), sizeof(char) * 4);
    return in;
}

ostream & ACCAD::operator<<(ostream & out, const Color & color)
{
    //out << color.r << color.b << color.g << color.a;
    out.read(&(color.r), sizeof(char) * 4);
    return out;
}
