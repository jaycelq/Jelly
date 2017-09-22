//
// detail/socket_ops.h
// 
// Copyright (c) 2017-2017 qiang.li (jaycelq at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef JELLY_NET_DETAIL_SOCKET_OPS_H
#define JELLY_NET_DETAIL_SOCKET_OPS_H

#include "error_code.h"
#include "net/detail/socket_type.h"

namespace jelly {
namespace net {
namespace detail {

// Socket state bits
enum
{
    // The user wants a non-blocking socket.
    user_set_non_blocking = 1,

    // The socket has been set non-blocking
    internal_non_blocking = 2,

    // Helper "state" used to determine whether the socket is non-blocking
    non_blocking = user_set_non_blocking | internal_non_blocking,

    // User wants connection_aborted errors, which are disabled by default
    enable_connection_aborted = 4,

    // The user set the linger option. Needs to checked when closing.
    user_set_linger = 8,

    // The socket is stream-oriented
    stream_oriented = 16,

    // The socket is datagram-oriented
    diagram_oriented = 32,

    // The socket may have been dup()-ed
    possible_dup = 64
};

typedef unsigned char stage_type;

socket_type accept(socket_type s, socket_addr_type* addr,
    std::size_t* addr_len, error_code& ec);

} // namespace detail
} // namespace net
} // namespace jelly

#endif //JELLY_NET_NET_SOCKET_OPS_H
