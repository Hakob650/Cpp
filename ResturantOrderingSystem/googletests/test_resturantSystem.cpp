#include <gtest/gtest.h>
#include "../include/Dishes.hpp"
#include "../include/Appetizers.hpp"
#include "../include/Customers.hpp"
#include "../include/Menu.hpp"
#include "../include/Orders.hpp"
#include "../include/Resturant.hpp"

//Dish Tests
TEST(DishTest, DefaultConstructor)
{
    Dish d;
    EXPECT_EQ(d.getName(), "");
    EXPECT_DOUBLE_EQ(d.getPrice(), 0.0);
}

TEST(DishTest,ParameterizedConstructor)
{
    Dish d("Pizza", 12.99);
    EXPECT_EQ(d.getName(),"Pizza");
    EXPECT_DOUBLE_EQ(d.getPrice(), 12.99);
}

TEST(DishTest,CopyConstructor)
{
    Dish original("Burger", 8.5);
    Dish copy(original);
    EXPECT_EQ(copy.getName(), "Burger");
    EXPECT_DOUBLE_EQ(copy.getPrice(), 8.5);
}

TEST(DishTest, CopyAssignment)
{
    Dish d1("Sushi", 15.0);
    Dish d2;
    d2 = d1;
    EXPECT_EQ(d2.getName(), "Sushi");
    EXPECT_DOUBLE_EQ(d2.getPrice(), 15.0);
}

TEST(DishTest, MoveConstructor)
{
    Dish tmp("Taco", 6.75);
    Dish moved(std::move(tmp));
    EXPECT_EQ(moved.getName(), "Taco");
    EXPECT_DOUBLE_EQ(moved.getPrice(), 6.75);
    EXPECT_DOUBLE_EQ(tmp.getPrice(), 0.0);
}

TEST(DishTest, MoveAssignment)
{
    Dish d1("Pasta", 10.0);
    Dish d2;
    d2 = std::move(d1);
    EXPECT_EQ(d2.getName(), "Pasta");
    EXPECT_DOUBLE_EQ(d2.getPrice(), 10.0);
    EXPECT_DOUBLE_EQ(d1.getPrice(), 0.0);
}

TEST(DishTest, DisplayFunction)
{
    Dish d("Salad", 5.25);
    testing::internal::CaptureStdout();
    d.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Dish: Salad, Price: $5.25\n");
}

TEST(DishTest, GetName)
{
    Dish d("Cake", 4.5);
    EXPECT_EQ(d.getName(), "Cake");
}

TEST(DishTest, GetPrice)
{
    Dish d("Ice Cream", 3.25);
    EXPECT_DOUBLE_EQ(d.getPrice(), 3.25);
}

//Appetizer Tests
TEST(AppetizerTest, DisplayOutput) 
{
    Appetizer a("Spring Rolls", 4.99, true);
    testing::internal::CaptureStdout();
    a.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Dish: Spring Rolls, Price: $4.99\nSpicy Appetizer\n");
}

TEST(EntreeTest, DisplayOutput) 
{
    Entree e("Grilled Chicken", 12.5, 650);
    testing::internal::CaptureStdout();
    e.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Dish: Grilled Chicken, Price: $12.5\nCalories: 650\n");
}

TEST(DessertTest, DisplayOutput) 
{
    Dessert d("Chocolate Cake", 6.0, false);
    testing::internal::CaptureStdout();
    d.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Dish: Chocolate Cake, Price: $6\nNut-Free Dessert\n");
}

//Customer Tests
TEST(CustomerTest, ConstructorAndGetName) 
{
    Customer c("Alice", "alice@example.com");
    EXPECT_EQ(c.getName(), "Alice");
}

TEST(CustomerTest, CopyConstructor) 
{
    Customer c1("Bob", "bob@example.com");
    Customer c2(c1);
    EXPECT_EQ(c2.getName(), "Bob");
}

TEST(CustomerTest, MoveConstructor) 
{
    Customer c1("Charlie", "charlie@example.com");
    Customer c2(std::move(c1));
    EXPECT_EQ(c2.getName(), "Charlie");
}

