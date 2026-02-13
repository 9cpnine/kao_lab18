#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1, Rect *R2){

    double r1_right = R1->x + R1->w;
    double r2_right = R2->x + R2->w;
    double w_overlap = (r1_right < r2_right ? r1_right : r2_right) - (R1->x > R2->x ? R1->x : R2->x);

    double r1_bottom = R1->y - R1->h;
    double r2_bottom = R2->y - R2->h;
    double h_overlap = (R1->y < R2->y ? R1->y : R2->y) - (r1_bottom > r2_bottom ? r1_bottom : r2_bottom);

    if(w_overlap <= 0 || h_overlap <= 0) return 0;

    return w_overlap * h_overlap;
}