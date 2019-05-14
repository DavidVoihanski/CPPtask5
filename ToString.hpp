#include <sstream>
#include<string>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
namespace itertools{
    template<typename Iterable>
    std::string iterable_to_string(const Iterable& iterable) {
	ostringstream ostr;
	for (auto i: iterable)
		ostr << i << ",";
	return ostr.str();
    }   
}