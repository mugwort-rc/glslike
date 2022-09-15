# Supported features

## 5 Operators and Expressions

|Precedence|Operator Class|Operators|vec2|vec3|vec4|
|----------|--------------|---------|----|----|----|
|1 (highest)|parenthetical grouping| `()` |✅|✅|✅|
|2|array subscript| `[]` |✅|✅|✅|
||function call and constructor structure | `()` |✅|✅|✅|
||field or method selector, swizzle | `.` |✅|✅|✅|
||post fix increment and decrement | `++` `--` ||||
|3|prefix increment and decrement | `++` `--` ||||
||unary| `+` `-` `~` `!` ||||
|4|multiplicative| `*` `/` `%` ||||
|5|additive| `+` `-` |✅|✅|✅|
|6|bit-wise shift| `<<` ||||
|7|relational| `<` `>` `<=` `>=` ||||
|8|equality| `==` `!=` |✅|✅|✅|
|9|bit-wise and| `&` |Left to Right|
|10|bit-wise exclusive or| `^` |Left to Right|
|11|bit-wise inclusive or| `|` |Left to Right|
|12|logical and| `&&` |Left to Right|
|13|logical exclusive or| `^^` |Left to Right|
|14|logical inclusive or| `||` |Left to Right|
|15|selection| `? :` |Right to Left|
|16|Assignment| `=` |Right to Left|
||arithmetic assignments| `+=` `-=` `*=` `/=` `%=` `<<=` `>>=` `&=` `^=` `|=` ||
|17|sequence| `,` |Left to Right|


### 5.5 Vector and Scalar Components and Length

## Built-in Functions

### 8.1 Angle and Trigonometry Functions

|Function|float|vec2|vec3|vec4|
|radians|✅|✅|✅|✅|
|degrees|✅|✅|✅|✅|
|sin|✅|✅|✅|✅|
|cos|✅|✅|✅|✅|
|tan|✅|✅|✅|✅|
|asin|✅|✅|✅|✅|
|acos|✅|✅|✅|✅|
|atan|✅|✅|✅|✅|
|sinh|✅|✅|✅|✅|
|cosh|✅|✅|✅|✅|
|tanh|✅|✅|✅|✅|
|asinh|✅|✅|✅|✅|
|acosh|✅|✅|✅|✅|
|atanh|✅|✅|✅|✅|

### 8.2 Exponential Functions

|Function|float|vec2|vec3|vec4|
|pow|✅|✅|✅|✅|
|exp|✅|✅|✅|✅|
|log|✅|✅|✅|✅|
|exp2|✅|✅|✅|✅|
|log2|✅|✅|✅|✅|
|sqrt|✅|✅|✅|✅|
|inversesqrt|✅|✅|✅|✅|

### 8.3 Common Functions

|Function|float|vec2|vec3|vec4|
|abs|✅|✅|✅|✅|
|sign|✅|✅|✅|✅|
|floor|✅|✅|✅|✅|
|trunc|✅|✅|✅|✅|
|round|✅|✅|✅|✅|
|roundEven|✅|✅|✅|✅|
|ceil|✅|✅|✅|✅|
|fract|✅|✅|✅|✅|
|mod|✅|✅|✅|✅|
|modf|✅|✅|✅|✅|
|min|✅|✅|✅|✅|
|max|✅|✅|✅|✅|
|clamp|✅|✅|✅|✅|
|step|✅|✅|✅|✅|
|smoothstep|✅|✅|✅|✅|
|isnan|✅|✅|✅|✅|
|isinf|✅|✅|✅|✅|
|floatBitToInt|||||
|floatBitToUint|||||
|intBitsToFloat|||||
|fma|||||
|frexp|||||
|ldexp|||||

### 8.4 Floating-Point Pack and Unpack Functions

|Function|float|vec2|vec3|vec4|
|packUnorm2x16|||||
|packSnorm2x16|||||
|packUnorm4x8|||||
|packSnorm4x8|||||
|unpackUnorm2x16|||||
|unpackSnorm2x16|||||
|unpackUnorm4x8|||||
|unpackSnorm4x8|||||
|packDouble2x32|||||
|unpackDouble2x32|||||
|packHalf2x16|||||
|unpackHalf2x16|||||

### 8.5 Geometric Functions

|Function|float|vec2|vec3|vec4|
|length||✅|✅|✅|
|distance||✅|✅|✅|
|dot||✅|✅|✅|
|cross|-|-|✅|-|
|normalize||✅|✅|✅|
|transform|||||
|faceforward|✅|✅|✅|✅|
|reflect|✅|✅|✅|✅|
|refract|✅|✅|✅|✅|

### 8.6 Matrix Functions

|Function|float|vec2|vec3|vec4|
|matrixCompMult|||||
|outerProduct|||||
|transpose|||||
|determinant|||||
|inverse|||||

### 8.7 Vector Relational Functions

|Function|float|vec2|vec3|vec4|
|lessThan|||||
|lessThanEqual|||||
|greaterThan|||||
|greaterThanEqual|||||
|equal|||||
|notEqual|||||
|any|||||
|all|||||
|not|||||

### 8.8 Integer Functions

|Function|float|vec2|vec3|vec4|
|uaddCarry|||||
|usubBorrow|||||
|umulExtended|||||
|imulExtended|||||
|bitfieldExtract|||||
|bitfieldInsert|||||
|bitfieldReverse|||||
|bitCount|||||
|findLSB|||||
|findMSB|||||
