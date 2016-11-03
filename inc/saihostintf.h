/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc
 *
 * @file    saihostintf.h
 *
 * @brief   This module defines SAI host interface
 *
 * @par Abstract
 *
 *    This module defines SAI Host Interface which is responsbile for
 *    creating/deleting linux netdev corresponding to the host interface type.
 *    All the management operations of the netdevs such as changing IP address
 *    are outside the scope of SAI.
 *
 */

#if !defined (__SAIHOSTINTF_H_)
#define __SAIHOSTINTF_H_

#include <saitypes.h>

/**
 * @defgroup SAIHOSTINTF SAI - Host Interface specific API definitions
 *
 * @{
 */

/**
 * @brief Defines maximum host interface name
 */
#define HOSTIF_NAME_SIZE 16

/**
 * @brief Host interface trap group attributes
 */
typedef enum _sai_hostif_trap_group_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_HOSTIF_TRAP_GROUP_ATTR_START,

    /**
     * @brief Admin Mode
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default true
     */
    SAI_HOSTIF_TRAP_GROUP_ATTR_ADMIN_STATE = SAI_HOSTIF_TRAP_GROUP_ATTR_START,

    /**
     * @brief Cpu egress queue
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_HOSTIF_TRAP_GROUP_ATTR_QUEUE,

    /**
     * @brief Sai policer object id
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_POLICER
     * @flags CREATE_AND_SET
     * @allownull true
     */
    SAI_HOSTIF_TRAP_GROUP_ATTR_POLICER,

    /**
     * @brief End of attributes
     */
    SAI_HOSTIF_TRAP_GROUP_ATTR_END,

    /** Start of custom range base */
    SAI_HOSTIF_TRAP_GROUP_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range */
    SAI_HOSTIF_TRAP_GROUP_ATTR_CUSTOM_RANGE_END

} sai_hostif_trap_group_attr_t;

/**
 * @brief Create host interface trap group
 *
 * @param[out] hostif_trap_group_id Host interface trap group id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_hostif_trap_group_fn)(
        _Out_ sai_object_id_t *hostif_trap_group_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove host interface trap group
 *
 * @param[in] hostif_trap_group_id Host interface trap group id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_hostif_trap_group_fn)(
        _In_ sai_object_id_t hostif_trap_group_id);

/**
 * @brief Set host interface trap group attribute value.
 *
 * @param[in] hostif_trap_group_id Host interface trap group id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_hostif_trap_group_attribute_fn)(
        _In_ sai_object_id_t hostif_trap_group_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief get host interface trap group attribute value.
 *
 * @param[in] hostif_trap_group_id Host interface trap group id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_get_hostif_trap_group_attribute_fn)(
        _In_ sai_object_id_t hostif_trap_group_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Host interface trap type
 */
