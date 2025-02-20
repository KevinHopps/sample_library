#include <mylib/version.hpp>

#include <gtest/gtest.h>

namespace mylib {
    namespace tests {

        TEST(basic_tests, version_test) {
            EXPECT_EQ(version_major(), MYLIB_VERSION_MAJOR);
            EXPECT_EQ(version_minor(), MYLIB_VERSION_MINOR);
        }

    }
}
