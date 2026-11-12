
# FNET TCP/IP stack (https://github.com/butok/FNET), used by tcpip.sys.
# Only the stack core is built. The configuration lives in reactos/fnet_user_config.h.

list(APPEND SOURCE
    port/cpu/fnet_cpu.c
    service/fnet_service.c
    stack/fnet_arp.c
    stack/fnet_checksum.c
    stack/fnet_error.c
    stack/fnet_eth.c
    stack/fnet_icmp4.c
    stack/fnet_inet.c
    stack/fnet_ip.c
    stack/fnet_ip4.c
    stack/fnet_isr.c
    stack/fnet_mempool.c
    stack/fnet_netbuf.c
    stack/fnet_netif.c
    stack/fnet_prot.c
    stack/fnet_socket.c
    stack/fnet_stack.c
    stack/fnet_stdlib.c
    stack/fnet_tcp.c
    stack/fnet_timer.c)

add_library(fnet STATIC ${SOURCE})

target_include_directories(fnet PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/reactos
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/stack
    ${CMAKE_CURRENT_SOURCE_DIR}/service
    ${CMAKE_CURRENT_SOURCE_DIR}/port/compiler
    ${CMAKE_CURRENT_SOURCE_DIR}/port/cpu)

if(NOT MSVC)
    # Third party code, keep the upstream sources untouched.
    target_compile_options(fnet PRIVATE -Wno-unused-variable -Wno-unused-but-set-variable)
endif()

