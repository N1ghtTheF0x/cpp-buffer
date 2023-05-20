#include <NTF/Buffer.hpp>

#include <sstream>

namespace NTF
{
    Buffer::operator uint8_t *()
    {
        return pointer;
    }
    Buffer::operator size_t()
    {
        return length;
    }
    Buffer::Buffer(uint8_t* data,size_t size):
        pointer(data), length(size)
    {

    }
    Buffer::Buffer(size_t size):
        pointer(new uint8_t[size]), length(size)
    {

    }
    Buffer::Buffer(std::istream &input)
    {
        input.seekg(input.end);
        length = input.tellg();
        input.seekg(input.beg);
        auto buf = input.rdbuf();
        buf->sgetn((char*)pointer,length);
    }
    Buffer::Buffer(std::ifstream &stream)
    {
        stream.seekg(stream.end);
        length = stream.tellg();
        stream.seekg(stream.beg);
        auto buf = stream.rdbuf();
        buf->sgetn((char*)pointer,length);
    }
    Buffer::Buffer(std::fstream &stream)
    {
        stream.seekg(stream.end);
        length = stream.tellg();
        stream.seekg(stream.beg);
        auto buf = stream.rdbuf();
        buf->sgetn((char*)pointer,length);
    }
    Buffer::Buffer(const char* path)
    {
        std::ifstream stream(path);
        stream.seekg(stream.end);
        length = stream.tellg();
        stream.seekg(stream.beg);
        auto buf = stream.rdbuf();
        buf->sgetn((char*)pointer,length);
    }
    Buffer::Buffer(std::string path)
    {
        std::ifstream stream(path);
        stream.seekg(stream.end);
        length = stream.tellg();
        stream.seekg(stream.beg);
        auto buf = stream.rdbuf();
        buf->sgetn((char*)pointer,length);
    }
    Buffer::Buffer(std::stringstream path)
    {
        std::ifstream stream(path.str());
        stream.seekg(stream.end);
        length = stream.tellg();
        stream.seekg(stream.beg);
        auto buf = stream.rdbuf();
        buf->sgetn((char*)pointer,length);
    }
#ifdef Linux
    #include <unistd.h>
    void posix_read(int fd,void* dst,size_t size)
    {
        read(fd,dst,size);
    }
    Buffer::Buffer(int handle)
    {
        length = lseek(handle,0,SEEK_END);
        lseek(handle,0,SEEK_SET);
        pointer = new uint8_t[length];
        posix_read(handle,pointer,length);
    }
#endif
#ifdef Windows
    #include <windows.h>
    Buffer::Buffer(HANDLE handle)
    {
        https://learn.microsoft.com/en-us/windows/win32/fileio/opening-a-file-for-reading-or-writing#example-open-a-file-for-reading
    }
#endif
}