#pragma once
namespace itertools{
    template<typename It>
    class const_powerset_iterator{
        It iterator;
        public:
        const_powerset_iterator(const It& inIt){
            this->iterator = inIt;
        }
        const auto operator*(){
            return *iterator;
        }
         bool operator !=(const const_powerset_iterator& other) const{
                return (this->iterator != other.iterator);
            }
        const_powerset_iterator& operator++() {
                ++this->iterator;
                return *this;
        }
    };
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
                return const_powerset_iterator{set.begin()};
            }
            auto end() const{
                return const_powerset_iterator{set.end()};
            }
    };
}
