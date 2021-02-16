#include <iostream>

class Brightness {
    public:
        explicit Brightness(int value) : value_(value) {}

        int Value() const {
            return value_;
        }

        static Brightness Maximum();
        static Brightness Minimum();
        static Brightness Median();

    private:
        int value_;
};

Brightness Brightness::Maximum() {
    return Brightness(100);
}

Brightness Brightness::Minimum() {
    return Brightness(0);
}

Brightness Brightness::Median() {
    return Brightness((Maximum().value_ + Minimum().value_) / 2);
}