typedef enum _sai_hostif_trap_type_t
{
    /* Control plane protocol */

    /* Switch trap */

    /** default action is drop */
    SAI_HOSTIF_TRAP_TYPE_STP = 0x00000000,

    /** default action is drop */
    SAI_HOSTIF_TRAP_TYPE_LACP = 0x00000001,

    /** default action is drop */
    SAI_HOSTIF_TRAP_TYPE_EAPOL = 0x00000002,

    /** default action is drop */
    SAI_HOSTIF_TRAP_TYPE_LLDP = 0x00000003,

    /** default action is drop */
    SAI_HOSTIF_TRAP_TYPE_PVRST = 0x00000004,

    /** default action is forward */
    SAI_HOSTIF_TRAP_TYPE_IGMP_TYPE_QUERY = 0x00000005,

    /** default action is forward */
    SAI_HOSTIF_TRAP_TYPE_IGMP_TYPE_LEAVE = 0x00000006,

    /** default action is forward */
    SAI_HOSTIF_TRAP_TYPE_IGMP_TYPE_V1_REPORT = 0x00000007,

    /** default action is forward */
    SAI_HOSTIF_TRAP_TYPE_IGMP_TYPE_V2_REPORT = 0x00000008,

    /** default action is forward */
    SAI_HOSTIF_TRAP_TYPE_IGMP_TYPE_V3_REPORT = 0x000000009,

    /** default action is trap */
    SAI_HOSTIF_TRAP_TYPE_SAMPLEPACKET = 0x00000000a,

    /** Switch traps custom range start */
    SAI_HOSTIF_TRAP_TYPE_SWITCH_CUSTOM_RANGE_BASE = 0x00001000,

    /* Router traps */

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_ARP_REQUEST = 0x00002000,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_ARP_RESPONSE = 0x00002001,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_DHCP = 0x00002002,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_OSPF = 0x00002003,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_PIM = 0x00002004,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_VRRP = 0x00002005,

    /**
     * @brief BGP traffic (tcp src port == 179 or tcp dst port == 179) to local
     * router IP address (default packet action is forward)
     */
    SAI_HOSTIF_TRAP_TYPE_BGP = 0x00002006,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_DHCPV6 = 0x00002007,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_OSPFV6 = 0x00002008,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_VRRPV6 = 0x00002009,

    /**
     * @brief BGPv6 traffic (tcp src port == 179 or tcp dst port == 179) to
     * local router IP address (default packet action is forward)
     */
    SAI_HOSTIF_TRAP_TYPE_BGPV6 = 0x0000200a,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_IPV6_NEIGHBOR_DISCOVERY = 0x0000200b,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_IPV6_MLD_V1_V2 = 0x0000200c,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_IPV6_MLD_V1_REPORT = 0x0000200d,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_IPV6_MLD_V1_DONE = 0x0000200e,

    /** default packet action is forward */
    SAI_HOSTIF_TRAP_TYPE_MLD_V2_REPORT = 0x0000200f,

    /**
     * @brief IP packets to local router IP address (routes with
     * #SAI_ROUTE_ENTRY_ATTR_NEXT_HOP_ID = #SAI_SWITCH_ATTR_CPU_PORT)
     * (default packet action is trap)
     */
    SAI_HOSTIF_TRAP_TYPE_IP2ME = 0x00002010,

    /**
     * @brief SSH traffic (tcp dst port == 22) to local router IP address
     * (default packet action is trap)
     */
    SAI_HOSTIF_TRAP_TYPE_SSH = 0x00002011,

    /**
     * @brief SNMP traffic (udp dst port == 161) to local router IP address
     * (default packet action is trap)
     */
    SAI_HOSTIF_TRAP_TYPE_SNMP = 0x00002012,

    /** Router traps custom range start */
    SAI_HOSTIF_TRAP_TYPE_ROUTER_CUSTOM_RANGE_BASE = 0x0003000,

    /* Pipeline exceptions */

    /**
     * @brief Packets size exceeds the router interface MTU size
     * (default packet action is trap)
     */
    SAI_HOSTIF_TRAP_TYPE_L3_MTU_ERROR = 0x00004000,

    /**
     * @brief Packets with TTL 0 or 1
     * (default packet action is trap)
     */
    SAI_HOSTIF_TRAP_TYPE_TTL_ERROR = 0x00004001,

    /** Exception traps custom range start */
    SAI_HOSTIF_TRAP_TYPE_CUSTOM_EXCEPTION_RANGE_BASE = 0x00005000,

} sai_hostif_trap_type_t;

/**
 * @brief Host interface trap channel
 */
typedef enum _sai_hostif_trap_channel_t
{
    /** receive packets via file desriptor */
    SAI_HOSTIF_TRAP_CHANNEL_FD,

    /** receive packets via callback */
    SAI_HOSTIF_TRAP_CHANNEL_CB,

    /** receive packets via OS net device */
    SAI_HOSTIF_TRAP_CHANNEL_NETDEV,

    /** Host interface trap channel custom range start */
    SAI_HOSTIF_TRAP_CHANNEL_CUSTOM_RANGE_BASE = 0x10000000

} sai_hostif_trap_channel_t;

/**
 * @brief Host interface trap attributes
 */
