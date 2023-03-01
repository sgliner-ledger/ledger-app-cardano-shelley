#ifndef H_HANDLERS

#include <os_io_seproxyhal.h>
#include <stdlib.h>

#include "handlers.h"
#include "getVersion.h"
#include "getSerial.h"
#include "getPublicKeys.h"
#include "runTests.h"
#include "errors.h"
#include "deriveAddress.h"
#include "deriveNativeScriptHash.h"
#include "signTx.h"
#include "signOpCert.h"
#include "signCVote.h"

// The APDU protocol uses a single-byte instruction code (INS) to specify
// which command should be executed. We'll use this code to dispatch on a
// table of function pointers.
handler_fn_t* lookupHandler(uint8_t ins)
{
	switch (ins) {
#define  CASE(INS, HANDLER) case INS: return HANDLER;
		// 0x0* -  app status calls
		CASE(0x00, getVersion_handleAPDU);
		CASE(0x01, getSerial_handleAPDU);

		// 0x1* -  public-key/address related
		CASE(0x10, getPublicKeys_handleAPDU);
		CASE(0x11, deriveAddress_handleAPDU);
		CASE(0x12, deriveNativeScriptHash_handleAPDU);

		// 0x2* -  signing related
		CASE(0x21, signTx_handleAPDU);
#ifndef APP_XS
		CASE(0x22, signOpCert_handleAPDU);
#endif // APP_XS
		CASE(0x23, signCVote_handleAPDU);

		#ifdef DEVEL
		// 0xF* -  debug_mode related
		CASE(0xF0, handleRunTests);
		//   0xF1  reserved for INS_SET_HEADLESS_INTERACTION
		#endif // DEVEL
#undef   CASE
	default:
		return NULL;
	}
}

#endif
