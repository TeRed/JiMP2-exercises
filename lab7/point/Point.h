//
// Created by albert on 26.04.17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H
class Point {
public:
    Point();
    Point(double x, double y);
    ~Point();

    void ToString(std::ostream &out) const;
    double Distance(const Point &other) const;

    double GetX() const;
    double GetY() const;

    friend std::ostream& operator<<(std::ostream& out, const Point& pkt);

protected:
    double x_, y_;
};

std::ostream& operator<<(std::ostream& out, const Point& pkt);
#endif //JIMP_EXERCISES_POINT_H
