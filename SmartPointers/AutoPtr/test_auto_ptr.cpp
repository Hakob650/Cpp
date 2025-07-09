#include <gtest/gtest.h>
#include "my_auto_ptr.hpp"
#include "my_auto_ptr_exceptions.hpp"

TEST(MyAutoPtrTest, ConstructorAndDereference) {
    my_auto_ptr ptr(new int(42));
    EXPECT_EQ(*ptr, 42);
}

TEST(MyAutoPtrTest, CopyConstructorTransfersOwnership) {
    my_auto_ptr a(new int(10));
    my_auto_ptr b(a);
    EXPECT_FALSE(a);  // a.ptr should be nullptr
    EXPECT_EQ(*b, 10);
}

TEST(MyAutoPtrTest, CopyAssignmentTransfersOwnership) {
    my_auto_ptr a(new int(5));
    my_auto_ptr b(new int(20));
    b = a;
    EXPECT_FALSE(a);
    EXPECT_EQ(*b, 5);
}

TEST(MyAutoPtrTest, ResetPointer) {
    my_auto_ptr ptr(new int(100));
    ptr.reset(new int(200));
    EXPECT_EQ(*ptr, 200);
}

TEST(MyAutoPtrTest, ReleasePointer) {
    my_auto_ptr ptr(new int(300));
    int* raw = ptr.release();
    EXPECT_EQ(*raw, 300);
    EXPECT_FALSE(ptr);  // ptr should now be null
    delete raw;
}

TEST(MyAutoPtrTest, DereferenceNullThrows) {
    my_auto_ptr ptr(nullptr);
    EXPECT_THROW(*ptr, auto_ptr_exception);
}

TEST(MyAutoPtrTest, ArrowOperatorNullThrows) {
    my_auto_ptr ptr(nullptr);
    EXPECT_THROW(ptr.operator->(), auto_ptr_exception);
}
