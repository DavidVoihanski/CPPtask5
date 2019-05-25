#pragma once
#include <thread>
#include <chrono>
namespace itertools{

    template<typename firstIt, typename secondIt>
    class const_product_iterator{
        public:
        firstIt firstIterator;
        secondIt secondIterator;
        secondIt secondIteratorSaver;
        secondIt secondIteratorEnd;
        const_product_iterator(){

        }
        const_product_iterator(const const_product_iterator& other){
            this->firstIterator = other.firstIterator;
            this->secondIterator = other.secondIterator;
            this->secondIteratorSaver = other.secondIteratorSaver;
            this->secondIteratorEnd = other.secondIteratorEnd;
        }
        const_product_iterator(const firstIt& firstStart, const secondIt& secondItEnd, const secondIt& second){
            this->firstIterator = firstStart;
            this->secondIterator = second;
            this->secondIteratorSaver = second;
            this->secondIteratorEnd = secondItEnd;
        }
        const_product_iterator(const firstIt& firstStart, const secondIt& second){
            this->firstIterator = firstStart;
            this->secondIterator = second;
            this->secondIteratorSaver = second;
        }
        const auto operator *(){
            resultSet toReturn{*firstIterator, *secondIterator};
            return toReturn;
        }
        const_product_iterator& operator++() {
            ++this->secondIterator;
            if(this->secondIterator == this->secondIteratorEnd){
                this->secondIterator = this->secondIteratorSaver;
                ++this->firstIterator;
            }
            return *this;
        }
        bool operator !=(const const_product_iterator& other) const{
            return (this->firstIterator != other.firstIterator && this->secondIterator != other.secondIterator);
         }
    }; 
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
            auto begin() const{
                return const_product_iterator{this->first.begin(),this->second.end(), this->second.begin()};
            }
            auto end() const{
                return const_product_iterator{this->first.end(), this->second.end()};
            }
    };
}