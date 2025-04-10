#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "corner.h"
#include "parse_inputs.h"
#include "mark.h"

using namespace cv;
using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) {

    auto start = high_resolution_clock::now();
    
    vector<string> args(argv + 1, argv + argc);
    ParseResult params = parse_inputs(args);

    if (params.I.empty()) {
        cerr << "Error: Could not load image!" << endl;
        return -1;
    }

    CornerResult result = corner(
        params.I,
        params.C,
        params.T_angle,
        params.sig,
        params.H,
        params.L,
        params.Endpoint,
        params.Gap_size
    );

    Mat marked_image = params.I.clone();
    for (const auto& p : result.corners) {
        marked_image = mark(marked_image, p.x, p.y, 5);
    }

    imwrite("result.jpg", marked_image);

    auto stop = high_resolution_clock::now();
    auto duraction = duration_cast<seconds>(stop - start);

    cout << duraction.count() << " - Sec" << endl;

    cout << "Detected " << result.corners.size() << " corners. Results saved to result.jpg" << endl;

    cout << "\nUsed parameters:\n"
        << "C: " << params.C << endl
        << "T_angle: " << params.T_angle << endl
        << "sig: " << params.sig << endl
        << "H: " << params.H << endl
        << "L: " << params.L << endl
        << "Endpoint: " << (params.Endpoint ? "true" : "false") << endl
        << "Gap_size: " << params.Gap_size << endl;

    return 0;
}
