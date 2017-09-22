//
// socket_type.h
// 
// Copyright (c) 2017-2017 qiang.li (jaycelq at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef JELLY_NET_DETAIL_SOCKET_TYPE_H
#define JELLY_NET_DETAIL_SOCKET_TYPE_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <limits.h>
#include <sys/un.h>

namespace jelly {
namespace net {
namespace detail {

typedef int socket_type;
const int invalid_socket = -1;
const int socket_error_retval = -1;
const int max_addr_v4_str_len = INET_ADDRSTRLEN;
const int max_addr_v6_str_len = INET6_ADDRSTRLEN + 1 + IF_NAMESIZE;
typedef sockaddr socket_addr_type;
typedef in_addr in4_addr_type;
typedef ip_mreq in4_mreq_type;
typedef sockaddr_in sockaddr_in4_type;
typedef in6_addr in6_addr_type;
typedef ipv6_mreq ipv6_mreq_type;
typedef sockaddr_in6 sockaddr_in6_type;
typedef sockaddr_storage sockaddr_storage_type;
typedef sockaddr_un sockaddr_un_type;
typedef addrinfo addrinfo_type;
typedef ::linger linger_type;
typedef int ioctl_arg_type;
typedef uint32_t u_long_type;
typedef uint16_t u_short_type;
typedef ssize_t signed_size_type;

}
}
}

#endif //JELLY_NET_DETAIL_SOCKET_TYPE_H
