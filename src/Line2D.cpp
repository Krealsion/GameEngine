//
// Created by jdemoss on 1/15/20.
//

#include "Line2D.h"

Line2D::Line2D(Vector2 p1, Vector2 p2) {
    Slope = (p2.GetY() - p1.GetY()) / (p2.GetX() - p1.GetX());
    Intercept = p1.GetY() - p1.GetX() * Slope;
    RangeStart = std::min(p1.GetY(), p2.GetY());
    RangeEnd = std::max(p1.GetY(), p2.GetY());
    DomainStart = std::min(p1.GetX(), p2.GetX());
    DomainEnd = std::max(p1.GetX(), p2.GetX());
}
double Line2D::GetSlope() const {
    return Slope;
}
double Line2D::GetIntercept() const {
    return Intercept;
}
double Line2D::Evaluate(double x) const {
    return x * Slope + Intercept;
}
bool Line2D::BoundingCollisionCheck(Line2D o) const {
    if (DomainStart > o.DomainEnd){
        return false;
    }
    if (DomainEnd < o.DomainStart){
        return false;
    }
    if (RangeStart > o.RangeEnd) {
        return false;
    }
    if (RangeEnd < o.RangeStart) {
        return false;
    }
    return true;
}
bool Line2D::SharesDomainRange(const Line2D& l1, const Line2D& l2) {
    if (l1.DomainStart > l2.DomainEnd){
            return false;
        }
    if (l1.DomainEnd < l2.DomainStart){
        return false;
    }
    if (l1.RangeStart > l2.RangeEnd) {
        return false;
    }
    if (l1.RangeEnd < l2.RangeStart) {
        return false;
    }
    return true;
}
bool Line2D::CheckValueInDomain(double x) {
    if (x < DomainStart){
        return false;
    }
    if (x > DomainEnd) {
        return false;
    }
    return true;
}
bool Line2D::CheckLinesParallel(const Line2D& l1, const Line2D& l2) {
    return l1.Slope == l2.Slope;
}
