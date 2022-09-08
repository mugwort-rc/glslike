#pragma once

//
// glslike_io.hpp
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

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "png.h"

namespace glslike {
namespace io {

bool rgba2png(const std::string &filename, const std::vector<std::uint8_t> image, const int width, const int height, const int channel) {
    assert(channel == 4);
    const int row_size = width * channel;

    std::unique_ptr<FILE, decltype(&fclose)> fp(fopen(filename.c_str(), "wb"), fclose);
    if ( ! fp ) {
        std::cerr << "cannot open " << filename << std::endl;
        return false;
    }
    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if ( ! png_ptr ) {
        return false;
    }
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if ( ! info_ptr ) {
        png_destroy_write_struct(&png_ptr, nullptr);
        return false;
    }
    if ( setjmp(png_jmpbuf(png_ptr)) ) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        return false;
    }
    png_init_io(png_ptr, fp.get());
    png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    // alloc & copy
    png_bytepp data_ptr = static_cast<png_bytepp>(png_malloc(png_ptr, sizeof(png_bytep) * height));
    if ( ! data_ptr ) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        return false;
    }
    for (int y = 0; y < height; ++y) {
        data_ptr[y] = static_cast<png_bytep>(png_malloc(png_ptr, width * channel));
        if ( ! data_ptr[y] ) {
            for (int i = 0; i < y; ++i) {
                png_free(png_ptr, data_ptr[i]);
            }
            png_free(png_ptr, data_ptr);
            png_destroy_write_struct(&png_ptr, &info_ptr);
            return false;
        }
        const int offset0 = y * row_size;
        for (int x = 0; x < width; ++x) {
            const int offset = offset0 + x * channel;
            data_ptr[y][x * channel + 0] = image[offset + 0];
            data_ptr[y][x * channel + 1] = image[offset + 1];
            data_ptr[y][x * channel + 2] = image[offset + 2];
            data_ptr[y][x * channel + 3] = image[offset + 3];
        }
    }
    // write
    png_set_rows(png_ptr, info_ptr, data_ptr);
    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, nullptr);
    // free
    for (int y = 0; y < height; ++y) {
        png_free(png_ptr, data_ptr[y]);
    }
    png_free(png_ptr, data_ptr);

    png_destroy_write_struct(&png_ptr, &info_ptr);

    return true;
}

}  // namespace io
}  // namespace glslike