typedef enum _sai_hostif_trap_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_HOSTIF_TRAP_ATTR_START,

    /**
     * @brief Host interface trap type []
     *
     * @type sai_hostif_trap_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY | KEY
     */
    SAI_HOSTIF_TRAP_ATTR_TRAP_TYPE = SAI_HOSTIF_TRAP_ATTR_START,

    /**
     * @brief Trap action
     *
     * @type sai_packet_action_t
     * @flags CREATE_AND_SET
     * @default SAI_PACKET_ACTION_FORWARD
     */
    SAI_HOSTIF_TRAP_ATTR_PACKET_ACTION,

    /*
     * Below attributes are only valid when
     *
     * SAI_HOSTIF_TRAP_ATTR_PACKET_ACTION == SAI_PACKET_ACTION_TRAP or
     * SAI_HOSTIF_TRAP_ATTR_PACKET_ACTION == SAI_PACKET_ACTION_LOG
     */

    /**
     * @brief Trap priority. This is equivalent to ACL entry priority
     * #SAI_ACL_ENTRY_ATTR_PRIORITY
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default attrvalue SAI_SWITCH_ATTR_ACL_ENTRY_MINIMUM_PRIORITY
     */
    SAI_HOSTIF_TRAP_ATTR_TRAP_PRIORITY,

    /**
     * @brief Trap channel to use
     *
     * @type sai_hostif_trap_channel_t
     * @flags CREATE_AND_SET
     * @default SAI_HOSTIF_TRAP_CHANNEL_CB
     */
    SAI_HOSTIF_TRAP_ATTR_TRAP_CHANNEL,

    /**
     * @brief file descriptor
     *
     * Valid only when #SAI_HOSTIF_TRAP_ATTR_TRAP_CHANNEL == #SAI_HOSTIF_TRAP_CHANNEL_FD
     * Must be set before set #SAI_HOSTIF_TRAP_ATTR_TRAP_CHANNEL to #SAI_HOSTIF_TRAP_CHANNEL_FD
     *
     * @type sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_HOSTIF
     */
    SAI_HOSTIF_TRAP_ATTR_FD,

    /**
     * @brief Enable trap for a list of SAI ports
     *
     * @type sai_object_list_t
     * @objects SAI_OBJECT_TYPE_PORT
     * @flags CREATE_AND_SET
     * @default empty
     */
    SAI_HOSTIF_TRAP_ATTR_PORT_LIST,

    /**
     * @brief Trap-group ID for the trap
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_HOSTIF_TRAP_GROUP
     * @flags CREATE_AND_SET
     * @default attrvalue SAI_SWITCH_ATTR_DEFAULT_TRAP_GROUP
     */
    SAI_HOSTIF_TRAP_ATTR_TRAP_GROUP,

    /**
     * @brief End of attributes
     */
    SAI_HOSTIF_TRAP_ATTR_END,

    /** Custom range start */
    SAI_HOSTIF_TRAP_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** Custom range end */
    SAI_HOSTIF_TRAP_ATTR_CUSTOM_RANGE_END

} sai_hostif_trap_attr_t;

/**
 * @brief Create host interface trap
 *
 * @param[out] hostif_trap_id Host interface trap id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_hostif_trap_fn)(
        _Out_ sai_object_id_t *hostif_trap_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove host interface trap
 *
 * @param[in] hostif_trap_group_id Host interface trap group id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_hostif_trap_fn)(
        _In_ sai_object_id_t hostif_trap_id);

/**
 * @brief Set trap attribute value.
 *
 * @param[in] hostif_trap_id Host interface trap id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_set_hostif_trap_attribute_fn)(
        _In_ sai_object_id_t hostif_trapid,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get trap attribute value.
 *
 * @param[in] hostif_trap_id Host interface trap id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_get_hostif_trap_attribute_fn)(
        _In_ sai_object_id_t hostif_trapid,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Host interface user defined trap ID table range
 */
#define SAI_HOSTIF_USER_DEFINED_TRAP_ID_TABLE_RANGE 0x1

/**
 * @brief user defined traps
 */
