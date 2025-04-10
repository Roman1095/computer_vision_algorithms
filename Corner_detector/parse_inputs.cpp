#include "parse_inputs.h"

ParseResult parse_inputs(const vector<string>& args) {
    ParseResult result;
    vector<double> para = { 1.5, 162.0, 3.0, 0.35, 0.0, 1.0, 1.0 }; 

    if (!args.empty()) {
        result.I = imread(args[0], IMREAD_COLOR);
        if (result.I.empty()) {
            cerr << "Error loading image: " << args[0] << endl;
            exit(EXIT_FAILURE);
        }

        for (size_t i = 1; i < args.size() && i - 1 < para.size(); ++i) {
            try {
                para[i - 1] = stod(args[i]);
            }
            catch (...) {
                cerr << "Invalid parameter format: " << args[i] << endl;
            }
        }
    }
    else {
        string path;
        cout << "Enter image path: ";
        cin >> path;

        result.I = imread(path, IMREAD_COLOR);
        if (result.I.empty()) {
            cerr << "Error loading image: " << path << endl;
            exit(EXIT_FAILURE);
        }
    }

    result.C = para[0];
    result.T_angle = para[1];
    result.sig = para[2];
    result.H = para[3];
    result.L = para[4];
    result.Endpoint = para[5] != 0.0;
    result.Gap_size = static_cast<int>(para[6]);

    return result;
}