/* Copyright (c) 2008-2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef DIAGFWD_H
#define DIAGFWD_H

#define NO_PROCESS	0
#define NON_APPS_PROC	-1

void diagfwd_init(void);
void diagfwd_exit(void);
void diag_process_hdlc(void *data, unsigned len);
void __diag_smd_send_req(void);
void __diag_smd_qdsp_send_req(void);
void __diag_smd_wcnss_send_req(void);
void diag_usb_legacy_notifier(void *, unsigned, struct diag_request *);
long diagchar_ioctl(struct file *, unsigned int, unsigned long);
int diag_device_write(void *, int, struct diag_request *);
int mask_request_validate(unsigned char mask_buf[]);
void diag_clear_reg(int);
int chk_config_get_id(void);
int chk_apps_only(void);
int chk_apps_master(void);
int chk_polling_response(void);
void diag_send_event_mask_update(smd_channel_t *, int num_bytes);
#if 1	// defined(LGE_DIAG_PATCHES_FROM_QCT_CASE_00823742)	// 2012.05.01 james.park@lge.com: applying diag patches from QCT Case#00823742.
void diag_send_msg_mask_update(smd_channel_t *, int ssid_first,
					 int ssid_last, int proc);
void diag_send_log_mask_update(smd_channel_t *, int);
#else
void diag_send_msg_mask_update(smd_channel_t *);
void diag_send_log_mask_update(smd_channel_t *);
#endif /* LGE_DIAG_PATCHES_FROM_QCT_CASE_00823742 */
void diag_update_sleeping_process(int process_id, int data_type);
/* State for diag forwarding */
#ifdef CONFIG_DIAG_OVER_USB
int diagfwd_connect(void);
int diagfwd_disconnect(void);
#endif
extern int diag_debug_buf_idx;
extern unsigned char diag_debug_buf[1024];
extern int diag_event_num_bytes;
extern struct platform_driver msm_diag_dci_driver;
#endif
