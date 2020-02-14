#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  SSL_METHOD ;

/* Variables and functions */
 int /*<<< orphan*/  const* dtlsv1_2_client_method () ; 
 int /*<<< orphan*/  const* dtlsv1_2_method () ; 
 int /*<<< orphan*/  const* dtlsv1_2_server_method () ; 
 int /*<<< orphan*/  const* dtlsv1_client_method () ; 
 int /*<<< orphan*/  const* dtlsv1_method () ; 
 int /*<<< orphan*/  const* dtlsv1_server_method () ; 
 int /*<<< orphan*/  const* sslv3_client_method () ; 
 int /*<<< orphan*/  const* sslv3_method () ; 
 int /*<<< orphan*/  const* sslv3_server_method () ; 
 int /*<<< orphan*/  const* tlsv1_1_client_method () ; 
 int /*<<< orphan*/  const* tlsv1_1_method () ; 
 int /*<<< orphan*/  const* tlsv1_1_server_method () ; 
 int /*<<< orphan*/  const* tlsv1_2_client_method () ; 
 int /*<<< orphan*/  const* tlsv1_2_method () ; 
 int /*<<< orphan*/  const* tlsv1_2_server_method () ; 
 int /*<<< orphan*/  const* tlsv1_client_method () ; 
 int /*<<< orphan*/  const* tlsv1_method () ; 
 int /*<<< orphan*/  const* tlsv1_server_method () ; 

const SSL_METHOD *TLSv1_2_method(void)
{
    return tlsv1_2_method();
}

const SSL_METHOD *TLSv1_2_server_method(void)
{
    return tlsv1_2_server_method();
}

const SSL_METHOD *TLSv1_2_client_method(void)
{
    return tlsv1_2_client_method();
}

const SSL_METHOD *TLSv1_1_method(void)
{
    return tlsv1_1_method();
}

const SSL_METHOD *TLSv1_1_server_method(void)
{
    return tlsv1_1_server_method();
}

const SSL_METHOD *TLSv1_1_client_method(void)
{
    return tlsv1_1_client_method();
}

const SSL_METHOD *TLSv1_method(void)
{
    return tlsv1_method();
}

const SSL_METHOD *TLSv1_server_method(void)
{
    return tlsv1_server_method();
}

const SSL_METHOD *TLSv1_client_method(void)
{
    return tlsv1_client_method();
}

const SSL_METHOD *SSLv3_method(void)
{
    return sslv3_method();
}

const SSL_METHOD *SSLv3_server_method(void)
{
    return sslv3_server_method();
}

const SSL_METHOD *SSLv3_client_method(void)
{
    return sslv3_client_method();
}

const SSL_METHOD *DTLSv1_2_method(void)
{
    return dtlsv1_2_method();
}

const SSL_METHOD *DTLSv1_2_server_method(void)
{
    return dtlsv1_2_server_method();
}

const SSL_METHOD *DTLSv1_2_client_method(void)
{
    return dtlsv1_2_client_method();
}

const SSL_METHOD *DTLSv1_method(void)
{
    return dtlsv1_method();
}

const SSL_METHOD *DTLSv1_server_method(void)
{
    return dtlsv1_server_method();
}

const SSL_METHOD *DTLSv1_client_method(void)
{
    return dtlsv1_client_method();
}

