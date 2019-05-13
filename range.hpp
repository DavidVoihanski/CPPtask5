#pragma once
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
                this->first = start;
                this->last = end;
            }
        
        class iterator{
            public:
            T current;
            // iterator(){

            // }
            iterator(const iterator& other){
                this->current = other->current;
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
            bool operator !=(const iterator& other) const{
                return (this->current != other.current);
            }

            bool operator == (const iterator& other) const{
                return (this->current == other.current);
            }
        };//iterator

            iterator begin() {
                return iterator{this->first};
            }
            iterator end() {
                return iterator{this->last};
            }
    };


}

