#include <NTF/Buffer.hpp>

namespace NTF
{
    size_t Buffer::tellg() const
    {
        return readOffset;
    }
    bool Buffer::seekg(size_t offset)
    {
        readOffset = offset;
        return offset >= 0 && offset < length;
    }
    size_t Buffer::read(void* dst,size_t size)
    {
        auto pos = pointer + readOffset;
        memcpy(dst,pos,size);
        readOffset += size;
        return readOffset;
    }
    int8_t Buffer::readInt8()
    {
        int8_t value;
        read(&value,sizeof(value));
        return value;
    }
    int16_t Buffer::readInt16()
    {
        int16_t value;
        read(&value,sizeof(value));
        return value;
    }
    int32_t Buffer::readInt32()
    {
        int32_t value;
        read(&value,sizeof(value));
        return value;
    }
    int64_t Buffer::readInt64()
    {
        int64_t value;
        read(&value,sizeof(value));
        return value;
    }
    uint8_t Buffer::readUInt8()
    {
        uint8_t value;
        read(&value,sizeof(value));
        return value;
    }
    uint16_t Buffer::readUInt16()
    {
        uint16_t value;
        read(&value,sizeof(value));
        return value;
    }
    uint32_t Buffer::readUInt32()
    {
        uint32_t value;
        read(&value,sizeof(value));
        return value;
    }
    uint64_t Buffer::readUInt64()
    {
        uint64_t value;
        read(&value,sizeof(value));
        return value;
    }
    float Buffer::readFloat()
    {
        float value;
        read(&value,sizeof(value));
        return value;
    }
    double Buffer::readDouble()
    {
        double value;
        read(&value,sizeof(value));
        return value;
    }
    const char* Buffer::readString(size_t size)
    {
        char* string = new char[size+1];
        string[size] = '\0';
        read(string,size);
        return string;
    }
    const char* Buffer::readString()
    {
        return readString(strlen((const char*)(pointer + readOffset)));
    }
}