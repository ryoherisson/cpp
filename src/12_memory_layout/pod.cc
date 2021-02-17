#include <type_traits>
struct FundamentalTypes {
    int16_t i;
    double d;
};
static_assert(std::is_pod<FundamentalTypes>::value, "Should be POD.");

int main() {

    return 0;
}