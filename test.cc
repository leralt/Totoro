#include <string.h>
#include <string>
#include <fstream>
#include <netinet/in.h>
#include "wrap.h"


void readFile(std::string filepath,char* buff){
    std::ifstream getfile;
    getfile.open(filepath,std::ios::in);
    getfile.read(buff,1024);
    getfile.close();
}

int main(){
    char buff[1024];
    readFile("/home/lyc/www/index.html",buff);
    printf("%s",buff);
}