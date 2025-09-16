#include <memory>
#include <iostream>

#if 0
struct Foo : std::enable_shared_from_this<Foo> {
    /**
     * @brief 自身の共有ポインタ(shared_ptr)を取得します。
     * @return このオブジェクトを管理する std::shared_ptr<Foo>
     * @note このメソッドは std::enable_shared_from_this を介して安全に共有ポインタを生成します。
     */
    std::shared_ptr<Foo> getptr() {return shared_from_this();}
};
#else
struct Foo {
    /**
     * @brief thisポインタから直接共有ポインタ(shared_ptr)を生成して返します。
     * @return thisから生成された std::shared_ptr<Foo>
     * @warning この方法は非常に危険です。
     *          オブジェクトがすでに他のshared_ptrによって管理されている場合、
     *          このメソッドを呼び出すと多重解放が発生し、未定義動作を引き起こします。
     *          std::enable_shared_from_this の使用が推奨されます。
     */
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