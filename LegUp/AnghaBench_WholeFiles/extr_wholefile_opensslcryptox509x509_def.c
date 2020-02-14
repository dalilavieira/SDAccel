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

/* Variables and functions */
 char const* X509_CERT_AREA ; 
 char const* X509_CERT_DIR ; 
 char const* X509_CERT_DIR_EVP ; 
 char const* X509_CERT_FILE ; 
 char const* X509_CERT_FILE_EVP ; 
 char const* X509_PRIVATE_DIR ; 

const char *X509_get_default_private_dir(void)
{
    return X509_PRIVATE_DIR;
}

const char *X509_get_default_cert_area(void)
{
    return X509_CERT_AREA;
}

const char *X509_get_default_cert_dir(void)
{
    return X509_CERT_DIR;
}

const char *X509_get_default_cert_file(void)
{
    return X509_CERT_FILE;
}

const char *X509_get_default_cert_dir_env(void)
{
    return X509_CERT_DIR_EVP;
}

const char *X509_get_default_cert_file_env(void)
{
    return X509_CERT_FILE_EVP;
}

