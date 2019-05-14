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
        
        class iterator{
            public:
            T current;
            // iterator(){

            // }
            iterator(const iterator& other){
                this->current = other.current;
            }
            iterator(const T& arg){
                this->current = arg;
            }
            T& operator *(){
                return current;
            }
        
            iterator& operator++() {
                this->current++;
                return *this;
            }
            iterator& operator++(int){
                iterator temp = *this;
                this->current++;
                return temp;
            }
            T& operator-(int num) const{
                return (current - num);
            }
            bool operator !=(const iterator& other) const{
                return !(this->current == other.current);
            }
            
            // template<typename other>
            // bool operator!=(other other_){
            //     return !(this->current == *other_);
            // }
            bool operator == (const iterator& other) const{
                return (this->current == other.current);
            }
            
        };//iterator
            class const_iterator{
            public:
            T current;
            // iterator(){

            // }
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
                iterator temp = *this;
                this->current++;
                return temp;
            }
            T& operator-(int num) const{
                return (current - num);
            }
            bool operator !=(const const_iterator& other) const{
                return !(this->current == other.current);
            }
            
            template<typename other>
            bool operator!=(other other_){
                return !(this->current == *other_);
            }
            bool operator == (const const_iterator& other) const{
                return (this->current == other.current);
            }
            
        };//iterator

            iterator begin() {
                return iterator{this->first};
            }
            iterator end() {
                return iterator{this->last};
            }
            const_iterator begin() const{
                return const_iterator{this->first};
            }
            const_iterator end() const{
                return const_iterator{this->last};
            }
    };


}

