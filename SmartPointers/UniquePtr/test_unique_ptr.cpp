#include <gtest/gtest.h>
#include "my_unique_ptr.hpp"
#include "my_unique_ptr_exceptions.hpp"

int* make_int(int value)
{
    return new int(value);
}

TEST(MyUniquePtrTest, ConstructionAndDereference)
{
    MyUniquePtr ptr(make_int(42));

    EXPECT_EQ(*ptr, 42);
}

TEST(MyUniquePtrTest, ArrowOperator)
{
    struct test_struct
    {
        int x = 99;
        int get_x() const { return x; }
    };

    MyUniquePtr ptr(new int(7));
    EXPECT_EQ(*ptr, 7);
}

TEST(MyUniquePtrTest, MoveConstructor)
{
    MyUniquePtr original(new int(50));
    MyUniquePtr moved(std::move(original));

    EXPECT_EQ(*moved, 50);
    EXPECT_FALSE(original);
}

TEST(MyUniquePtrTest, MoveAssignment)
{
    MyUniquePtr ptr1(new int(20));
    MyUniquePtr ptr2;
    ptr2 = std::move(ptr1);

    EXPECT_EQ(*ptr2, 20);
    EXPECT_FALSE(ptr1);
}

TEST(MyUniquePtrTest, ResetReplacesValue)
{
    MyUniquePtr ptr1(new int(15));
    ptr1.reset(make_int(20));
    EXPECT_EQ(*ptr1, 20);
}

TEST(MyUniquePtrTest, ResetWithSamePointerNoDelete)
{
    int* raw_ptr = make_int(25);
    MyUniquePtr ptr(raw_ptr);
    ptr.reset(raw_ptr);
    EXPECT_EQ(*ptr, 25);
}

TEST(MyUniquePtrTest, ReleaseReturnsNullPointer)
{
    MyUniquePtr ptr(make_int(23));
    int* raw_ptr = ptr.release();
    EXPECT_EQ(*raw_ptr, 23);
    EXPECT_FALSE(ptr);
    delete raw_ptr;
}

TEST(MyUniquePtrTest, DereferenceNullThrows)
{
    MyUniquePtr ptr;
    EXPECT_THROW(*ptr, UniquePtrException);
}

TEST(MyUniquePtrTest, ArrowNullThrows)
{
    MyUniquePtr ptr;
    EXPECT_THROW(ptr.operator->(), UniquePtrException);
}

TEST(MyUniquePtrTest, ReleaseNullThrows)
{
    MyUniquePtr ptr;
    EXPECT_THROW(ptr.release(), UniquePtrException);
}