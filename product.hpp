#pragma once
namespace itertools{
    template<typename firstT, typename secondT>
    class product{
        private:
            firstT first;
            secondT second;
        public:
            product(){
                
            }
            product(const firstT& first, const secondT& second){
                this->first = first;
                this->second = second;
            }
            auto begin() {
                return first.begin();
            }
            auto end() {
                return first.begin();
            }
    };
}