typedef enum _sai_hostif_user_defined_trap_id_t
{
    /** Samplepacket traps */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_SAMPLEPACKET = 0x00000000,

    /** ACL traps */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_ACL_MIN = 0x00000001,

    /** ACL traps range max */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_ACL_MAX = SAI_HOSTIF_USER_DEFINED_TRAP_ID_ACL_MIN + SAI_HOSTIF_USER_DEFINED_TRAP_ID_TABLE_RANGE,

    /** router traps */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_ROUTER_MIN = SAI_HOSTIF_USER_DEFINED_TRAP_ID_ACL_MAX + 1,

    /** router traps max */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_ROUTER_MAX = SAI_HOSTIF_USER_DEFINED_TRAP_ID_ROUTER_MIN + SAI_HOSTIF_USER_DEFINED_TRAP_ID_TABLE_RANGE,

    /** neighbor table traps */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_NEIGH_MIN = SAI_HOSTIF_USER_DEFINED_TRAP_ID_ROUTER_MAX+1,

    /** neighbor table traps max */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_NEIGH_MAX = SAI_HOSTIF_USER_DEFINED_TRAP_ID_NEIGH_MIN + SAI_HOSTIF_USER_DEFINED_TRAP_ID_TABLE_RANGE,

    /** fdb traps */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_FDB_MIN = SAI_HOSTIF_USER_DEFINED_TRAP_ID_NEIGH_MAX + 1,

    /** fdb traps max */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_FDB_MAX = SAI_HOSTIF_USER_DEFINED_TRAP_ID_FDB_MIN + SAI_HOSTIF_USER_DEFINED_TRAP_ID_TABLE_RANGE,

    /** Custom range base */
    SAI_HOSTIF_USER_DEFINED_TRAP_ID_CUSTOM_RANGE_BASE = 0x10000000,

} sai_hostif_user_defined_trap_id_t;

/**
 * @brief Host interface user defined traps attributes
 */
typedef enum _sai_hostif_user_defined_trap_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_HOSTIF_USER_DEFINED_TRAP_ATTR_START,

    /**
     * @brief Trap channel to use
     *
     * @type sai_hostif_trap_channel_t
     * @flags CREATE_ONLY
     * @default SAI_HOSTIF_TRAP_CHANNEL_CB
     */
    SAI_HOSTIF_USER_DEFINED_TRAP_ATTR_HOSTIF_TRAP_CHANNEL = SAI_HOSTIF_USER_DEFINED_TRAP_ATTR_START,

    /**
     * @brief File descriptor
     *
     * Valid only when #SAI_HOSTIF_TRAP_ATTR_TRAP_CHANNEL == #SAI_HOSTIF_TRAP_CHANNEL_FD
     * Must be set before set #SAI_HOSTIF_TRAP_ATTR_TRAP_CHANNEL to #SAI_HOSTIF_TRAP_CHANNEL_FD
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_HOSTIF
     * @flags CREATE_AND_SET
     */
    SAI_HOSTIF_USER_DEFINED_TRAP_ATTR_FD,

    /**
     * @brief End of attributes
     */
    SAI_HOSTIF_USER_DEFINED_TRAP_ATTR_END,

} sai_hostif_user_defined_trap_attr_t;

/**
 * @brief Set user defined trap attribute value.
 *
 * @param[in] hostif_user_defined_trap_id Host interface user defined trap id
 * @param[in] attr Aattribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_set_hostif_user_defined_trap_attribute_fn)(
        _In_ sai_hostif_user_defined_trap_id_t hostif_user_defined_trapid,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get user defined trap attribute value.
 *
 * @param[in] hostif_user_defined_trap_id Host interface user defined trap id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_get_hostif_user_defined_trap_attribute_fn)(
        _In_ sai_hostif_user_defined_trap_id_t hostif_user_defined_trapid,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Attribute data for SAI_HOSTIF_ATTR_TYPE
 */
typedef enum _sai_hostif_type_t
{
    /** Netdev-based Host Interface Type */
    SAI_HOSTIF_TYPE_NETDEV,

    /** file descriptor */
    SAI_HOSTIF_TYPE_FD

} sai_hostif_type_t;

/**
 * @brief Host interface attribute IDs
 */
