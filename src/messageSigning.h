#ifndef H_CARDANO_APP_MESSAGE_SIGNING
#define H_CARDANO_APP_MESSAGE_SIGNING

#include "bip44.h"

void getWitness(bip44_path_t* pathSpec,
                const uint8_t* txHashBuffer, size_t txHashSize,
                uint8_t* outBuffer, size_t outSize);

void getCVoteRegistrationSignature(bip44_path_t* pathSpec,
                                   const uint8_t* payloadHashBuffer, size_t payloadHashSize,
                                   uint8_t* outBuffer, size_t outSize);

#ifndef APP_XS_OPCERT
void getOpCertSignature(bip44_path_t* pathSpec,
                        const uint8_t* opCertBodyBuffer, size_t opCertBodySize,
                        uint8_t* outBuffer, size_t outSize);
#endif // APP_XS_OPCERT

#endif // H_CARDANO_APP_MESSAGE_SIGNING
