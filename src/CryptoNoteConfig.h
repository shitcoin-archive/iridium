// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>

namespace CryptoNote {
namespace parameters {

const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x16fa;
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 20;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(2500000000000000);
const size_t CRYPTONOTE_COIN_VERSION                         = 1;
const unsigned EMISSION_SPEED_FACTOR                         = 18;

static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 60000; // increasing to allow bigger tx
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V3  = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2; // idem
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V3;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MINIMUM_FEE                                   = UINT64_C(5000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(5000);

const uint64_t DIFFICULTY_TARGET                             = 175;
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;
const size_t   DIFFICULTY_WINDOW_V1                          = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V2                          = 60;
const size_t   DIFFICULTY_WINDOW_V3                          = DIFFICULTY_WINDOW_V2;
const size_t   DIFFICULTY_CUT                                = 60;
const size_t   DIFFICULTY_CUT_V1                             = DIFFICULTY_CUT;
const size_t   DIFFICULTY_CUT_V2                             = DIFFICULTY_CUT;
const size_t   DIFFICULTY_CUT_V3                             = DIFFICULTY_CUT;
const size_t   DIFFICULTY_LAG                                = 15;
const size_t   DIFFICULTY_LAG_V1                             = DIFFICULTY_LAG;
const size_t   DIFFICULTY_LAG_V2                             = 0;
const size_t   DIFFICULTY_LAG_V3                             = DIFFICULTY_LAG_V2;

static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        =  20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7;
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 15 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 8560;
const uint32_t IRIDIUM_REWARD_ADJUSTMENT_BLOCK               = 8560;

const uint32_t UPGRADE_HEIGHT_V2                             = 69500;
const uint32_t UPGRADE_HEIGHT_V3                             = 95250;
const uint32_t UPGRADE_HEIGHT_V4                             = -1;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";

// testnet setup
const uint32_t TESTNET_UPGRADE_HEIGHT_V2                             = 2;
const uint32_t TESTNET_UPGRADE_HEIGHT_V3                             = 10;
const uint32_t TESTNET_UPGRADE_HEIGHT_V4                             = -1;
const uint64_t TESTNET_DIFFICULTY_TARGET                             = 15; // target in testnet mode

} // parameters

const char     CRYPTONOTE_NAME[]                             = "iridium";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  300;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  12007;
const int      RPC_DEFAULT_PORT                              =  13007;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 100000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115";

const char* const SEED_NODES[] = {
    "178.33.231.97:12017", /*RBX*/
    "178.33.231.97:12018",
    "178.33.231.97:12019",
    "178.33.231.97:12020",
    "158.69.127.27:12017", /*MTL*/
    "158.69.127.27:12018",
    "158.69.127.27:12019",
    "158.69.127.27:12020",
    "139.99.131.92:12017", /*SDN*/
    "139.99.131.92:12018",
    "139.99.131.92:12019",
    "139.99.131.92:12020",
};


struct CheckpointData {
    uint32_t index;
    const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
    {1472,"c04eeed2a0472ed73a5a42e14834cbb82ff35dae555df343d1d5abcac0dc0c19"},
    {1473,"1571fe8ab50ec2d7c3a523f939524086408c9e9f1fadad820d8af50bbf4ec1dc"},
    {1474,"72d9313ed27985756ec2be9d524aee16026c2f8c5b48c2ea9886a88334019b8d"},
    {69500,"1e6f58fac635e3e0a0ca3845f6a07abaf4080c36dd91bfab315f6cdb657cc775"},
    {69501,"f7533fed7e05112098b9d4e0e6c92c6e2bb9145d0b4ca897a1e241e57a8f6206"},
    {92300,"ce67a10acca26ce15cef9a441dbfeff06667e41eeacdc6dcc8661b2c0bc45783"}
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
