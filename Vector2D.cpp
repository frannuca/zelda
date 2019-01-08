//
// Created by frannuca on 01.01.19.
//

#include "Vector2D.h"

Vector2D::Vector2D() :x(0),y(0){

}

Vector2D::Vector2D(float x_, float y_):x(x_),y(y_) {

}

Vector2D Vector2D::add(const Vector2D &v) const {
    return Vector2D(x+v.x,y+v.y);
}

Vector2D Vector2D::substract(const Vector2D &v) const {
    return Vector2D(x-v.x,y-v.y);
}

Vector2D Vector2D::multiply(const Vector2D &v) const {
    return Vector2D(x*v.x,y*v.y);
}

Vector2D Vector2D::divide(const Vector2D &v) const {
    return Vector2D(x/v.x,y/v.y);
}

Vector2D Vector2D::scalarMultiplication(const float &l) const {
    return Vector2D(x*l,y*l);
}

Vector2D Vector2D::scalarDivision(const float &l) const {
    return Vector2D(x/l,y/l);
}

Vector2D Vector2D::scalarSum(const float &l) const {
    return Vector2D(x+l,y+l);
}

Vector2D Vector2D::scalarSubstract(const float &l) const {
    return Vector2D(x-l,y-l);
}

Vector2D operator+(const Vector2D &a, const Vector2D &b) {
    return a.add(b);
}

Vector2D operator-(const Vector2D &a, const Vector2D &b) {
    return a.substract(b);
}

Vector2D operator/(const Vector2D &a, const Vector2D &b) {
    return a.divide(b);
}

Vector2D operator*(const Vector2D &a, const Vector2D &b) {
    return a.multiply(b);
}

Vector2D operator+(const Vector2D &a, const float &b) {
    return a.scalarSum(b);
}

Vector2D operator-(const Vector2D &a, const float &b) {
    return a.scalarSubstract(b);
}

Vector2D operator/(const Vector2D &a, const float &b) {
    return a.scalarDivision(b);
}

Vector2D operator*(const Vector2D &a, const float &b) {
    return a.scalarMultiplication(b);
}

Vector2D operator+(const float &a, const Vector2D &b) {
    return b.scalarSum(a);
}

Vector2D operator-(const float &a, const Vector2D &b) {
    return Vector2D(a-b.x,a-b.y);
}

Vector2D operator/(const float &a, const Vector2D &b) {
    return Vector2D(a/b.x,a/b.y);
}

Vector2D operator*(const float &a, const Vector2D &b) {
    return b.scalarMultiplication(a);
}

Vector2D& Vector2D::operator+=(const Vector2D &b) {
    x += b.x;
    y += b.y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D &b) {
    x -= b.x;
    y -= b.y;
    return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D &b) {
    x *= b.x;
    y *= b.y;
    return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D &b) {
    x /= b.x;
    y /= b.y;
    return *this;
}

Vector2D& Vector2D::operator+=(const float &b) {
    x +=b;
    y +=b;
    return *this;
}

Vector2D& Vector2D::operator-=(const float &b){
    x -=b;
    y -=b;
    return *this;
}

Vector2D& Vector2D::operator*=(const float &b) {
    x *=b;
    y*=b;
    return *this;
}

Vector2D& Vector2D::operator/=(const float &b) {
    x /=b;
    y/=b;
    return *this;
}

Vector2D::Vector2D(const Vector2D &that):x(that.x),y(that.y) {

}

void Vector2D::operator=(const Vector2D &that) {
    x=that.x;
    y=that.y;
}

std::ostream &operator<<(std::ostream &stream, const Vector2D &v) {
    stream<<"("<<v.x<<","<<v.y<<")";
    return stream;
}

Vector2D &Vector2D::zero() {
    x=0;
    y=0;
    return *this;
}
