# Class Diagram of Abstract Factory Pattern

```mermaid

classDiagram
    %% Abstract Interface
    class CarFactory {
        <<abstract>>
        +createCar() Car
        +createSpecification() CarSpecification
    }
    
    %% Concrete Factory 1
    class NorthAmericaCarFactory {
        +createCar() Car
        +createSpecification() CarSpecification
    }
    
    %% Concrete Factory 2
    class EuropeCarFactory {
        +createCar() Car
        +createSpecification() CarSpecification
    }
    
    %% Abstract Products
    class Car {
        <<abstract>>
    }
    
    class CarSpecification {
        <<abstract>>
    }
    
    %% Concrete Products 1 (North America)
    class Sedan {
    }
    
    class NorthAmericaSpec {
    }
    
    %% Concrete Products 2 (Europe)
    class Hatchback {
    }
    
    class EuropeSpec {
    }
    
    %% Client
    class CarFactoryClient {
        +main(String[] args)
    }
    
    %% Inheritance relationships
    CarFactory <|-- NorthAmericaCarFactory : implements
    CarFactory <|-- EuropeCarFactory : implements
    
    Car <|-- Sedan : implements
    Car <|-- Hatchback : implements
    
    CarSpecification <|-- NorthAmericaSpec : implements
    CarSpecification <|-- EuropeSpec : implements
    
    %% Association relationships
    CarFactoryClient --> CarFactory : uses
    CarFactoryClient --> Car : creates
    CarFactoryClient --> CarSpecification : creates
    
    NorthAmericaCarFactory --> Sedan : creates
    NorthAmericaCarFactory --> NorthAmericaSpec : creates
    
    EuropeCarFactory --> Hatchback : creates
    EuropeCarFactory --> EuropeSpec : creates
    
```

## Pattern Structure

### Components:

1. **Abstract Interface**: `CarFactory`
   - Declares methods for creating abstract products

2. **Concrete Factory 1**: `NorthAmericaCarFactory`
   - Implements creation methods for North America specific products

3. **Concrete Factory 2**: `EuropeCarFactory`
   - Implements creation methods for Europe specific products

4. **Abstract Products**: `Car`, `CarSpecification`
   - Define interfaces for product objects

5. **Concrete Products 1**: `Sedan`, `NorthAmericaSpec`
   - Products for North America market

6. **Concrete Products 2**: `Hatchback`, `EuropeSpec`
   - Products for Europe market

7. **Client**: `CarFactoryClient`
   - Uses only interfaces declared by Abstract Factory and Abstract Product classes

### Key Benefits:
- **Consistency**: Ensures related products are used together
- **Isolation**: Separates product creation from usage
- **Flexibility**: Easy to add new product families
- **Type Safety**: Compile-time checking of product compatibility