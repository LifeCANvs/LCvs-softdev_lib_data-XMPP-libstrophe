/* SPDX-License-Identifier: MIT */
/* tls_dummy.c
** strophe XMPP client library -- TLS abstraction dummy impl.
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
 *  TLS dummy implementation.
 */

#include "common.h"
#include "tls.h"
#include "sock.h"

struct _tls {
    xmpp_ctx_t *ctx; /* do we need this? */
    sock_t sock;
    /* we don't implement anything */
};

void tls_initialize(void)
{
    return;
}

void tls_shutdown(void)
{
    return;
}

char *tls_id_on_xmppaddr(xmpp_conn_t *conn, unsigned int n)
{
    UNUSED(conn);
    UNUSED(n);
    /* always fail */
    return NULL;
}

unsigned int tls_id_on_xmppaddr_num(xmpp_conn_t *conn)
{
    UNUSED(conn);
    /* always fail */
    return 0;
}

tls_t *tls_new(xmpp_conn_t *conn)
{
    UNUSED(conn);
    /* always fail */
    return NULL;
}

void tls_free(tls_t *tls)
{
    UNUSED(tls);
    return;
}

xmpp_tlscert_t *tls_peer_cert(xmpp_conn_t *conn)
{
    UNUSED(conn);
    return NULL;
}

int tls_set_credentials(tls_t *tls, const char *cafilename)
{
    UNUSED(tls);
    UNUSED(cafilename);
    return -1;
}

int tls_init_channel_binding(tls_t *tls,
                             const char **binding_prefix,
                             size_t *binding_prefix_len)
{
    UNUSED(tls);
    UNUSED(binding_prefix);
    UNUSED(binding_prefix_len);
    return -1;
}

const void *tls_get_channel_binding_data(tls_t *tls, size_t *size)
{
    UNUSED(tls);
    UNUSED(size);
    return NULL;
}

int tls_start(tls_t *tls)
{
    UNUSED(tls);
    return -1;
}

int tls_stop(tls_t *tls)
{
    UNUSED(tls);
    return -1;
}

int tls_error(struct conn_interface *intf)
{
    UNUSED(intf);
    return 0;
}

int tls_pending(struct conn_interface *intf)
{
    UNUSED(intf);
    return 0;
}

int tls_read(struct conn_interface *intf, void *buff, size_t len)
{
    UNUSED(intf);
    UNUSED(buff);
    UNUSED(len);
    return -1;
}

int tls_write(struct conn_interface *intf, const void *buff, size_t len)
{
    UNUSED(intf);
    UNUSED(buff);
    UNUSED(len);
    return -1;
}

int tls_clear_pending_write(struct conn_interface *intf)
{
    UNUSED(intf);
    return -1;
}

int tls_is_recoverable(struct conn_interface *intf, int error)
{
    UNUSED(intf);
    UNUSED(error);
    return 0;
}
