```mermaid
classDiagram
    Reminder <|-- MorningReminder
    Reminder <|-- NightReminder

    class Reminder{
        +begin_greet()
        +alert()
        +end_greet()
        +remind()
    }

    class MorningReminder{
        +begin_greet()
        +alert()
        +end_greet()
    }

    class NightReminder{
        +begin_greet()
        +alert()
        +end_greet()
    }
```