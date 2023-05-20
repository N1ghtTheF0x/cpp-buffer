#ifndef __NTF_BUFFER_HPP
#define __NTF_BUFFER_HPP

#include <fstream>
#include <cstring>

namespace NTF
{
    /**
     * @brief Easy to use Buffer for reading/writing data into a pointer
     * 
     */
    class Buffer
    {
    protected:
        /**
         * @brief Pointer to the data
         */
        uint8_t* pointer = nullptr;
        /**
         * @brief Length of the data
         */
        size_t length = 0;
        /**
         * @brief Current read offset. Starts with 0 and should end with length
         */
        size_t readOffset = 0;
        /**
         * @brief Current write offset. Starts with 0 and should end with length
         */
        size_t writeOffset = 0;
    public:
        /**
         * @brief Get direct access to the pointer
         * @return The pointer to the data
         */
        operator uint8_t*();
        /**
         * @brief Get direct access to the size of the data
         * @return The size of the data 
         */
        operator size_t();
        /**
         * @brief Construct a new Buffer object using a pointer and fixed size
         * 
         * @param data The pointer to data
         * @param size The fixed size of the data
         */
        Buffer(uint8_t* data,size_t size);
        /**
         * @brief Construct a new Buffer object using a fixed size
         * 
         * @param size The fixed size of the new data
         */
        Buffer(size_t size);
        /**
         * @brief Construct a new Buffer object using an istream object
         * 
         * @param input The istream object
         */
        Buffer(std::istream &input);
        /**
         * @brief Construct a new Buffer object using an ifstream object
         * 
         * @param stream The ifstram object
         */
        Buffer(std::ifstream &stream);
        /**
         * @brief Construct a new Buffer object using an fstream object
         * 
         * @param stream The fstream object
         */
        Buffer(std::fstream &stream);
        /**
         * @brief Construct a new Buffer object using a filepath
         * 
         * @param path The path to the file
         */
        Buffer(const char* path);
        /**
         * @brief Construct a new Buffer object using a filepath
         * 
         * @param path The path to the file
         */
        Buffer(std::string path);
        /**
         * @brief Construct a new Buffer object using a filepath
         * 
         * @param path The path to the file
         */
        Buffer(std::stringstream path);
        /**
         * @brief Returns the fixed size of the data
         * 
         * @return The size of the data 
         */
#ifdef Linux
        /**
         * @brief Construct a new Buffer object using a valid file descriptor. Linux only!
         * 
         * @param handle The file descriptor
         */
        Buffer(int handle);
#endif
#ifdef Windows
        /**
         * @brief Construct a new Buffer object using a valid file handle. Windows only!
         * 
         * @param handle 
         */
        Buffer(HANDLE handle);
#endif
        size_t size() const;
        /**
         * @brief Deletes the data to free memory. Returns true if success, false if data is already gone
         * 
         * @return Has the data been deleted?
         */
        bool clear() const;
        /**
         * @brief Check if the data is valid (not deleted)
         * 
         * @return Has the data been deleted?
         */
        bool valid() const;
        /**
         * @brief Returns the offset for reading
         * 
         * @return The current read offset
         */
        size_t tellg() const;
        /**
         * @brief Returns the offset for writing
         * 
         * @return The current write offset
         */
        size_t tellp() const;
        /**
         * @brief Sets the absolute read position of the data
         * 
         * @param offset New absolute read position
         * @return The read offset is valid
         */
        bool seekg(size_t offset);
        /**
         * @brief Sets the absolute write position of the data
         * 
         * @param offset New absolute write position
         * @return The write offset is valid
         */
        bool seekp(size_t offset);
        /**
         * @brief Read data to the given pointer with a fixed size
         * 
         * @param dst The pointer to put the read data
         * @param size The size of the read data
         * @return The new read position
         */
        size_t read(void* dst,size_t size);
        /**
         * @brief Write data from the given pointer with a fixed size
         * 
         * @param src The pointer with data to write
         * @param size The size of the write data
         * @return The new write position
         */
        size_t write(const void* src,size_t size);

        int8_t readInt8();uint8_t readUInt8();
        int16_t readInt16();uint16_t readUInt16();
        int32_t readInt32();uint32_t readUInt32();
        int64_t readInt64();uint64_t readUInt64();
        float readFloat();double readDouble();
        const char* readString(size_t size);
        const char* readString();

        void writeInt8(int8_t value);void writeUInt8(uint8_t value);
        void writeInt16(int16_t value);void writeUInt16(uint16_t value);
        void writeInt32(int32_t value);void writeUInt32(uint32_t value);
        void writeInt64(int64_t value);void writeUInt64(uint64_t value);
        void writeFloat(float value);void writeDouble(double value);
        void writeString(char* string);
        void writeString(std::string string);
        void writeString(std::stringstream string);
    };
}

#endif