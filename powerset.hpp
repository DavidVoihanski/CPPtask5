#pragma once
namespace itertools{
    template<typename T>
    class powerset{
        private:
            T temp;
        public:
            powerset(){
                
            }
            powerset(const T& container){
                this->temp = temp;
            }
            auto begin() {
                return temp.begin();
            }
            auto end() {
                return temp.begin();
            }
    };
}
