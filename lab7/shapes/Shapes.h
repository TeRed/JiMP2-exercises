//
// Created by albert on 26.04.17.
//

#ifndef JIMP_EXERCISES_SHAPES_H
#define JIMP_EXERCISES_SHAPES_H
namespace shape {
    class Shape{
    public:
        Shape(){};
        ~Shape(){};
        virtual void draw() = 0;
    };

    class Circle : public Shape {
    private:
        unsigned int radius;
    public:
        Circle(unsigned int);
        ~Circle(){};
        virtual void draw();
    };

    class Square : public Shape {
    private:
        unsigned int side;
    public:
        Square(unsigned int);
        ~Square(){};
        virtual void draw();
    };

    class Triangle : public Shape {
    private:
        unsigned int side;
    public:
        Triangle(unsigned int);
        ~Triangle(){};
        virtual void draw();
    };

}
#endif //JIMP_EXERCISES_SHAPES_H
