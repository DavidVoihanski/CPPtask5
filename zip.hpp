#pragma once
namespace itertools{
    template<typename firstIt, typename secondIt>
    class const_zip_iterator{
        public:
        firstIt firstIterator;
        firstIt firstEnd;
        secondIt secondIterator;
        bool inSecond;
        const_zip_iterator(const const_zip_iterator& other){
            this->firstIterator = other.firstIterator;
            this->secondIterator = other.secondIterator;
            this->inSecond = other.inSecond;
        }
        const_zip_iterator(firstIt first,  secondIt second){
            this->firstIterator = first;
            this->secondIterator = second;
            this->inSecond = false;
            }
        const_zip_iterator(const firstIt& firstStart, const firstIt& firstEnd, const secondIt& second){
            this->firstIterator = firstStart;
            this->firstEnd = firstEnd;
            this->secondIterator = second;
            this->inSecond = false;
        }
        const std::string operator *(){
            std::string toReturn = "";
            toReturn += *firstIterator;
            toReturn += *secondIterator;
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
                return const_chain_iterator{this->first.begin(), this->first.end(), this->second.begin()};
            }
            auto end() const{
                return const_chain_iterator{this->first.end(), this->second.end()};
            }
        };
}