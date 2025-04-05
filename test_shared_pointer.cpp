#include <memory>
#include <iostream>

#if 1
class Foo : public std::enable_shared_from_this<Foo>
#else
/* 
    This is not recommended
    because it is not a good practice to inherit from std::enable_shared_from_this directly.
*/
class Foo : std::enable_shared_from_this<Foo>
#endif
{
    public:
        void exec() {
            std::cout << "Foo().exec();" << std::endl;
        }

        std::shared_ptr<Foo> getptr() {
            // search existing shared_ptr and return it
            // throw exception if not existed
            return shared_from_this();
        }
};

int main() {
    std::shared_ptr<Foo> f0;
    {
        /*
            Foo object inside f1 is created using new Foo{}, 
            which is not managed by a std::shared_ptr at the time of its creation.
        */
        // std::shared_ptr<Foo> f1{new Foo{}};     // This is not recommended.
        std::shared_ptr<Foo> f1 = std::make_shared<Foo>();  // This is recommended.
        f1->exec();
        f0 = f1;        
    }

    f0->exec();

    std::shared_ptr<Foo> p1 = std::make_shared<Foo>();

    std::shared_ptr<Foo> p2 = p1->getptr();
    /*
        This ends throwing an error below.

        terminate called after throwing an instance of 'std::bad_weak_ptr'
        what():  bad_weak_ptr
        Aborted (core dumped)
    */
    
    // p2->exec();

    // do not need "delete"
    return 0;
}
