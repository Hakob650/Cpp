#include <gtest/gtest.h>
#include "../include/Base.hpp"
#include "../include/Derived.hpp"

TEST(VTableTest, BaseCall)
{
    Base base;
    
    testing::internal::CaptureStdout();
    
    base.call_virtual(0);
    
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Base::foo()"), std::string::npos);
}

TEST(VTableTest, DerivedCall)
{
    Derived derived;
    
    testing::internal::CaptureStdout();

    derived.call_virtual(0);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Derived::foo()"), std::string::npos);
}

TEST(VTableTest, BaseTypeInfo)
{
    Base b;
    
    testing::internal::CaptureStdout();
    
    b.print_type();
    
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Base"), std::string::npos);
}

TEST(VTableTest, DerivedTypeInfo) 
{
    Derived d;
    
    testing::internal::CaptureStdout();
    
    d.print_type();
    
    std::string output = testing::internal::GetCapturedStdout();
    
    std::cout << "Captured output: [" << output << "]" << std::endl;
    
    EXPECT_NE(output.find("Derived"), std::string::npos);
}
