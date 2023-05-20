#include <iostream>

#ifdef Windows
#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    int argc = __argc;
    char** argv = __argv;
#else
int main(int argc,char** argv)
{
#endif
    std::cout << "Hello World!" << std::endl;

    return EXIT_SUCCESS;
}