#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

const double PI = 3.14159265358979;

int n;
double px, py;
double qx, qy;

int main() {
    cin >> n >> px >> py >> qx >> qy;
    double rx = (px + qx) / 2.0L;
    double ry = (py + qy) / 2.0L;

    double lens = sqrt((rx - px) * (rx - px) + (ry - py) * (ry - py));
    cout << lens << endl;
    double sazimuth = atan2(py - ry, px - rx);

    double qazimuth = sazimuth + 2.0 * PI / n;
    double hy = lens * sin(qazimuth), hx = lens * cos(qazimuth);
    hx += rx, hy += ry;

    printf("%.12f %.12f\n", hx, hy);
    return 0;
}