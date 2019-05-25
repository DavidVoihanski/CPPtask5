#pragma once
namespace itertools{
    template<typename T>
    class powerset{
        private:
            T set;
        public:
            powerset(){

            }
            powerset(const T& container){
                this->set = container;
            }
            auto begin() const{
                return set.begin();
            }
            auto end() const{
                return set.begin();
            }
    };
}
