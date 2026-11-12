/*
 * PROJECT:     ReactOS TCP/IP protocol driver
 * LICENSE:     Apache-2.0 (https://spdx.org/licenses/Apache-2.0)
 * PURPOSE:     FNET configuration for the ReactOS kernel (tcpip.sys)
 *
 * FNET is used here only as a TCP engine. ReactOS keeps its own IP, ARP,
 * ICMP, UDP and routing code: FNET receives whole IPv4 packets from the
 * ReactOS IP layer and hands whole IPv4 packets back to it for sending.
 */

#ifndef _FNET_USER_CONFIG_H_
#define _FNET_USER_CONFIG_H_

/*****************************************************************************
 * Platform. There is no FNET CPU port for x86/ReactOS, everything the stack
 * needs from the platform is provided by tcpip.sys (ip/fnet_glue/fnet_port.c).
 *****************************************************************************/
#define FNET_CPU_STR                        "REACTOS"
#define FNET_CFG_CPU_LITTLE_ENDIAN          (1)
#define FNET_CFG_CPU_CLOCK_HZ               (1000000000u) /* Not used. */
#define FNET_CFG_CPU_TIMER_NUMBER           (0u)          /* Not used (FNET_CFG_TIMER_ALT). */
#define FNET_CFG_CPU_TIMER_VECTOR_NUMBER    (0u)          /* Not used (FNET_CFG_TIMER_ALT). */
#define FNET_CFG_CPU_ETH0                   (0)           /* No FNET Ethernet driver. */
#define FNET_CFG_CPU_ETH1                   (0)
#define FNET_CFG_CPU_WIFI                   (0)
#define FNET_CFG_CPU_FLASH                  (0)

/* Basic data types, normally provided by the FNET CPU port headers. */
typedef unsigned char           fnet_uint8_t;
typedef unsigned short int      fnet_uint16_t;
typedef unsigned long int       fnet_uint32_t;  /* 32 bits on Windows (LLP64) */
typedef unsigned long long      fnet_uint64_t;
typedef signed char             fnet_int8_t;
typedef signed short int        fnet_int16_t;
typedef signed long int         fnet_int32_t;
typedef signed long long        fnet_int64_t;
typedef volatile fnet_uint8_t   fnet_vuint8_t;
typedef volatile fnet_uint16_t  fnet_vuint16_t;
typedef volatile fnet_uint32_t  fnet_vuint32_t;
typedef volatile fnet_uint64_t  fnet_vuint64_t;

/* FNET only knows how to detect embedded compilers. */
#if defined(_MSC_VER) && !defined(__clang__)
    #define FNET_COMP_STR                   "MSVC"
    #define FNET_COMP_PACKED_BEGIN          __pragma(pack(push, 1))
    #define FNET_COMP_PACKED_END            __pragma(pack(pop))
#endif

/*****************************************************************************
 * Stack.
 *****************************************************************************/
#define FNET_CFG_IP4                        (1)
#define FNET_CFG_IP6                        (0)
#define FNET_CFG_TCP                        (1)
#define FNET_CFG_UDP                        (0) /* UDP is handled by ReactOS. */
#define FNET_CFG_RAW                        (0) /* Raw IP is handled by ReactOS. */
#define FNET_CFG_LOOPBACK                   (0) /* ReactOS has its own loopback interface. */
#define FNET_CFG_MULTICAST                  (0)
#define FNET_CFG_IGMP                       (0)
#define FNET_CFG_IP4_FRAGMENTATION          (1) /* Reassembly of fragmented TCP segments. */
#define FNET_CFG_TCP_URGENT                 (0)

/* All FNET calls are made from a single kernel thread, so FNET needs no
 * locking of its own. Time comes from the ReactOS kernel. */
#define FNET_CFG_MULTITHREADING             (0)
#define FNET_CFG_TIMER_ALT                  (1)

/* Sockets. */
#define FNET_CFG_SOCKET_MAX                 (512u)
#define FNET_CFG_SOCKET_BSD_NAMES           (0) /* Avoid clashes with ReactOS headers. */
#define FNET_CFG_SOCKET_TCP_MSS             (0u) /* MSS = interface MTU - 40. */
#define FNET_CFG_SOCKET_TCP_TX_BUF_SIZE     (64u * 1024u)
#define FNET_CFG_SOCKET_TCP_RX_BUF_SIZE     (128u * 1024u)

/* No FNET services yet. */
#define FNET_CFG_DHCP_CLN                   (0)
#define FNET_CFG_DHCP_SRV                   (0)
#define FNET_CFG_DNS                        (0)

/* Debugging. */
#define FNET_CFG_DEBUG                      (0)
#define FNET_CFG_ASSERT                     (0)

#endif /* _FNET_USER_CONFIG_H_ */
