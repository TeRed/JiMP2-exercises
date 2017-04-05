//
// Created by albert on 01.04.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H
#include <cstdint>
#include <algorithm>

namespace memorychunk{
    class MemoryChunk{
    private:
        int8_t *data;
        size_t data_size;
    public:
//        Constructors
        MemoryChunk(size_t sz);

//        Copy
        MemoryChunk(const MemoryChunk &memorychunk);
        MemoryChunk & operator=(const MemoryChunk &memorychunk);

//        Move
        MemoryChunk(MemoryChunk &&memorychunk);
        MemoryChunk & operator=(MemoryChunk &&memorychunk);

//        Destructor
        ~MemoryChunk();

//        Methods
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
    };

    void swap(int8_t *&a, int8_t *&b);
}
#endif //JIMP_EXERCISES_MEMORYCHUNK_H
