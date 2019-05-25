#pragma once
#include <exception>
namespace itertools{
    
    template<typename firstIt, typename secondIt>
    class const_chain_iterator{
        public:
        firstIt firstIterator;
        firstIt firstEnd;
        secondIt secondIterator;
        bool inSecond;
        const_chain_iterator(){
            
        }
        const_chain_iterator(const const_chain_iterator& other){
            this->firstIterator = other.firstIterator;
            this->secondIterator = other.secondIterator;
            this->inSecond = other.inSecond;
        }
        const_chain_iterator(firstIt first,  secondIt second){
            this->firstIterator = first;
            this->secondIterator = second;
            this->inSecond = false;
            }
        const_chain_iterator(const firstIt& firstStart, const firstIt& firstEnd, const secondIt& second){
            this->firstIterator = firstStart;
            this->firstEnd = firstEnd;
            this->secondIterator = second;
            this->inSecond = false;
        }
        const auto& operator *(){
            if(!inSecond)
                return *firstIterator;
            else
                return *secondIterator;
        }
        const_chain_iterator& operator++() {
            if(!inSecond){
                ++this->firstIterator;
                if(this->firstIterator == this->firstEnd)
                    this->inSecond = true;
            }
            else{
                ++this->secondIterator;
            }
            return *this;
        }
        bool operator !=(const const_chain_iterator& other) const{
            return (this->firstIterator != other.firstIterator || this->secondIterator != other.secondIterator);
         }
    };  
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
            
            auto begin() const{
                return const_chain_iterator{(this->first.begin()),this->first.end(), (this->second.begin())};
            }
            auto end() const{
                return const_chain_iterator{this->first.end(), this->second.end()};
            }
    };
}