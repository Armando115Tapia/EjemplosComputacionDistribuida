/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "suma.h"

bool_t
xdr_sumandos (XDR *xdrs, sumandos *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->sumando1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->sumando2))
		 return FALSE;
	return TRUE;
}