typedef enum _sai_hostif_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_HOSTIF_ATTR_START,

    /**
     * @brief Host interface type
     *
     * @type sai_hostif_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_HOSTIF_ATTR_TYPE = SAI_HOSTIF_ATTR_START,

    /**
     * @brief Assosiated port or router interface
     *
     * Valid only when #SAI_HOSTIF_ATTR_TYPE == #SAI_HOSTIF_TYPE_NETDEV
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_PORT, SAI_OBJECT_TYPE_ROUTER_INTERFACE
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @condition SAI_HOSTIF_ATTR_TYPE == SAI_HOSTIF_TYPE_NETDEV
     */
    SAI_HOSTIF_ATTR_RIF_OR_PORT_ID,

    /**
     * @brief Name [char[HOSTIF_NAME_SIZE]]
     *
     * The maximum number of charactars for the name is HOSTIF_NAME_SIZE - 1 since
     * it needs the terminating null byte ('\0') at the end.
     *
     * Valid only when #SAI_HOSTIF_ATTR_TYPE == #SAI_HOSTIF_TYPE_NETDEV
     *
     * @type char
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @condition SAI_HOSTIF_ATTR_TYPE == SAI_HOSTIF_TYPE_NETDEV
     */
    SAI_HOSTIF_ATTR_NAME,

    /**
     * @brief Set the operational status for this host interface
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_HOSTIF_ATTR_OPER_STATUS,

    /**
     * @brief Rnd of attributes
     */
    SAI_HOSTIF_ATTR_END,

    /** Custom range base value */
    SAI_HOSTIF_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_HOSTIF_ATTR_CUSTOM_RANGE_END

} sai_hostif_attr_t;

/**
 * @brief Create host interface
 *
 * @param[out] hif_id Host interface id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Aarray of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_create_hostif_fn)(
        _Out_ sai_object_id_t *hif_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove host interface
 *
 * @param[in] hif_id Host interface id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_remove_hostif_fn)(
        _In_ sai_object_id_t hif_id);

/**
 * @brief Set host interface attribute
 *
 * @param[in] hif_id Host interface id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_set_hostif_attribute_fn)(
        _In_ sai_object_id_t hif_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get host interface attribute
 *
 * @param[in] hif_id Host interface id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_get_hostif_attribute_fn)(
        _In_ sai_object_id_t hif_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Host interface TX type
 */
typedef enum _sai_hostif_tx_type_t
{
    /**
     * @brief Bypass switch ASIC processing pipeline,
     * tx packet goes to the specified output port directly
     */
    SAI_HOSTIF_TX_TYPE_PIPELINE_BYPASS,

    /** tx packet goes to the switch ASIC processing pipeline to decide the output port */
    SAI_HOSTIF_TX_TYPE_PIPELINE_LOOKUP,

    /** Custom range bae */
    SAI_HOSTIF_TX_TYPE_CUSTOM_RANGE_BASE = 0x10000000

} sai_hostif_tx_type_t;

/**
 * @brief Host interface packet attributes
 */
typedef enum _sai_hostif_packet_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_HOSTIF_PACKET_ATTR_START,

    /**
     * @brief Trap ID (for receive-only)
     *
     * @type sai_hostif_trap_type_t
     * @flags READ_ONLY
     */
    SAI_HOSTIF_PACKET_ATTR_HOSTIF_TRAP_TYPE = SAI_HOSTIF_PACKET_ATTR_START,

    /**
     * @brief User-Defined Trap ID (for receive-only)
     *
     * @type sai_hostif_user_defined_trap_id_t
     * @flags READ_ONLY
     */
    SAI_HOSTIF_PACKET_ATTR_HOSTIF_USER_DEFINED_TRAP_ID,

    /**
     * @brief Ingress port (for receive-only)
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_PORT
     * @flags READ_ONLY
     */
    SAI_HOSTIF_PACKET_ATTR_INGRESS_PORT,

    /**
     * @brief Ingress LAG (for receive-only)
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_LAG
     * @flags READ_ONLY
     */
    SAI_HOSTIF_PACKET_ATTR_INGRESS_LAG,

    /**
     * @brief Packet transmit type. (MANDATORY_ON_SEND)
     *
     * @type sai_hostif_tx_type_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_HOSTIF_PACKET_ATTR_HOSTIF_TX_TYPE,

    /**
     * @brief Egress port or
     * (MANDATORY_ON_SEND when #SAI_HOSTIF_PACKET_ATTR_HOSTIF_TX_TYPE == #SAI_HOSTIF_TX_TYPE_PIPELINE_BYPASS)
     * For receive case, filled with the egress destination port for unicast packets.
     * Egress LAG member port id to be filled for the LAG destination case.
     * Applicable for use-case like SAMPLEPACKET traps
     *
     * @type sai_object_id_t
     * @objects SAI_OBJECT_TYPE_PORT
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @condition SAI_HOSTIF_PACKET_ATTR_HOSTIF_TX_TYPE == SAI_HOSTIF_TX_TYPE_PIPELINE_BYPASS
     */
    SAI_HOSTIF_PACKET_ATTR_EGRESS_PORT_OR_LAG,

    /**
     * @brief End of attributes
     */
    SAI_HOSTIF_PACKET_ATTR_END,

} sai_hostif_packet_attr_t;

