#pragma once
#include<exception>
namespace itertools{
    template<typename T>
    class range{
        private:
            T first;
            T last;
            range(const range& other);
        public:
            range(){

            }
            range(const T& start, const T& end){
                //throw std::invalid_argument("bad");
                this->first = start;
                this->last = end;
            }
            class const_iterator{
            public:
            T current;
            const_iterator(){

            }
            const_iterator(const const_iterator& other){
                this->current = other.current;
            }
            const_iterator(const T& arg){
                this->current = arg;
            }
            const T& operator *(){
                return current;
            }
        
            const_iterator& operator++() {
                this->current++;
                return *this;
            }
            const_iterator& operator++(int){
                const_iterator temp = *this;
                this->current++;
                return temp;
            }
            bool operator !=(const const_iterator& other) const{
                return !(this->current == other.current);
            }
            bool operator == (const const_iterator& other) const{
                return (this->current == other.current);
            }
            
        };//iterator

            const_iterator begin() const{
                return const_iterator{this->first};
            }
            const_iterator end() const{
                return const_iterator{this->last};
            }
    };


}

