// https://www.geeksforgeeks.org/system-design/software-design-patterns/
// https://www.geeksforgeeks.org/system-design/command-pattern-c-design-patterns/

#include <iostream>
#include <vector>

// Receiver: Electronic Device
class ElectronicDevice {
    private:
        std::string name;

    public:
        ElectronicDevice(const std::string& n) : name(n) {
            // do nothing
        }

        void turnOn() {
            std::cout << name << " is On now" << std::endl;
        }

        void turnOff() {
            std::cout << name << "is Off now" << std::endl;
        }
};

// Command interface
class Command {
    public:
        virtual void execute() = 0;
};

// Concrete Command: Turn on
class TurnOnCommand : public Command {
    private:
        ElectronicDevice& device;

    public:
        TurnOnCommand(ElectronicDevice& dev) : device(dev) {
            // do nothing
        }

        void execute() {
            device.turnOn();
        }
};

// Concrete Command: Turn off
class TurnOffCommand : public Command {
    private:
        ElectronicDevice& device;

    public:
        TurnOffCommand(ElectronicDevice& dev) : device(dev) {
            // do nothing
        }

        void execute() {
            device.turnOff();
        }
};

// Invoker: Remote Control
class RemoteControl {
    private:
        std::vector<Command*> commands;

    public:
        void addCommand(Command* cmd) {
            commands.push_back(cmd);
        }

        void pressButton(int slot) {
            if (slot >= 0 && slot < commands.size()) {
                commands[slot]->execute();
            }
        }
};

int main() {
    // Create electronic devices
    ElectronicDevice tv("TV");
    ElectronicDevice lights("Lights");

    // Create commands for turning devices on and off
    TurnOnCommand turnOnTV(tv);
    TurnOffCommand turnOffTV(tv);
    TurnOnCommand turnOnLights(lights);
    TurnOffCommand turnOffLights(lights);

    // Create a remote control
    RemoteControl remote;

    // Set commands for remote buttons
    remote.addCommand(&turnOnTV);
    remote.addCommand(&turnOffTV);
    remote.addCommand(&turnOnLights);
    remote.addCommand(&turnOffLights);

    // Press buttons on the remote
    remote.pressButton(0);
    remote.pressButton(1);
    remote.pressButton(2);
    remote.pressButton(3);

    return 0;
}