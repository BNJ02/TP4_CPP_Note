#ifndef _Polygone_HPP_
#define _Polygone_HPP_

#include <iostream>

#include "Point2D.hpp"
#include <vector>
#include <regex>

using namespace std;

template <typename T>
class Polygone;

template <typename T>
ostream& operator<<(ostream &, Polygone<T> const&);

template <typename T>
class Polygone {

protected:
  vector<Point2D<T>> sommets;

public: 
  Polygone();
  Polygone(string stringListePoints);
  Polygone(vector<Point2D<T>> listeSommeets);
  Polygone(Polygone<T> const& poly);
  vector<Point2D<T>> getSommets() const;
  void setSommets(vector<Point2D<T>> listeSommets);
  void addPoint(Point2D<T>);
  void translate(T x,T y);

  friend ostream& operator<< <T>(ostream &, Polygone const&);

};

/*============================*/
/*         Polygone()         */
/*============================*/
template <typename T>
Polygone<T>::Polygone() {
}

/*============================================================*/
/*         Polygone(vector<Point2D<T>> listeSommets)          */
/*============================================================*/
template <typename T>
Polygone<T>::Polygone(vector<Point2D<T>> poly) {
  this->sommets = poly;
}

/*============================================*/
/*        Polygone(Polygone<T> poly)          */
/*============================================*/
template <typename T>
Polygone<T>::Polygone(Polygone<T> const& poly) {
  this->sommets = poly.getSommets();
}

/*============================================*/
/*     Polygone(string stringListePoints)     */
/*============================================*/
template <typename T>
Polygone<T>::Polygone(string stringListePoints) {
  // Define regular expression, named pattern
  regex regex("\\[(-?\\d+);(-?\\d+)\\]");

  // Look for similitudes in the string
  smatch match;
  string::const_iterator searchStart(stringListePoints.cbegin());

  // Vector of Points2D
  vector<Point2D<int>> points;

  while (regex_search(searchStart, stringListePoints.cend(), match, regex)) {
    // Add point in the vector
    Point2D<int> point(stoi(match[1]), stoi(match[2]));
    points.push_back(point);

    // Update of starting point for the next seek
    searchStart = match.suffix().first;
  }

  this->sommets = points;
}

/*================================================*/
/*        setSommets() : vector<Point2D<T>>       */
/*================================================*/
template <typename T>
void Polygone<T>::setSommets(vector<Point2D<T>> listeSommets){
  this->sommets = listeSommets;
}

/*================================================*/
/*        getSommets() : vector<Point2D<T>>       */
/*================================================*/
template <typename T>
vector<Point2D<T>> Polygone<T>::getSommets() const {
  return this->sommets;
}

/*================================================*/
/*           addPoint(Point2D<T>) : void          */
/*================================================*/
template <typename T>
void Polygone<T>::addPoint(Point2D<T> point){
  this->sommets.push_back(point);
}

/*================================================*/
/*           translate(T x, T y) : void           */
/*================================================*/
template <typename T>
void Polygone<T>::translate(T x,T y)
{
  //On parcours le tableau de sommets
  for (auto it = begin(sommets); it!= end(sommets); ++it)
  { 
    it->translate(x,y);
  }
}

/*================================================*/
/*                  operator<<                    */
/*================================================*/

template <typename T>
std::ostream& operator<<(std::ostream &o, Polygone<T> const &R)
{
  vector<Point2D<T>> sommetsPoly = R.getSommets();
  if (sommetsPoly.size() == 0) {
    o <<"Le polygone ne contient aucun point" << endl;
  } else if (sommetsPoly.size() == 1) {
    o <<"Le polygone contient un seul point : " << sommetsPoly[0] << endl;
  } else {
    //o <<"Le polygone contient plusieurs points : ";
    for (auto const somm : sommetsPoly) {
      o << somm << " ";
    }
  }
  return o;
}
#endif