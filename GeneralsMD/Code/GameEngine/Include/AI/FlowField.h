#pragma once
#ifndef __FLOWFIELD_H__
#define __FLOWFIELD_H__

#include <cstdint>
#include <vector>
#include <DirectXMath.h>

class TerrainGrid {
    int m_width, m_height;
public:
    TerrainGrid(int w, int h) : m_width(w), m_height(h) {}
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    bool IsWalkable(int x, int y) const { return true; }
};

class FlowField {
    std::vector<uint8_t> m_dirGrid;
    int m_width, m_height;
public:
    FlowField();
    void Compute(int targetX, int targetY, const TerrainGrid& terrain);
    DirectX::XMFLOAT2 GetDirection(int cellX, int cellY) const;
};

#endif