TEST(CustomerTest, PlaceOrderAndHistory) 
{
    Customer c("Dana", "dana@example.com");
    Order o1;  // assume default constructor
    c.placeOrder(o1);

    testing::internal::CaptureStdout();
    c.viewOrderHistory();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

//Menu Tests
TEST(MenuTest, AddAndRetrieveDish) 
{
    Menu menu;
    menu.addDish(new Appetizer("Bruschetta", 5.0, false));
    
    Dish* dish = menu.getDishbyName("Bruschetta");
    ASSERT_NE(dish, nullptr);
    EXPECT_EQ(dish->getName(), "Bruschetta");
}

TEST(MenuTest, DisplayMenuOutput) 
{
    Menu menu;
    menu.addDish(new Entree("Steak", 20.0, 700));

    testing::internal::CaptureStdout();
    menu.displayMenu();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Steak"), std::string::npos);
}

//Orders Tests
Customer testCustomer("Test User", "test@example.com");

Appetizer* makeAppetizer() { return new Appetizer("Bruschetta", 5.0, false); }
Entree* makeEntree() { return new Entree("Pasta", 12.0, 600); }
Dessert* makeDessert() { return new Dessert("Tiramisu", 6.0, true); }

TEST(OrderTest, ConstructorAndDisplayEmptyOrder) 
{
    Order order(&testCustomer);

    testing::internal::CaptureStdout();
    order.displayOrder();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Customer: Test User"), std::string::npos);
    EXPECT_NE(output.find("Ordered Dishes:"), std::string::npos);
    EXPECT_NE(output.find("Total Price: $0"), std::string::npos);
}

TEST(OrderTest, AddDishAndCalculateTotal) 
{
    Order order(&testCustomer);
    order.addDish(makeAppetizer());
    order.addDish(makeEntree());
    order.calculateTotal();

    testing::internal::CaptureStdout();
    order.displayOrder();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Bruschetta"), std::string::npos);
    EXPECT_NE(output.find("Pasta"), std::string::npos);
    EXPECT_NE(output.find("Total Price: $17"), std::string::npos);
}

TEST(OrderTest, CopyConstructorCopiesDishes) 
{
    Order original(&testCustomer);
    original.addDish(makeDessert());
    original.calculateTotal();

    Order copy(original);

    testing::internal::CaptureStdout();
    copy.displayOrder();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Tiramisu"), std::string::npos);
    EXPECT_NE(output.find("Total Price: $6"), std::string::npos);
}

TEST(OrderTest, MoveConstructorTransfersDishes) 
{
    Order original(&testCustomer);
    original.addDish(makeEntree());
    original.calculateTotal();

    Order moved(std::move(original));

    testing::internal::CaptureStdout();
    moved.displayOrder();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Pasta"), std::string::npos);
    EXPECT_NE(output.find("Total Price: $12"), std::string::npos);
}

TEST(OrderTest, CopyAssignmentCopiesOrder) 
{
    Order order1(&testCustomer);
    order1.addDish(makeAppetizer());
    order1.calculateTotal();

    Order order2(&testCustomer);
    order2 = order1;

    testing::internal::CaptureStdout();
    order2.displayOrder();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Bruschetta"), std::string::npos);
    EXPECT_NE(output.find("Total Price: $5"), std::string::npos);
}

TEST(OrderTest, MoveAssignmentTransfersOrder) 
{
    Order order1(&testCustomer);
    order1.addDish(makeDessert());
    order1.calculateTotal();

    Order order2(&testCustomer);
    order2 = std::move(order1);

    testing::internal::CaptureStdout();
    order2.displayOrder();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Tiramisu"), std::string::npos);
    EXPECT_NE(output.find("Total Price: $6"), std::string::npos);
}

//Resturant Tests
TEST(RestaurantTest, GetCustomerByNameFound) 
{
   Resturant resturant;

    resturant.addCustomer(new Customer("Bob", "bob@example.com"));
    Customer* c = resturant.getCustomerByName("Bob");

    ASSERT_NE(c, nullptr);
    EXPECT_EQ(c->getName(), "Bob");
}

TEST(RestaurantTest, GetCustomerByNameNotFound) 
{
    Resturant resturant;

    Customer* c = resturant.getCustomerByName("Alice");
    EXPECT_EQ(c, nullptr);
}

TEST(RestaurantTest, ShowMenuOutputContainsDishes) 
{
    Resturant resturant;

    resturant.getMenu().addDish(new Appetizer("Salad", 5.25, false));
    resturant.getMenu().addDish(new Entree("Chicken", 8.0, 500));
    resturant.getMenu().addDish(new Dessert("Ice Cream", 5.0, false));

    testing::internal::CaptureStdout();
    resturant.showMenu();
    std::string output = testing::internal::GetCapturedStdout();

}

TEST(RestaurantTest, ViewCustomerOrderHistoryEmpty) 
{
    Resturant resturant;

    resturant.addCustomer(new Customer("Bob", "bob@example.com"));

    testing::internal::CaptureStdout();
    resturant.viewCustomerOrderHistory("Bob");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("Customer not found"), std::string::npos);
}

TEST(RestaurantTest, ManuallyCreateAndStoreOrder) 
{
    Resturant resturant;

    resturant.addCustomer(new Customer("Bob", "bob@example.com"));
    resturant.getMenu().addDish(new Entree("Chicken", 8.0, 500));
    resturant.getMenu().addDish(new Dessert("Ice Cream", 5.0, false));

    Customer* customer = resturant.getCustomerByName("Bob");
    ASSERT_NE(customer, nullptr);

    Order order(customer);
    order.addDish(resturant.getMenu().getDishbyName("Chicken"));
    order.addDish(resturant.getMenu().getDishbyName("Ice Cream"));
    order.calculateTotal();
    customer->placeOrder(order);

    testing::internal::CaptureStdout();
    resturant.viewCustomerOrderHistory("Bob");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Chicken"), std::string::npos);
    EXPECT_NE(output.find("Ice Cream"), std::string::npos);
    EXPECT_NE(output.find("Total Price: $13"), std::string::npos);
}