/**
 * @brief Hostif receive function
 *
 * @param[in] hif_id Host interface id
 * @param[out] buffer Packet buffer
 * @param[inout] buffer_size Allocated buffer size [in], actual packet size in bytes [out]
 * @param[inout] attr_count Allocated list size [in], number of attributes [out]
 * @param[out] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success #SAI_STATUS_BUFFER_OVERFLOW if
 * buffer_size is insufficient, and buffer_size will be filled with required
 * size. Or if attr_count is insufficient, and attr_count will be filled with
 * required count. Failure status code on error
 */
typedef sai_status_t(*sai_recv_hostif_packet_fn)(
        _In_ sai_object_id_t hif_id,
        _Out_ void *buffer,
        _Inout_ sai_size_t *buffer_size,
        _Inout_ uint32_t *attr_count,
        _Out_ sai_attribute_t *attr_list);

/**
 * @brief Hostif send function
 *
 * @param[in] hif_id Host interface id. only valid for send through FD channel. Use #SAI_NULL_OBJECT_ID for send through CB channel.
 * @param[in] buffer Packet buffer
 * @param[in] buffer size Packet size in bytes
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t(*sai_send_hostif_packet_fn)(
        _In_ sai_object_id_t hif_id,
        _In_ void *buffer,
        _In_ sai_size_t buffer_size,
        _In_ uint32_t attr_count,
        _In_ sai_attribute_t *attr_list);

/**
 * @brief Hostif receive callback
 *
 * @param[in] buffer Packet buffer
 * @param[in] buffer_size Actual packet size in bytes
 * @param[in] attr_count Nnumber of attributes
 * @param[in] attr_list Array of attributes
 */
typedef void(*sai_packet_event_notification_fn)(
        _In_ const void *buffer,
        _In_ sai_size_t buffer_size,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief hostif methods table retrieved with sai_api_query()
 */
typedef struct _sai_hostif_api_t
{
    sai_create_hostif_fn                           create_hostif;
    sai_remove_hostif_fn                           remove_hostif;
    sai_set_hostif_attribute_fn                    set_hostif_attribute;
    sai_get_hostif_attribute_fn                    get_hostif_attribute;
    sai_create_hostif_trap_group_fn                create_hostif_trap_group;
    sai_remove_hostif_trap_group_fn                remove_hostif_trap_group;
    sai_set_hostif_trap_group_attribute_fn         set_trap_group_attribute;
    sai_get_hostif_trap_group_attribute_fn         get_trap_group_attribute;
    sai_create_hostif_trap_fn                      create_trap;
    sai_remove_hostif_trap_fn                      remove_trap;
    sai_set_hostif_trap_attribute_fn               set_trap_attribute;
    sai_get_hostif_trap_attribute_fn               get_trap_attribute;
    sai_set_hostif_user_defined_trap_attribute_fn  set_user_defined_trap_attribute;
    sai_get_hostif_user_defined_trap_attribute_fn  get_user_defined_trap_attribute;
    sai_recv_hostif_packet_fn                      recv_packet;
    sai_send_hostif_packet_fn                      send_packet;
} sai_hostif_api_t;

/**
 * @}
 */
#endif /** __SAIHOSTINTF_H_ */
