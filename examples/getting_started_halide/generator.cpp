// g++ generator.cpp ../../3rd-party/Halide-14.0.0-x86-64-linux/share/Halide/tools/GenGen.cpp -o generator -std=c++17 -I../../ -I../../3rd-party/Halide-14.0.0-x86-64-linux/include -L../../3rd-party/Halide-14.0.0-x86-64-linux/lib -Xlinker -rpath ../../3rd-party/Halide-14.0.0-x86-64-linux/lib -lHalide -ldl -lpng -lz
// ./generator -g getting_started_halide auto_schedule=true -p ../../3rd-party/Halide-14.0.0-x86-64-linux/lib/libautoschedule_adams2019.so -s Adams2019  -o ./ target=host -e h,o,schedule

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

#define GLSLIKE_USE_HALIDE
#include "glslike.hpp"
#include "glslike_io.hpp"

using namespace glslike;


vec3 calc(vec2 position) {
    Halide::Expr distance = length(position);
    Halide::Expr distanceSqrd = distance * distance;
    return vec3(
        0.2f / distanceSqrd,
        0.1f / distanceSqrd,
        0.0f
    );
}

Halide::Expr to256(Halide::Expr value) {
    return Halide::cast<std::uint8_t>(clamp(value, 0.0f, 1.0f) * 255.0f);
}


class GettingStartedHalide : public Halide::Generator<GettingStartedHalide> {
public:
    Halide::GeneratorOutput<Halide::Buffer<std::uint8_t>> output{"output", 3};
    Halide::Var x{"x"}, y{"y"}, c{"c"};

    void generate() {
        // Unhandled exception: Error: Can't access output buffer of undefined Func.
        // see: https://github.com/halide/Halide/issues/6586
        output(c, x, y) = Halide::cast<std::uint8_t>(0);

        const auto width = output.dim(1).extent();
        const auto height = output.dim(2).extent();
        const auto half_width = width / 2.0f;
        const auto half_height = height / 2.0f;

        // create vector
        const auto vx = (x - half_width) / half_width;
        const auto vy = (y - half_height) / half_height;
        const vec2 position(vx, vy);

        // calc color
        const auto color = calc(position);

        // write color
        output(0, x, y) = to256(color.r);
        output(1, x, y) = to256(color.g);
        output(2, x, y) = to256(color.b);
        output(3, x, y) = Halide::cast<std::uint8_t>(0xff);
    }

    void schedule() {
        output.set_estimates({{0, 3}, {0, 1024}, {0, 1024}});
    }
};

HALIDE_REGISTER_GENERATOR(GettingStartedHalide, getting_started_halide)
