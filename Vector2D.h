//
// Created by frannuca on 01.01.19.
//

#ifndef ATTACKOVERTIME_VECTOR2D_H
#define ATTACKOVERTIME_VECTOR2D_H

#include <iostream>
class Vector2D {

public:
    float x,y;
    Vector2D();
    Vector2D(float x,float y);

    Vector2D(const Vector2D& that);
    void operator=(const Vector2D& that);

    Vector2D add(const Vector2D& v) const;
    Vector2D substract(const Vector2D& v) const;
    Vector2D multiply(const Vector2D& v) const;
    Vector2D divide(const Vector2D& v) const;
    Vector2D scalarMultiplication(const float& l) const;
    Vector2D scalarDivision(const float& l) const;
    Vector2D scalarSum(const float& l) const;
    Vector2D scalarSubstract(const float& l) const;
    Vector2D& zero();
    friend Vector2D operator+(const Vector2D& a, const Vector2D& b);
    friend Vector2D operator-(const Vector2D& a, const Vector2D& b);
    friend Vector2D operator/(const Vector2D& a, const Vector2D& b);
    friend Vector2D operator*(const Vector2D& a, const Vector2D& b);

    friend Vector2D operator+(const Vector2D& a, const float& b);
    friend Vector2D operator-(const Vector2D& a, const float& b);
    friend Vector2D operator/(const Vector2D& a, const float& b);
    friend Vector2D operator*(const Vector2D& a, const float& b);

    friend Vector2D operator+(const float& a, const Vector2D& b);
    friend Vector2D operator-(const float& a, const Vector2D& b);
    friend Vector2D operator/(const float& a, const Vector2D& b);
    friend Vector2D operator*(const float& a, const Vector2D& b);


    Vector2D& operator+=(const Vector2D& b);
    Vector2D& operator-=(const Vector2D& b);
    Vector2D& operator*=(const Vector2D& b);
    Vector2D& operator/=(const Vector2D& b);

    Vector2D& operator+=(const float& b);
    Vector2D& operator-=(const float& b);
    Vector2D& operator*=(const float& b);
    Vector2D& operator/=(const float& b);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
};


#endif //ATTACKOVERTIME_VECTOR2D_H
