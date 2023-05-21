#include "../src/libgeometry/parser.c"
#include <ctest.h>
#include <ctype.h>
#include <libgeometry/parser.h>

CTEST(ctest, CHECK_PERIMETER)
{
    float rad = 8.4;
    const double Pi = 3.1415;
    double expected = 2 * Pi * rad;
    double reality = pcircle(rad);
    ASSERT_DBL_NEAR_TOL(expected, reality, 1e-1);
}

CTEST(ctest, CHECK_SQUARE)
{
    float rad = 8.4;
    const double Pi = 3.1415;
    double expected = Pi * rad * rad;
    double reality = acircle(rad);
    ASSERT_DBL_NEAR_TOL(expected, reality, 2e-1);
}