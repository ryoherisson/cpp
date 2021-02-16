#include <string>

union X {
    int m1;
    double m2;
    std::string m3;
    X() : m1(0) {}
    ~X() {}
};
template <class T>
void destroy_at(T* location)
{
    location->~T();
}
int main()
{
    X x;
    new (&x.m3) std::string("aaa");
    destroy_at(&x.m3);
}