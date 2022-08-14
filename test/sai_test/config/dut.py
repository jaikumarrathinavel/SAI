# Copyright (c) 2021 Microsoft Open Technologies, Inc.
#
#    Licensed under the Apache License, Version 2.0 (the "License"); you may
#    not use this file except in compliance with the License. You may obtain
#    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
#
#    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
#    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
#    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
#    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
#
#    See the Apache Version 2.0 License for specific language governing
#    permissions and limitations under the License.
#
#    Microsoft would like to thank the following companies for their review and
#    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
#    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
#
#

from typing import Dict, List
from config.vlan import Vlan
from config.lag import Lag


class Dut():
    """
    Dut config, represent the dut object in the test structure.
    Class attributes:
            default_vrf 
            default_ipv6_route_entry 
            default_ipv4_route_entry 
            loopback_intf 
            local_10v6_route_entry 
            local_128v6_route_entry 
            lag1_rif 
            lag1_nbr 
            lag1_nhop 
            lag1_route 
            lag2_rif 
            lag2_nbr 
            lag2_nhop 
            lag2_route 

            # vlan
            default_vlan_id 
            vlans

            # switch
            switch_id 

            # fdb
            default_vlan_fdb_list 
            vlan_10_fdb_list 
            vlan_20_fdb_list 

            # port
            bridge_port_list 
            default_1q_bridge_id 
            default_trap_group 
            dev_port_list 
            host_intf_table_id 
            portConfigs 
            port_list 
            port_to_hostif_map 
            hostif_list 
            port0_rif 

            # lag
            lag1 
            lag2 
    """

    def __init__(self):
        """
        Init all of the class attributes
        """

        # router
        self.default_vrf = None
        self.default_ipv6_route_entry = None
        self.default_ipv4_route_entry = None
        self.loopback_intf = None
        self.local_10v6_route_entry = None
        self.local_128v6_route_entry = None
        self.lag1_rif = None
        self.lag1_nbr = None
        self.lag1_nhop = None
        self.lag1_route = None
        self.lag2_rif = None
        self.lag2_nbr = None
        self.lag2_nhop = None
        self.lag2_route = None

        # vlan
        self.default_vlan_id = None
        self.vlans: Dict[int, Vlan] = {}
        """
        Vlan object list, key: int, Value: Vlan object
        """

        # switch
        self.switch_id = None

        # fdb
        self.default_vlan_fdb_list: List = None
        self.vlan_10_fdb_list: List = None
        self.vlan_20_fdb_list: List = None

        # port
        self.bridge_port_list: List = None
        """
        bridge port id list
        """
        self.default_1q_bridge_id = None
        self.default_trap_group = None
        self.dev_port_list: List = None
        """
        Local device port index list, 0, 1, ...
        """
        self.host_intf_table_id = None
        self.portConfigs = None
        self.port_list: List = None
        """
        Port object list
        """
        self.port_to_hostif_map = None
        self.hostif_list = None
        """
        Host interface list
        """
        self.port0_rif = None

        # lag
        self.lag1: Lag = None
        self.lag2: Lag = None
