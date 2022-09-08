#!/usr/bin/env python3

#
# Copyright 2022 mugwort_rc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

from __future__ import annotations

import argparse
import itertools
import os
import sys


def main(argv: list[str]):
    parser = argparse.ArgumentParser()

    args = parser.parse_args(argv[1:])

    lowercase = [
        "xyzw",
        "rgba",
        "stpq",
    ]

    vectors = {
        2: "vec = vec2(1.0, 2.0)",
        3: "vec = vec3(1.0, 2.0, 3.0)",
        4: "vec = vec4(1.0, 2.0, 3.0, 4.0)",
    }

    for vector in range(2, 5):
        for swizzle in range(2, 5):
            for xrs in range(3):
                print(f"def test_vec{ vector }_swizzle{ swizzle }_{ lowercase[xrs][:swizzle] }():")
                print("    " + vectors[vector])
                for u, v, w in zip(
                    itertools.product(lowercase[0][:vector], repeat=swizzle),
                    itertools.product(lowercase[xrs][:vector], repeat=swizzle),
                    itertools.product("1234"[:vector], repeat=swizzle)):
                    print("    # " + "".join(v))
                    print(f"    v2 = vec." + "".join(v))
                    for i in range(swizzle):
                        print(f"    assert v2.{ lowercase[0][i] } == { w[i] }.0")
                print()



if __name__ == "__main__":
    sys.exit(main(sys.argv))
