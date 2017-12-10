#include <ifstream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
    ifstream file("Client.txt" , ios::in);
    if (!file.is_open()) {
     return 0;
    }
    string line , IP , port;
    getLine(file , line);
    int p = line.find(' ');
    if (p == -1) {
        throw std::invalid_argument("Bad argument");
    }
    istringstream(action.substr(0, p)) >> IP;
    istringstream(action.substr(p + 1 , line.size() - 2)) >> port;

    int portNum = 0;
    port >> portNum;
    // port num is int of the port number
    // IP is string of the IP
    file.close();
}

