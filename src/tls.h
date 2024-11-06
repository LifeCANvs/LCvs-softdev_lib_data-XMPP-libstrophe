/* SPDX-License-Identifier: MIT */
/* tls.h
** strophe XMPP client library -- TLS abstraction header
**
** Copyright (C) 2005-2009 Collecta, Inc.
** Copyright 2024 LifeCAN!vs
**
**  This software is provided AS-IS with no warranty, either express or
**  implied.
**
** This program is licensed under the MIT license.
*/

/** @file
 *  TLS abstraction API.
 */

#ifndef __LIBSTROPHE_TLS_H__
#define __LIBSTROPHE_TLS_H__

#include "common.h"
#include "sock.h"

typedef struct _tls tls_t;

typedef struct _dnsname_t dnsname_t;

struct _xmpp_tlscert_t {
    xmpp_ctx_t *ctx;
    xmpp_conn_t *conn;
    char *pem;
    char *elements[XMPP_CERT_ELEMENT_MAX];
    dnsname_t *dnsnames;
};

/* provided by the real TLS implementation */

void tls_initialize(void);
void tls_shutdown(void);

tls_t *tls_new(xmpp_conn_t *conn);
void tls_free(tls_t *tls);

char *tls_id_on_xmppaddr(xmpp_conn_t *conn, unsigned int n);
unsigned int tls_id_on_xmppaddr_num(xmpp_conn_t *conn);

xmpp_tlscert_t *tls_peer_cert(xmpp_conn_t *conn);
int tls_set_credentials(tls_t *tls, const char *cafilename);
int tls_init_channel_binding(tls_t *tls,
                             const char **binding_prefix,
                             size_t *binding_prefix_len);
const void *tls_get_channel_binding_data(tls_t *tls, size_t *size);

int tls_start(tls_t *tls);
int tls_stop(tls_t *tls);

int tls_pending(struct conn_interface *intf);
int tls_read(struct conn_interface *intf, void *buff, size_t len);
int tls_write(struct conn_interface *intf, const void *buff, size_t len);
int tls_clear_pending_write(struct conn_interface *intf);

int tls_error(struct conn_interface *intf);
int tls_is_recoverable(struct conn_interface *intf, int error);

/* provided by tls.c */
extern const struct conn_interface tls_intf;

xmpp_tlscert_t *tlscert_new(xmpp_ctx_t *ctx);
int tlscert_add_dnsname(xmpp_tlscert_t *cert, const char *dnsname);

int tls_caching_password_callback(char *pw, size_t pw_max, xmpp_conn_t *conn);
void tls_clear_password_cache(xmpp_conn_t *conn);

#endif /* __LIBSTROPHE_TLS_H__ */
