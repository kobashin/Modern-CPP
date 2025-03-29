#include <memory>
#include <iostream>

#if 0
struct Foo : std::enable_shared_from_this<Foo> {
    std::shared_ptr<Foo> getptr() {return shared_from_this();}
};
#else
struct Foo {
    std::shared_ptr<Foo> getptr() {
        return std::shared_ptr<Foo>(this);
    }
};
#endif

int main() {
    
#if 0    
    /*
        getptr() method of raw pointer -> throw exception

        terminate called after throwing an instance of 'std::bad_weak_ptr'
        what():  bad_weak_ptr
        Aborted (core dumped)
    */
    Foo* p1 = new Foo;  // raw pointer
    std::shared_ptr<Foo> p2 = p1->getptr();
#else
    std::shared_ptr<Foo> p1 = std::make_shared<Foo>();
    std::shared_ptr<Foo> p2 = p1->getptr();
#endif

    return 0;
}