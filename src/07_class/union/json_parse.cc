#include <map>
#include <string>
#include <vector>
#include <iostream>

template <class T>
void destroy_at(T* location)
{
    location->~T();
}
struct value {
    enum class kind {
        null,
        object,
        array,
        string,
        number,
        boolean
    };
    kind k_;
    union data {
        bool b_;
        double num_;
        std::string str_;
        std::vector<value> arr_;
        std::map<std::string, value> obj_;
        data() : b_{} {}
        ~data() {}
    } data_;
    value()  : k_() {}
    value(std::string s) : k_(kind::string)
    {
        new(&data_.str_) std::string(std::move(s));
    }
    ~value()
    {
        switch(k_) {
        case kind::object:
            destroy_at(&data_.obj_); break;
        case kind::array:
            destroy_at(&data_.arr_); break;
        case kind::string:
            destroy_at(&data_.str_); break;
        default:
            break;
        }
    }
    kind get_kind() { return k_; }
    std::string get_string_or(std::string default_value)
    {
        return (k_ == kind::string) ? data_.str_ : default_value;
    }
};
int main()
{
    value v1;
    std::cout << static_cast<int>(v1.get_kind()) << v1.get_string_or("bbb") << std::endl;
    value v2("aaa");
    std::cout << static_cast<int>(v2.get_kind()) << v2.get_string_or("bbb") << std::endl;
}