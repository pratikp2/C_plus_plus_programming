# SOLID Design Principles

<p align="center">
  <img src="images/SOLID_design_principle.jpg" alt="Sample Image" width="600" height="500">
</p>

[YouTube Reference : Solid design Principles](https://www.youtube.com/watch?v=XI7zep97c-Y)
***

***1. S : Single Responsibility Principles***

- ***“A class should have one, and only one, reason to change".*** Following this principle means that each class only does one thing and every class or module only has responsibility for one part of the software’s functionality. More simply, each class should solve only one problem.
- It can be applied to classes, software components, and microservices.Utilizing this principle makes code easier to test and maintain, it makes software easier to implement, and it helps to avoid unanticipated side-effects of future changes.
```
// Violation of SRP
class User {
    std::string username;
    std::string password;
public:
    void setUsername(const std::string& uname) { username = uname; }
    void setPassword(const std::string& pwd) { password = pwd; }
    bool changeMode(const std::string& Mode) {}
};

// Following SRP
class User {
    std::string username;
    std::string password;
public:
    void setUsername(const std::string& uname) { username = uname; }
    void setPassword(const std::string& pwd) { password = pwd; }
};
```
***

***2. O : Open-Closed Principle***

- ***“Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification”***
- At first glance, these two criteria seem to be inherently contradictory. The way to comply with these principles and to make sure that your class is easily extendable without having to modify the code is through the use of abstractions.
- Using inheritance or interfaces that allow polymorphic substitutions is a common way to comply with this principle. Regardless of the method used, it’s important to follow this principle in order to write code that is maintainable and revisable.

shape.cpp

```
//Violation of OCP
class Shape {
public:
    void drawCircle();
    void drawSquare();
}
```
New shape.cpp

```
// Following OCP

class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {}
};

class Rectangle : public Shape {
public:
    void draw() const override {}
};
```
***

***3. L : Liskov Substitution Principle***

- ***“Derived or child classes must be substitutable for their base or parent classes“.*** The principle is named for Barbara Liskov, who introduced this concept of behavioral subtyping in 1987. 
-  This principle ensures that any class that is the child of a parent class should be usable in place of its parent without any unexpected behavior.
- This principle helps to avoid unexpected consequences of changes and avoids having to open a closed class in order to make changes.
- It leads to easy extensions of software, and, while it might slow down the development process, following this principle during development can avoid lots of issues during updates and extensions.
```
#include <iostream>

class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying" << std::endl;
    }
};

class Sparrow : public Bird {
public:
    void fly() override {
        std::cout << "Sparrow is flying" << std::endl;
    }
};

class Ostrich : public Bird {
public:
    void fly() override {
        // Ostriches cannot fly, so we should override with a specific behavior
        throw std::logic_error("Ostriches cannot fly");
    }
};

void letBirdFly(Bird& bird) { bird.fly();}

int main() {
    Sparrow sparrow;
    Ostrich ostrich;
    letBirdFly(sparrow);  // Works fine
    // letBirdFly(ostrich);  // Throws exception, violates LSP
    return 0;
}

```
***

***4. I : Interface Segregation Principle***

- ***“Make fine grained interfaces that are client-specific, Do not force any client to implement an interface which is irrelevant to them“.*** The general idea of interface segregation principle is that it’s better to have a lot of smaller interfaces than a few bigger ones.
- For software engineers, this means that you don’t want to just start with an existing interface and add new methods. Instead, start by building a new interface and then let your class implement multiple interfaces as needed.
- Smaller interfaces mean that developers should have a preference for composition over inheritance and for decoupling over coupling.
- According to this principle, engineers should work to have many client-specific interfaces, avoiding the temptation of having one big, general-purpose interface
```
#include <iostream>

class IPrinter {
public:
    virtual void printDocument() = 0;
};

class IScanner {
public:
    virtual void scanDocument() = 0;
};

class IMachine : public IPrinter, public IScanner {};

class MultifunctionPrinter : public IMachine {
public:
    void printDocument() override {
        std::cout << "Printing document" << std::endl;
    }
    void scanDocument() override {
        std::cout << "Scanning document" << std::endl;
    }
};

class SimplePrinter : public IPrinter {
public:
    void printDocument() override {
        std::cout << "Printing document" << std::endl;
    }
};

int main() {
    SimplePrinter printer;
    printer.printDocument();
    // printer.scanDocument(); // Not possible, adheres to ISP
    return 0;
}

```
***

***5. D : Dependency Inversion Principle***

- ***High-level modules should not depend on low-level modules. Both should depend on abstractions***
- This principle offers a way to decouple software modules. Simply put, dependency inversion principle means that developers should “depend on abstractions, not on concretions.Further, ***“abstractions should not depend on details. Details should depend upon abstractions.”***
- One popular way to comply with this principle is through the use of a dependency inversion pattern, although this method is not the only way to do so. Whatever method you choose to utilize, finding a way to utilize this principle will make your code more flexible, agile, and reusable.
```
#include <iostream>
#include <memory>

class IKeyboard {
public:
    virtual void input() = 0;
};

class WiredKeyboard : public IKeyboard {
public:
    void input() override {
        std::cout << "Wired keyboard input" << std::endl;
    }
};

class BluetoothKeyboard : public IKeyboard {
public:
    void input() override {
        std::cout << "Bluetooth keyboard input" << std::endl;
    }
};

class Computer {
    std::shared_ptr<IKeyboard> keyboard;
public:
    Computer(std::shared_ptr<IKeyboard> kbd) : keyboard(kbd) {}
    void receiveInput() {
        keyboard->input();
    }
};

int main() {
    std::shared_ptr<IKeyboard> wiredKeyboard = std::make_shared<WiredKeyboard>();
    Computer computer(wiredKeyboard);
    computer.receiveInput();

    std::shared_ptr<IKeyboard> bluetoothKeyboard = std::make_shared<BluetoothKeyboard>();
    Computer anotherComputer(bluetoothKeyboard);
    anotherComputer.receiveInput();

    return 0;
}

```
***