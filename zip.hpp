#pragma once
namespace itertools{
    template<typename firstT, typename secondT>
    class zip{
        private:
            firstT first;
            secondT second;
        public:
            zip(){

            }  
            zip(firstT first, secondT second){
                this->first = first;
                this->second = second;
            }
            auto begin() {
                return first.begin();
            }
            auto end(){
                return first.end();
            }
            auto begin() const{
                return first.begin();
            }
            auto end() const{
                return first.end();
            }
        };
}