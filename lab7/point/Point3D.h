//
// Created by albert on 26.04.17.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H
#include "Point.h"

class Point3D : public Point {
protected:
    double z_;
public:
    Point3D();
    Point3D(double x, double y, double z);
    ~Point3D();

    void ToString(std::ostream &out) const;
    double Distance(const Point3D &other) const;

    double GetZ() const;
};
#endif //JIMP_EXERCISES_POINT3D_H
