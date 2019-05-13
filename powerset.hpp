#pragma once
namespace itertools{
    template<typename T>
    class powerset{
        private:
            T temp;
        public:
            powerset(const T& container){

            }
            auto begin() {
                return temp.begin();
            }
            auto end() {
                return temp.begin();
            }
    };
}
