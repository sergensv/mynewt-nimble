/*  Bluetooth Mesh */

/*
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __PROV_H__
#define __PROV_H__

#include "os/os_mbuf.h"
#include "mesh/mesh.h"
#include "../src/ble_hs_conn_priv.h"

#define PROV_ERR_NONE          0x00
#define PROV_ERR_NVAL_PDU      0x01
#define PROV_ERR_NVAL_FMT      0x02
#define PROV_ERR_UNEXP_PDU     0x03
#define PROV_ERR_CFM_FAILED    0x04
#define PROV_ERR_RESOURCES     0x05
#define PROV_ERR_DECRYPT       0x06
#define PROV_ERR_UNEXP_ERR     0x07
#define PROV_ERR_ADDR          0x08

int bt_mesh_pb_adv_open(const uint8_t uuid[16], uint16_t net_idx, uint16_t addr,
			uint8_t attention_duration);

void bt_mesh_pb_adv_recv(struct os_mbuf *buf);

bool bt_prov_active(void);

int bt_mesh_pb_gatt_open(uint16_t conn_handle);
int bt_mesh_pb_gatt_close(uint16_t conn_handle);
int bt_mesh_pb_gatt_recv(uint16_t conn_handle, struct os_mbuf *buf);

const struct bt_mesh_prov *bt_mesh_prov_get(void);

int bt_mesh_prov_init(const struct bt_mesh_prov *prov);

void bt_mesh_prov_reset_link(void);

void bt_mesh_prov_complete(uint16_t net_idx, uint16_t addr);
void bt_mesh_prov_node_added(uint16_t net_idx, uint16_t addr, uint8_t num_elem);
void bt_mesh_prov_reset(void);

#endif
