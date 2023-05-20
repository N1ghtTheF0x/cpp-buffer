#include <NTF/Buffer.hpp>

namespace NTF
{
    size_t Buffer::size() const
    {
        return length;
    }
    bool Buffer::clear() const
    {
        if(!valid()) return false;
        delete pointer;
        return true;
    }
    bool Buffer::valid() const
    {
        return pointer != nullptr;
    }
}