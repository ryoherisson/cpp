#include <iostream>
#include <memory>

class BasicArray {
    public:
        virtual ~BasicArray() {
            std::cout << "BasicArray::~BasicArray() is called." << std::endl;
        }

        virtual void Set(int index, int value) = 0;
        virtual int Get(int index) const = 0;
};

class DynamicArray : public BasicArray {
    public:
        DynamicArray(int size, int initial_value) {
            data_ = new int[size];
            for (auto i = 0; i < size; ++i) {
                data_[i] = initial_value;
            }
        }

        // 明示的に定義しない場合、 コンパイラが暗黙的にデストラクタを定義します.
        ~DynamicArray() override {
            std::cout << "DynamicArray::~DynamicArray() is called." << std::endl;
            delete[] data_;
        }

        void Set(int index, int value) override {
            data_[index] = value;
        }

        int Get(int index) const override {
            return data_[index];
        }

    private:
        int* data_;
};

// 明示的に定義しない場合、 コンパイラが暗黙的にデストラクタを定義します.
// DynamicArray::~DynamicArray() {
//     std::cout << "DynamicArray::~DynamicArray() is called." << std::endl;
//     delete[] data_;
// }

int main() {
    // destructor 派生クラス => 基底クラス
    DynamicArray d(5, 1);
    std::cout << d.Get(2) << std::endl;
    d.Set(2, 10);
    std::cout << d.Get(2) << std::endl;

    // アップキャスト
    std::unique_ptr<BasicArray> b(new DynamicArray(5, 1));
    std::cout << b->Get(2) << std::endl;
    b->Set(2, 10);
    std::cout << b->Get(2) << std::endl;

    return 0;
}