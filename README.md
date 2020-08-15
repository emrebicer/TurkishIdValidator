# Turkish ID Validator
C++ implementation of Turkish ID validator. It can be used to validate a single Turkish ID or to validate a batch of Turkish Id's from a file.

## Usage
You can compile with g++ and run as follows

```terminal
g++ main.cpp -o app tid.cpp
./app
```
Output
```Terminal
Validating: 10000000146
        10000000146     -->     ✅VALID
Validating from: exampleids.txt
        10000000146     -->     ✅VALID
        50584170538     -->     ✅VALID
        78645934578     -->     ✅VALID
        58933519632     -->     ✅VALID
        98968137944     -->     ✅VALID
        12345678901     -->     ❌INVALID
```

## Algorithm
I have followed the pseudo code that [@ssg](https://github.com/ssg) has shared in C# implementation of the Validator.
The pseudo code can be found [here](https://github.com/ssg/TurkishId#algorithm).
