#include <NTF/Buffer.hpp>

#include <sstream>

namespace NTF
{
    size_t Buffer::tellp() const
    {
        return writeOffset;
    }
    bool Buffer::seekp(size_t offset)
    {
        writeOffset = offset;
        return offset >= 0 && offset < length;
    }
    size_t Buffer::write(const void* src,size_t size)
    {
        auto pos = pointer + writeOffset;
        memcpy(pos,src,size);
        writeOffset += size;
        return writeOffset;
    }
    void Buffer::writeInt8(int8_t value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeInt16(int16_t value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeInt32(int32_t value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeInt64(int64_t value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeUInt8(uint8_t value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeUInt16(uint16_t value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeUInt32(uint32_t value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeUInt64(uint64_t value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeFloat(float value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeDouble(double value)
    {
        write(&value,sizeof(value));
    }
    void Buffer::writeString(char* string)
    {
        write(string,strlen(string));
    }
    void Buffer::writeString(std::string string)
    {
        writeString(string.c_str());
    }
    void Buffer::writeString(std::stringstream string)
    {
        writeString(string.str());
    }
}