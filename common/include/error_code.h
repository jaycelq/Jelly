//
// error_code.h
// 
// Copyright (c) 2017-2017 qiang.li (jaycelq at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef JELLY_ERROR_CODE_H
#define JELLY_ERROR_CODE_H

#include <system_error>

namespace jelly
{

typedef std::error_category error_catergory;
typedef std::error_code error_code;

const error_catergory& system_category() { return std::system_category();}
}

#endif //NET_ERROR_CODE_H
