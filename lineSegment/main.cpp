#pragma once
#include <fstream>
#include <filesystem>
#include "CoordinateDiagram.h"

using namespace std;
using namespace std::filesystem;

// Check if the file exists and is a regular file
bool isValidFilePath(const string& filepath) {
    path pathObj(filepath);

    if (exists(pathObj) && is_regular_file(pathObj)) {
        return true;
    }
    else {
        return false;
    }
}

// Read the coordinates from the file and return a vector of Line objects
vector<Line> readCoordinatesFromFile(const string& filename) {
    vector<Line> lines;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        char comma; // Use to read unnecessary characters
        int x1, y1, x2, y2;

        // Read the coordinates from the text line
        ss >> x1 >> comma >> y1 >> comma >> comma >> x2 >> comma >> y2;

        // Create a Line object and add it to the vector
        lines.push_back(Line(x1, y1, x2, y2));
    }
    file.close();
    return lines;
}

int main(int argc, char* argv[])
{
    // Get the filepath from the command-line argument
    string filepath;
    if (argc == 1) {
        // No filepath provided, use the default filepath
        filepath = "exinput.txt";
        cout << "No filepath provided, using the default filepath: " << filepath << endl;
    }
    else if (argc == 2) {
        // Get the filepath from the command-line argument
        filepath = argv[1];
    }
    else {
        // More than one argument provided
        cerr << "Usage: " << path(argv[0]).filename().string() << " [file_path]" << endl;
        return 1; // error
    }

    // Check if the file exists and is a regular file
    if (not isValidFilePath(filepath)) {
        cerr << "The default filepath \"" << filepath << "\" is invalid or does not exist." << endl;
        return 1; // error
    }
    
    // Read the coordinates from the file and create a CoordinateDiagram object
    vector<Line> lineVector = readCoordinatesFromFile(filepath);
    CoordinateDiagram cordSys(lineVector);
    string str;
    str = cordSys.toString();
    // cout << str; // Uncomment this line to print the output to the console
    
    // Write the output to a file
    string outputFilename = "output.txt";
    ofstream out(outputFilename);
    out << str;
    out.close();
    cout << "Done. The output is written to " << outputFilename << endl;

    return 0;
}