#pragma once
#ifndef __POOLALLOCATOR_H__
#define __POOLALLOCATOR_H__

#include <cstddef>
#include <memory>
#include <vector>
#include <bitset>
#include <mutex>

template<typename T, size_t BlockSize = 4096>
class PoolAllocator {
    struct Block {
        alignas(T) std::byte storage[sizeof(T) * BlockSize];
        std::bitset<BlockSize> used;
        size_t firstFree() const {
            for (size_t i = 0; i < BlockSize; ++i) {
                if (!used[i]) return i;
            }
            return BlockSize;
        }
    };
    std::vector<std::unique_ptr<Block>> m_blocks;
    std::mutex m_mutex;

public:
    PoolAllocator() {
        m_blocks.push_back(std::make_unique<Block>());
    }

    T* Allocate() {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (auto& block : m_blocks) {
            size_t idx = block->firstFree();
            if (idx < BlockSize) {
                block->used.set(idx);
                return reinterpret_cast<T*>(&block->storage[idx * sizeof(T)]);
            }
        }
        auto block = std::make_unique<Block>();
        block->used.set(0);
        T* ptr = reinterpret_cast<T*>(&block->storage[0]);
        m_blocks.push_back(std::move(block));
        return ptr;
    }

    void Free(T* ptr) {
        if (!ptr) return;
        std::lock_guard<std::mutex> lock(m_mutex);
        for (auto& block : m_blocks) {
            std::byte* start = &block->storage[0];
            std::byte* end = start + sizeof(T) * BlockSize;
            std::byte* p = reinterpret_cast<std::byte*>(ptr);
            if (p >= start && p < end) {
                size_t idx = (p - start) / sizeof(T);
                block->used.reset(idx);
                return;
            }
        }
    }

    size_t BlockCount() const { return m_blocks.size(); }
};

using UnitPool = PoolAllocator<class Unit, 2048>;
using ProjectilePool = PoolAllocator<class Projectile, 8192>;
using EffectPool = PoolAllocator<class ParticleEffect, 16384>;

#endif
