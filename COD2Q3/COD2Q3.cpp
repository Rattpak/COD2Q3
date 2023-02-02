#include <iostream>
#include <fstream>
#include <string>

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
    std::string data = " 0 0 0 0.5 0.5";
    std::string line;
    char first;
    while (std::getline(input, line)) {
        // Add your own code here to process each line
        first = line[1];
        if (first == '(') {
            for (int i = 0; i < line.length(); ++i) {
                if (isalpha(line[i])) {
                    int j = i;
                    while (j < line.length() && line[j] != ' ') {
                        ++j;
                    }
                    // Remove everything after the next space
                    line.erase(j, line.length() - 1);
                    line += data;
                    break;
                }
            }
        }

        // Write the modified line to the output file
        output << line << '\n';
    }

    input.close();
    output.close();
}