#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void convertMap(const std::string&);

int main()
{
    std::cout << "Enter file path: ";
    std::string filepath;
    std::getline(std::cin, filepath);

    convertMap(filepath);
    std::cout << "Converted" << std::endl;
    return 0;
}

void convertMap(const std::string& filepath) {
    std::ifstream input(filepath);
    if (!input) {
        std::cerr << "Error opening file: " << filepath << std::endl;
        return;
    }

    // Generate the output file path by appending "_q3" before the file extension
    std::size_t pos = filepath.find_last_of('.');
    std::string outputFilePath = filepath.substr(0, pos) + "_q3" + filepath.substr(pos);

    std::ofstream output(outputFilePath);
    if (!output) {
        std::cerr << "Error creating file: " << outputFilePath << std::endl;
        return;
    }

    // Skip the first 3 lines
    for (int i = 0; i < 3; ++i) {
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Iterate through every line after the first 3
    std::string waw_lightmap = "lightmap_gray";
    std::string line;
    char first;
    while (std::getline(input, line)) {
        first = line[1];
        if (first == '(') {
            //remove everything after cod lightmap and the weird zero that serves no function
            line = line.substr(0, line.find(waw_lightmap) - 3);
            std::string data = ""; //all texture data from cod
            for (int i = 0; i < line.length(); ++i) {
                if (isalpha(line[i])) {
                    int j = i;
                    while (j < line.length() && line[j] != ' ') {
                        ++j;
                    }
                    data = line.substr(j + 1, line.size());
                    line = line.substr(0, j); //trim line so we can add modified texture data
                    break;
                }
            }
            std::stringstream ss;
            ss << data;
            std::vector<float> vecData;
            std::string temp;
            float num;
            while (!ss.eof()) { //store all texture data in vector for manipulation
                ss >> temp;
                if (std::stringstream(temp) >> num) {
                    vecData.push_back(num);
                }
            }
            line = line + " " + std::to_string(vecData[2]) + " " + std::to_string(vecData[3]) + " " + std::to_string(vecData[4]) + " " + std::to_string(vecData[0]/512) + " " + std::to_string(vecData[1]/512);
        }
        // Write the modified line to the output file
        output << line << '\n';
    }

    input.close();
    output.close();
}