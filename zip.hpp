#pragma once
namespace itertools{
    template<typename firstRes, typename secondRes>
    class resultSet{
        firstRes first;
        secondRes second;
        public:
        resultSet(const firstRes& first_, const secondRes& second_):first(first_),second(second_){
        }
        friend std::ostream &operator<<(std::ostream &os, resultSet const &m){
            os << m.first << "," << m.second;
            return os;
        }
    };
    template<typename firstIt, typename secondIt>
    class const_zip_iterator{
        public:
        firstIt firstIterator;
        secondIt secondIterator;
        const_zip_iterator(){

        }
        const_zip_iterator(const const_zip_iterator& other){
            this->firstIterator = other.firstIterator;
            this->secondIterator = other.secondIterator;
        }
        const_zip_iterator(const firstIt& firstStart, const secondIt& second){
            this->firstIterator = firstStart;
            this->secondIterator = second;
        }
        const auto operator *(){
            resultSet toReturn{*firstIterator, *secondIterator};
            return toReturn;
        }
        const_zip_iterator& operator++() {
            ++this->firstIterator;
            ++this->secondIterator;
            return *this;
        }
        bool operator !=(const const_zip_iterator& other) const{
            return (this->firstIterator != other.firstIterator || this->secondIterator != other.secondIterator);
         }
    };  
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
            auto begin() const{
                return const_zip_iterator{this->first.begin(), this->second.begin()};
            }
            auto end() const{
                return const_zip_iterator{this->first.end(), this->second.end()};
            }
        };
}