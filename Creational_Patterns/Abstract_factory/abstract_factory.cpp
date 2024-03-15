#include<iostream>

using namespace std;


// Abstract Product A
class ProductA {
public:
    virtual ~ProductA() {}
    virtual void doSomething() = 0;
};

// Abstract Product B
class ProductB {
public:
    virtual ~ProductB() {}
    virtual void doSomethingElse() = 0;
};


// Concrete Product A1
class ConcreteProductA1 : public ProductA {
public:
    void doSomething() override {
        // Implementation of Concrete Product A1
        printf("Implementation of Concrete Product A1\n");
    }
};

// Concrete Product A2
class ConcreteProductA2 : public ProductA {
public:
    void doSomething() override {
        // Implementation of Concrete Product A2
        printf("Implementation of Concrete Product A2\n");
    }
};

// Concrete Product B1
class ConcreteProductB1 : public ProductB {
public:
    void doSomethingElse() override {
        // Implementation of Concrete Product B1
        printf("Implementation of Concrete Product B1\n");
    }
};

// Concrete Product B2
class ConcreteProductB2 : public ProductB {
public:
    void doSomethingElse() override {
        // Implementation of Concrete Product B2
        printf("Implementation of Concrete Product B2\n");
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual ProductA *createProductA() = 0;
    virtual ProductB *createProductB() = 0;
};


// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    ProductA *createProductA() override {
        return new ConcreteProductA1();
    }
    
    ProductB *createProductB() override {
        return new ConcreteProductB1();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    ProductA *createProductA() override {
        return new ConcreteProductA2();
    }
    
    ProductB *createProductB() override {
        return new ConcreteProductB2();
    }
};


// Client
class Client {
private:
    AbstractFactory *factory;
    
public:
    Client(AbstractFactory *f) : factory(f) {}
    
    void someOperation() {
        ProductA *productA = factory->createProductA();
        ProductB *productB = factory->createProductB();
        
        productA->doSomething();
        productB->doSomethingElse();
        
        delete productA;
        delete productB;
    }
    
    ~Client() {
        // Client is responsible for deleting the factory it was given.
        delete factory;
    }
};



int main()
{

    // Using ConcreteFactory1
    AbstractFactory *factory1 = new ConcreteFactory1();
    Client *client1 = new Client(factory1);
    client1->someOperation();

    delete client1; // Client destructor will delete factory1

    // Using ConcreteFactory2
    AbstractFactory *factory2 = new ConcreteFactory2();
    Client *client2 = new Client(factory2);
    client2->someOperation();

    delete client2; // Client destructor will delete factory2

    return 0;

}