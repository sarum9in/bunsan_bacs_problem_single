#pragma once

#include "bacs/single/problem/buildable.hpp"

#include "bunsan/factory_helper.hpp"

#include "bacs/single/api/problem.pb.h"

#include <boost/property_tree/ptree.hpp>

namespace bacs{namespace single{namespace problem
{
    class utility: public buildable
    BUNSAN_FACTORY_BEGIN(utility, const boost::filesystem::path &/*location*/,
                                  const boost::property_tree::ptree &/*config*/)
    public:
        static utility_ptr instance(const boost::filesystem::path &location);

    public:
        virtual api::pb::problem::Utility info() const=0;
    BUNSAN_FACTORY_END(utility)
}}}
