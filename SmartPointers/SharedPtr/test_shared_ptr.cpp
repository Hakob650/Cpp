#include <gtest/gtest.h>
#include "my_shared_ptr.hpp"
#include "my_shared_ptr_exceptions.hpp"

TEST(SharedPtrTest, ConstructorAndDereference) {
    SharedPtr sp(new int(10));
    EXPECT_EQ(*sp, 10);
}

TEST(SharedPtrTest, CopyConstructorIncrementsRefCount) {
    SharedPtr sp1(new int(20));
    SharedPtr sp2(sp1);
    EXPECT_EQ(sp1.use_count(), 2);
    EXPECT_EQ(sp2.use_count(), 2);
    EXPECT_EQ(*sp1, 20);
    EXPECT_EQ(*sp2, 20);
}

TEST(SharedPtrTest, CopyAssignmentTransfersOwnership) {
    SharedPtr sp1(new int(30));
    SharedPtr sp2;
    sp2 = sp1;
    EXPECT_EQ(sp1.use_count(), 2);
    EXPECT_EQ(sp2.use_count(), 2);
    EXPECT_EQ(*sp1, 30);
    EXPECT_EQ(*sp2, 30);
}

TEST(SharedPtrTest, DestructorDecrementsRefCount) {
    int* rawPtr = new int(40);

    {
        SharedPtr sp1(rawPtr);
        EXPECT_EQ(sp1.use_count(), 1);

        {
            SharedPtr sp2(sp1);
            EXPECT_EQ(sp1.use_count(), 2);
            EXPECT_EQ(sp2.use_count(), 2);
        }
        // sp2 destroyed here, ref count should be 1 now
        EXPECT_EQ(sp1.use_count(), 1);
    }
    // sp1 destroyed here, rawPtr deleted, cannot check use_count now
}

TEST(SharedPtrTest, DereferenceNullThrows) {
    SharedPtr sp;
    EXPECT_THROW(*sp, SharedPtrException);
}

TEST(SharedPtrTest, ArrowOperatorNullThrows) {
    SharedPtr sp;
    EXPECT_THROW(sp.operator->(), SharedPtrException);
}

TEST(SharedPtrTest, BoolOperatorWorks) {
    SharedPtr sp1(new int(50));
    SharedPtr sp2;
    EXPECT_TRUE(sp1);
    EXPECT_FALSE(sp2);
}

TEST(SharedPtrTest, GetReturnsCorrectPointer) {
    int* rawPtr = new int(60);
    SharedPtr sp(rawPtr);
    EXPECT_EQ(sp.get(), rawPtr);
}
