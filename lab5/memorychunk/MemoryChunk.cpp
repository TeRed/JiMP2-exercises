//
// Created by albert on 01.04.17.
//

#include "MemoryChunk.h"

namespace memorychunk{
    MemoryChunk::MemoryChunk(size_t sz) {
        data = new int8_t[sz];
        data_size = sz;
    }

    MemoryChunk::MemoryChunk(const MemoryChunk &memorychunk) {
        data = new int8_t[memorychunk.data_size];
        data_size = memorychunk.data_size;

        for(int i = 0; i < data_size; i++) {
            data[i] = memorychunk.data[i];
        }
    }

    MemoryChunk & MemoryChunk::operator=(const MemoryChunk &memorychunk) {
        if(&memorychunk == this) return *this;

        data = new int8_t[memorychunk.data_size];
        data_size = memorychunk.data_size;

        for(int i = 0; i < data_size; i++) {
            data[i] = memorychunk.data[i];
        }
        return *this;
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&memorychunk) {
        data = nullptr;
        swap(data, memorychunk.data);
        data_size = memorychunk.data_size;
        memorychunk.data_size = 0;
    }

    MemoryChunk & MemoryChunk::operator=(MemoryChunk &&memorychunk) {
        if(&memorychunk == this) return *this;
        data = nullptr;
        swap(data, memorychunk.data);
        data_size = memorychunk.data_size;
        memorychunk.data_size = 0;

        return *this;
    }

    MemoryChunk::~MemoryChunk() {
        delete data;
    }

    int8_t * MemoryChunk::MemoryAt(size_t offset) const {
        return data + offset;
    }

    size_t MemoryChunk::ChunkSize() const {
        return data_size;
    }

    void swap(int8_t *&a, int8_t *&b){
        int8_t *tmp = a;
        a = b;
        b = tmp;
    }
}