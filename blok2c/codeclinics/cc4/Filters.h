//
// Created by Dean on 27/02/2024.
//
#pragma once

class Filter {
public:
    virtual double process(double input) = 0;
};


//                   IIRFilter
//   X[n] ---->(+)--->[ 1 sample ] ---> Y[n]
//              |                   |
//             (a)<-----------------
//
class IIRFilter : Filter {
    public:
    double process(double input) override {
        // Y[n] = X[n] + aY[n-1]
        feedback = input + (a * feedback);
        return feedback;
    }

    void setCoefficient(double coefficient) {
        // Do not exceed 1, for the safety of all our ears
        a = coefficient;
    }

private:
    double feedback { 0.0 };
    double a { 0.0 }; // Coefficient "a" is mostly used for feedback lines

};


//                    OneZero
//   X[n] ---->(+)--------------------> Y[n]
//              |                  |
//             (b)-->[ 1 sample ]-->
//
class FIRFilter : Filter {
    public:
    double process(double input) override {
        // Y[n] = X[n] - bX[n-1]
        auto output = input - (b * x1);

        x1 = input; // Recaching Delay
        return output;
    }

    void setCoefficient(double coefficient) {
        b = coefficient;
    }

private:
    double x1 {0.0 }; // x1 for a single sample delay
    double b { 0.0 };  // Coefficient "b" is usually used for feed forward lines

};


//                   OnePole
//   X[n] --(b)->(+)--->[ 1 sample ] ---> Y[n]
//              |                   |
//             (a)<-----------------
//
class OnePole : Filter {
    public:
    double process(double input) override {
        // Y[n] = bX[n] + aY[n-1]
        // You make this one:

    }

    void setCoefficient(double coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }

private:
    double feedback { 0.0 };
    double a { 0.0 };
    double b { 0.0 };
};


//                   4_Pole / Simple Cascade
//   X[n]--->[OnePole][OnePole][OnePole][OnePole]--->Y[n]
//
class SimpleLadder : Filter {
    public:
    double process(double input) override {

    }

    void setCoefficient(double coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }

private:
    double A { 0.0 };
    double B { 0.0 };
    double C { 0.0 };
    double D { 0.0 };


    double b { 0.0 };
    double a { 0.0 };
};


//                   4 Sample
//   X[n] --(b)->(+)--->[ 4 sample ] ---> Y[n]
//              |                   |
//             (a)<-----------------
//
class FourSample : Filter {
    public:
    double process(double input) override {
        // Y[n] = X[n] + aY[n-4]

    }

    void setCoefficient(double coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }


private:
    double feedback { 0.0 };
    double b { 0.0 };
    double a { 0.0 };
};


//                   Halve Biquad
//   X[n] --(b)->(+)--------------------> Y[n]
//                |                  |
//               (a1)<----------[ 1 sample ]
//                |                  |
//               (a2)<----------[ 1 sample ]
//
//
class HalfBiquad : Filter {
    public:
    double process(double input) override {
      // y[n] = bX[n] - a1Y[n-1] - a2Y[n-2]

    }

    void setBCoefficient(double coefficient){
        b = coefficient;
    }

    void setA1Coefficient(double coefficient) {
        a1 = coefficient;
    }

    void setA2Coefficient(double coefficient) {
        a2 = coefficient;
    }


private:
    double b;
    double a1;
    double a2;
};


class Biquad : Filter {
public:
    // Zoek een Biquad, en maak  'm :- )
    // Probeer het internet, of Will Pirkle, zijn verschillende benaderingen
    // Succes.

};
