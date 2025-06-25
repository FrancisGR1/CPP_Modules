#include "Point.hpp"

void runTest(const Point& a, const Point& b, const Point& c, const Point& p, const std::string& label) {
    bool result = bsp(a, b, c, p);
    std::cout << label << ": " << (result ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);

    // Inside
    runTest(a, b, c, Point(1.0f, 1.0f), "Test 1 - Inside");
    runTest(a, b, c, Point(0.5f, 0.5f), "Test 2 - Inside");
    runTest(a, b, c, Point(2.0f, 2.0f), "Test 3 - Inside");

    // On Edge
    runTest(a, b, c, Point(0.0f, 0.0f), "Test 4 - On Vertex A");
    runTest(a, b, c, Point(2.5f, 0.0f), "Test 5 - On Edge AB");
    runTest(a, b, c, Point(0.0f, 2.5f), "Test 6 - On Edge AC");

    // Outside
    runTest(a, b, c, Point(-1.0f, -1.0f), "Test 7 - Outside");
    runTest(a, b, c, Point(5.0f, 5.0f), "Test 8 - Outside");
    runTest(a, b, c, Point(3.0f, 3.0f), "Test 9 - Outside");
    runTest(a, b, c, Point(5.0f, 1.0f), "Test 10 - Outside");

    // Degenerate triangle (zero area)
    Point d(1.0f, 1.0f);
    runTest(d, d, d, Point(1.0f, 1.0f), "Test 11 - Degenerate, same point");
    runTest(d, d, d, Point(2.0f, 2.0f), "Test 12 - Degenerate, outside");

    return 0;
}
