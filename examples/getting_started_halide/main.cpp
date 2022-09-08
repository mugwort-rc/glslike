// g++ main.cpp getting_started_halide.o -std=c++17 -O3 -Wall -fPIC -fopenmp -I../../ -I../../3rd-party/Halide-14.0.0-x86-64-linux/include -L../../3rd-party/Halide-14.0.0-x86-64-linux/lib -Xlinker -rpath ../../3rd-party/Halide-14.0.0-x86-64-linux/lib -lHalide -ldl -lpng -lz

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

#include <Halide.h>
#include "getting_started_halide.h"
#include "glslike_io.hpp"

int main() {
    constexpr int size = 1024;
    std::vector<std::uint8_t> data(size * size * 4);
    Halide::Runtime::Buffer output(data.data(), 4, size, size);

    getting_started_halide(output);

    glslike::io::rgba2png("output.png", data, size, size, 4);

    return 0;
}
