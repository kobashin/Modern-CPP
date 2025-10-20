// https://www.geeksforgeeks.org/system-design/visitor-method-design-patterns-in-c/

class Element {
    public:
        virtual void accept(Visitor& visitor) = 0;
};

class ElementA : public Element {
    public:
        void accept(Visitor& visitor) override {
            visitor.visit(*this);
        }
};

class ElementB : public Element {
    public:
        void accept(Visitor& visitor) override {
            visitor.visit(*this);
        }
};

class Visitor {
    public:
        virtual void visit(ElementA& element) = 0;
        virtual void visit(ElementB& element) = 0;
        // ... other visit methods for different elements
};

class ConcreteVisitor : public Visitor {
    public:
        void visit(ElementA& element) override {
            // perform operation on ElementA
        }

        void visit(ElementB& element) override {
            // perform operation on ElementB
        }
        // ... implementations for other visit methods
}