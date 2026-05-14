#include "AI/FlowField.h"
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>

FlowField::FlowField() : m_width(0), m_height(0) {}

void FlowField::Compute(int targetX, int targetY, const TerrainGrid& terrain) {
    m_width = terrain.GetWidth();
    m_height = terrain.GetHeight();
    m_dirGrid.resize(m_width * m_height);
    std::memset(m_dirGrid.data(), 0, m_dirGrid.size());

    struct Cell { int x, y; };
    std::queue<Cell> frontier;
    std::vector<float> dist(m_width * m_height, 1e18f);

    int targetIdx = targetY * m_width + targetX;
    dist[targetIdx] = 0.0f;
    frontier.push({ targetX, targetY });

    const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

    while (!frontier.empty()) {
        auto curr = frontier.front();
        frontier.pop();
        int currIdx = curr.y * m_width + curr.x;
        float curDist = dist[currIdx];

        for (int i = 0; i < 8; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            if (nx < 0 || nx >= m_width || ny < 0 || ny >= m_height) continue;
            if (!terrain.IsWalkable(nx, ny)) continue;

            float nd = curDist + ((i < 4) ? 1.0f : 1.414f);
            int nIdx = ny * m_width + nx;
            if (nd < dist[nIdx]) {
                dist[nIdx] = nd;
                m_dirGrid[nIdx] = static_cast<uint8_t>(i);
                frontier.push({ nx, ny });
            }
        }
    }
}

DirectX::XMFLOAT2 FlowField::GetDirection(int cellX, int cellY) const {
    if (cellX < 0 || cellX >= m_width || cellY < 0 || cellY >= m_height)
        return { 0.0f, 0.0f };

    static const float d[8][2] = {
        { -1, -1 }, { 0, -1 }, { 1, -1 },
        { -1,  0 },            { 1,  0 },
        { -1,  1 }, { 0,  1 }, { 1,  1 }
    };

    int idx = cellY * m_width + cellX;
    uint8_t dir = m_dirGrid[idx];
    if (dir >= 8) return { 0.0f, 0.0f };
    float len = std::sqrt(d[dir][0] * d[dir][0] + d[dir][1] * d[dir][1]);
    return { d[dir][0] / len, d[dir][1] / len };
}
