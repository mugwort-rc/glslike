// g++ main.cpp -std=c++17 -I../../ -lpng -lz

//
// Copyright 2022 mugwort_rc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "glslike.hpp"
#include "glslike_io.hpp"

using namespace glslike;


vec3 calc(vec2 position) {
    float distance = length(position);
    float distanceSqrd = distance * distance;
    return vec3(
        0.2f / distanceSqrd,
        0.1f / distanceSqrd,
        0.0f
    );
}

std::uint8_t to256(float value) {
    return static_cast<std::uint8_t>(std::clamp(value, 0.0f, 1.0f) * 255.0f);
}

int main() {
    constexpr int size = 1024;
    constexpr float half = size / 2.0f;
    std::vector<std::uint8_t> data(size * size * 4);
    constexpr int row_size = size * 4;
    for (int y = 0; y < size; ++y) {
        const int offset0 = y * row_size;
        for (int x = 0; x < size; ++x) {
            const int offset = offset0 + x * 4;
            // create position
            auto vx = (x - half) / half;
            auto vy = (y - half) / half;
            vec2 position(vx, vy);

            // calc color
            auto c = calc(position);

            // write color
            data[offset + 0] = to256(c.r);
            data[offset + 1] = to256(c.g);
            data[offset + 2] = to256(c.b);
            data[offset + 3] = 0xff;
        }
    }

    glslike::io::rgba2png("output.png", data, size, size, 4);

    return 0;
}
