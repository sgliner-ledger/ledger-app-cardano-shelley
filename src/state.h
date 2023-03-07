#ifndef H_CARDANO_APP_STATE
#define H_CARDANO_APP_STATE

#include "getVersion.h"
#include "getPublicKeys.h"
#include "deriveAddress.h"
#include "deriveNativeScriptHash.h"
#include "signTx.h"
#include "signOpCert.h"
#include "signCVote.h"


typedef union {
	// Here should go states of all instructions
	ins_get_keys_context_t getKeysContext;
	ins_derive_address_context_t deriveAddressContext;
	ins_derive_native_script_hash_context_t deriveNativeScriptHashContext;
	ins_sign_tx_context_t signTxContext;
#ifndef APP_XS_OPCERT
	ins_sign_op_cert_context_t signOpCertContext;
#endif // APP_XS_OPCERT
	ins_sign_cvote_context_t signCVoteContext;
} instructionState_t;

// Note(instructions are uint8_t but we have a special INS_NONE value
extern int currentInstruction;

extern instructionState_t instructionState;

#endif // H_CARDANO_APP_STATE
