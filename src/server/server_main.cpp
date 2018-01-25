/*
 * main.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: jonathan
 */
#include <iostream>
using namespace std;
#include "Server.h"
#include <stdlib.h>;
#include <fstream>
#include <vector>
#include "Command.h"

using namespace std;
int main() {
    ifstream file;
    file.open("Server.txt" , ios::in);
    if (!file.is_open()) {
        //return;
    }
    vector<string> strings;
    string port;
    getline(file , port);
    int portNum = atoi(port.c_str());
    // port num is int of the port number
    // IP is string of the IP
    file.close();
    Server server(portNum);
    try{
        server.start();
    } catch (const char *msg){
        cout << "Cannot start server. reason- " << msg << endl;
        exit(-1);
    }
}
