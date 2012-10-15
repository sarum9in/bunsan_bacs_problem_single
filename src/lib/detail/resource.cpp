#include "bacs/single/problem/detail/resource.hpp"

#include <string>
#include <algorithm>

#include <cmath>

#include <boost/cast.hpp>
#include <boost/spirit/include/qi.hpp>

namespace bacs{namespace single{namespace problem{namespace detail
{
    namespace qi = boost::spirit::qi;

    struct si_multiple: qi::symbols<char, double>
    {
        si_multiple()
        {
            add
                ("da", 1e1)
                ("h", 1e2)
                ("k", 1e3)
                ("M", 1e6)
                ("G", 1e9)
                ("T", 1e12)
                ("P", 1e15)
                ("E", 1e18)
                ("Z", 1e21)
                ("Y", 1e24);
        }
    };

    struct si_submultiple: qi::symbols<char, double>
    {
        si_submultiple()
        {
            add
                ("d", 1e-1)
                ("c", 1e-2)
                ("m", 1e-3)
                ("u", 1e-6)
                ("n", 1e-9)
                ("p", 1e-12)
                ("f", 1e-15)
                ("a", 1e-18)
                ("z", 1e-21)
                ("y", 1e-24);
        }
    };

    struct binary_multiple: qi::symbols<char, double>
    {
        binary_multiple()
        {
            constexpr double ten = 1 << 10;
            double mult = 1;
            add("Ki", mult *= ten);
            add("Mi", mult *= ten);
            add("Gi", mult *= ten);
            add("Ti", mult *= ten);
            add("Pi", mult *= ten);
            add("Ei", mult *= ten);
            add("Zi", mult *= ten);
            add("Yi", mult *= ten);
        }
    };

    template <typename Iterator>
    struct time_parser: qi::grammar<Iterator, double()>
    {
        time_parser(): time_parser::base_type(start)
        {
            qi::rule<Iterator> multiple = (si_multiple() | si_submultiple()) >> qi::char_('s');
            qi::rule<Iterator> multiple_unit = qi::eps | multiple;
            start = qi::double_ >> multiple_unit;
        }

        qi::rule<Iterator, double()> start;
    };

    template <typename Iterator>
    struct memory_parser: qi::grammar<Iterator, double()>
    {
        memory_parser(): memory_parser::base_type(start)
        {
            qi::rule<Iterator> multiple = binary_multiple() >> qi::char_('s');
            qi::rule<Iterator> multiple_unit = qi::eps | multiple;
            start = qi::double_ >> multiple_unit;
        }

        qi::rule<Iterator, double()> start;
    };

    std::uint64_t parse_time_millis(const std::string &time)
    {
        std::string::const_iterator begin = time.begin();
        double result;
        qi::parse(begin, time.end(), time_parser<std::string::const_iterator>(), result);
        return boost::numeric_cast<std::uint64_t>(std::round(result * 1000));
    }

    std::uint64_t parse_memory_bytes(const std::string &memory)
    {
        std::string::const_iterator begin = memory.begin();
        double result;
        qi::parse(begin, memory.end(), memory_parser<std::string::const_iterator>(), result);
        return boost::numeric_cast<std::uint64_t>(std::round(result));
    }
}}}}