#include <iostream>

#ifndef _Point2D_HPP_
#define _Point2D_HPP_

using namespace std;

template <typename T>
class Point2D;

template <typename T>
ostream& operator<<(ostream&, Point2D<T> const &);


/*============================*/
/*         Point2D ()         */
/*============================*/
template <typename T>
class Point2D {
  protected:
    T x;
    T y;

  public:
    Point2D(const T& x, const T& y);

    Point2D();

    Point2D(const Point2D& p);

    T getX() const;

    T getY() const;

    void setX(const T& x);

    void setY(const T& y);

    void translate(const T& x, const T& y);

    friend ostream& operator<< <T>(ostream&, Point2D<T> const &);
};

///// Constructors /////
template <typename T>
Point2D<T>::Point2D(const T& x, const T& y) {
    this->x = x;
    this->y = y;
}

template <typename T>
Point2D<T>::Point2D() {
    this->x = 0;
    this->y = 0;
}

template <typename T>
Point2D<T>::Point2D(const Point2D& p) {
    this->x = p.getX();
    this->y = p.getY();
}

///// Getters /////
template <typename T>
T Point2D<T>::getX() const {
    return this->x;
}

template <typename T>
T Point2D<T>::getY() const {
    return this->y;
}

///// Setters /////
template <typename T>
void Point2D<T>::setX(const T& x) {
    this->x = x;
}

template <typename T>
void Point2D<T>::setY(const T& y) {
    this->y = y;
}

///// Translate method /////
template <typename T>
void Point2D<T>::translate(const T& x, const T& y) {
    this->x += x;
    this->y += y;
}


// Surcharge de l'opérateur << : affichage des caractéristiques du point
template <typename T>
ostream& operator<<(ostream& os, Point2D<T> const &p)
{
    os << "[" << p.getX() << ";" << p.getY()<<"]";
    return os;
}

#endif