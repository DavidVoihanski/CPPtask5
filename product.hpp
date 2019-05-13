#pragma once
namespace itertools{
    template<typename firstT, typename secondT>
    class product{
        private:
            firstT first;
            secondT second;
        public:
            product(const firstT& first, const secondT& second){

            }
            auto begin() {
                return first.begin();
            }
            auto end() {
                return first.begin();
            }
    };
}