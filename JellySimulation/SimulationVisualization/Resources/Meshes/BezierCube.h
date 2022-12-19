#pragma once

#include <vector>
#include <SimpleMath.h>

#include <d3d11.h>

using namespace DirectX::SimpleMath;

static const std::vector<D3D11_INPUT_ELEMENT_DESC> g_bezierCubePositionLayout
{
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }
};

static int GetBezierIndex(int x, int y, int z)
{
    return z * 16 + y * 4 + x;
}

static std::vector<unsigned short> GetBezierCubeIndices()
{
    std::vector<unsigned short> indices;

    for (int i = 0; i < 64; i++)
    {
        int x1 = i % 4;
        int y1 = (i / 4) % 4;
        int z1 = i / 16;

        for (int j = i; j < 64; j++)
        {
            int x2 = j % 4;
            int y2 = (j / 4) % 4;
            int z2 = j / 16;

            auto xDiff = abs(x2 - x1), yDiff = abs(y2 - y1), zDiff = abs(z2 - z1);

            if (xDiff + yDiff + zDiff == 1)
            {
                indices.push_back(i);
                indices.push_back(j);
            }
        }
    }

    return indices;
}

static std::vector<unsigned short> g_bezierCubeSidesIndices =
{
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60,
    3, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63,
    0, 1, 2, 3, 16, 17, 18, 19, 32, 33, 34, 35, 48, 49, 50, 51,
    12, 13, 14, 15, 28, 29, 30, 31, 44, 45, 46, 47, 60, 61, 62, 53
};
