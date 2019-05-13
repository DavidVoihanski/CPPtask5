#pragma once
namespace itertools{

    template<typename firstT, typename secondT>
    class chain{
        private:
            chain(const chain& other);
        public:
            firstT first;
            secondT second;
            chain(){
                
            }
            chain(const firstT& first,const secondT& second){
                this->first = first;
                this->second = second;
            }   
            auto begin(){
                return first.begin();
            }
            auto end() {
                return first.begin();
            }
    };
}