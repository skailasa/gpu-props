#include "utils.hpp"

int main() {

    const std::string logFile = "bin/logFile.txt";
    std::ofstream fs;
    fs.open(logFile);
    device_info(fs);

    return 0;
}