/**
 * @file   sha.hpp
 * @author  fqguozhou@163.com
 * @date   Thu Jul 16 11:33:25 2015
 *
 * @brief
 *
 *
 */

#ifndef __SHA_HPP__
#define __SHA_HPP__
#include "miacropp/config.hpp"
#include "lib/utils.hpp"
#include <cstdint>
#include <cstring>
#include <string>

namespace miacropp
{
  namespace sha
  {
    class sha1_type
    {
     public:
      typedef uint32_t UNIT_T;
      static const size_t HASH_LENGTH = 20;
      static const size_t CHUNK_SIZE = 64;
      static const size_t K_COUNT = 80;
      static const UNIT_T K[80];
      static const size_t H_COUNT = 5;
      static const UNIT_T H[H_COUNT];
    };

    class sha224_type
    {
     public:
      typedef uint32_t UNIT_T;
      static const size_t HASH_LENGTH = 28;
      static const size_t CHUNK_SIZE = 64;
      static const size_t K_COUNT = 64;
      static const UNIT_T K[K_COUNT];
      static const size_t H_COUNT = 8;
      static const UNIT_T H[H_COUNT];
    };
    class sha256_type
    {
     public:
      typedef uint32_t UNIT_T;
      static const size_t HASH_LENGTH = 32;
      static const size_t CHUNK_SIZE = 64;
      static const size_t K_COUNT = 64;
      static const UNIT_T K[K_COUNT];
      static const size_t H_COUNT = 8;
      static const UNIT_T H[H_COUNT];
    };
    class sha384_type
    {
     public:
      typedef uint64_t UNIT_T;
      static const size_t HASH_LENGTH = 48;
      static const size_t CHUNK_SIZE = 128;
      static const size_t K_COUNT = 80;
      static const UNIT_T K[K_COUNT];
      static const size_t H_COUNT = 8;
      static const UNIT_T H[H_COUNT];
    };
    class sha512_type
    {
     public:
      typedef uint64_t UNIT_T;
      static const size_t HASH_LENGTH = 64;
      static const size_t CHUNK_SIZE = 128;
      static const size_t K_COUNT = 80;
      static const uint64_t K[K_COUNT];
      static const size_t H_COUNT = 8;
      static const UNIT_T H[H_COUNT];
    };

    template <typename SHA_TYPE>
    class sha224_512_chunk
    {
     public:
      typedef typename SHA_TYPE::UNIT_T UNIT_T;

      static const size_t HASH_LENGTH = SHA_TYPE::HASH_LENGTH;
      static const size_t CHUNK_SIZE = SHA_TYPE::CHUNK_SIZE;
      static const size_t K_COUNT = SHA_TYPE::K_COUNT;
      static const size_t H_COUNT = SHA_TYPE::H_COUNT;
      static const UNIT_T*
      H()
      {
        return SHA_TYPE::H;
      }
      static const UNIT_T*
      K()
      {
        return SHA_TYPE::K;
      }

     public:
      static void process_chunk(UNIT_T* H, UNIT_T* M_i);

     protected:
      static UNIT_T
      ROTL(size_t n, UNIT_T digit)
      {
        size_t bitwidth = sizeof(UNIT_T) * 8;
        if (n > bitwidth)
          return 0;
        return (digit << n) | (digit >> (bitwidth - n));
      }
      static UNIT_T
      ROTR(size_t n, UNIT_T digit)
      {
        size_t bitwidth = sizeof(UNIT_T) * 8;
        if (n > bitwidth)
          return 0;
        return (digit >> n) | (digit << (bitwidth - n));
      }

      static UNIT_T
      CH(UNIT_T x, UNIT_T y, UNIT_T z)
      {
        return (x & y) ^ ((~x) & z);
      }
      static UNIT_T
      MAJ(UNIT_T x, UNIT_T y, UNIT_T z)
      {
        return (x & y) ^ (x & z) ^ (y & z);
      }

      static uint32_t
      BSIG0(uint32_t x)
      {
        return ROTR(2, x) ^ ROTR(13, x) ^ ROTR(22, x);
      }
      static uint32_t
      BSIG1(uint32_t x)
      {
        return ROTR(6, x) ^ ROTR(11, x) ^ ROTR(25, x);
      }

      static uint32_t
      SSIG0(uint32_t x)
      {
        return ROTR(7, x) ^ ROTR(18, x) ^ (x >> 3);
      }
      static uint32_t
      SSIG1(uint32_t x)
      {
        return ROTR(17, x) ^ ROTR(19, x) ^ (x >> 10);
      }

      static uint64_t
      BSIG0(uint64_t x)
      {
        return ROTR(28, x) ^ ROTR(34, x) ^ ROTR(39, x);
      }
      static uint64_t
      BSIG1(uint64_t x)
      {
        return ROTR(14, x) ^ ROTR(18, x) ^ ROTR(41, x);
      }
      static uint64_t
      SSIG0(uint64_t x)
      {
        return ROTR(1, x) ^ ROTR(8, x) ^ (x >> 7);
      }

      static uint64_t
      SSIG1(uint64_t x)
      {
        return ROTR(19, x) ^ ROTR(61, x) ^ (x >> 6);
      }
    };

    template <typename SHA_TYPE>
    class sha1_chunk
    {
     public:
      typedef typename SHA_TYPE::UNIT_T UNIT_T;

      static const size_t HASH_LENGTH = SHA_TYPE::HASH_LENGTH;
      static const size_t CHUNK_SIZE = SHA_TYPE::CHUNK_SIZE;
      static const size_t K_COUNT = SHA_TYPE::K_COUNT;
      static const size_t H_COUNT = SHA_TYPE::H_COUNT;
      static const UNIT_T*
      H()
      {
        return SHA_TYPE::H;
      }
      static const UNIT_T*
      K()
      {
        return SHA_TYPE::K;
      }

     public:
      static void process_chunk(UNIT_T* H, UNIT_T* M_i);

     protected:
      static UNIT_T
      f(UNIT_T t, UNIT_T B, UNIT_T C, UNIT_T D)
      {
        if (t <= 19)
          return (B & C) | ((~B) & D);
        if ((t >= 20) && (t <= 39))
          return B ^ C ^ D;
        if ((t >= 40) && (t <= 59))
          return (B & C) | (B & D) | (C & D);
        if ((t >= 60) && (t <= 79))
          return B ^ C ^ D;
        return 0;
      }

      static UNIT_T
      K(UNIT_T t)
      {
        if (t <= 19)
          return 0x5A827999;
        if ((t >= 20) && (t <= 39))
          return 0x6ED9EBA1;
        if ((t >= 40) && (t <= 59))
          return 0x8F1BBCDC;
        if ((t >= 60) && (t <= 79))
          return 0xCA62C1D6;
        return 0;
      }
      static UNIT_T
      ROTL(size_t n, UNIT_T digit)
      {
        size_t bitwidth = sizeof(UNIT_T) * 8;
        if (n > bitwidth)
          return 0;
        return (digit << n) | (digit >> (bitwidth - n));
      }
    };
    template <typename SHA_CHUNK>
    class sha_base
    {
     public:
      typedef typename SHA_CHUNK::UNIT_T UNIT_T;

      static const size_t HASH_LENGTH = SHA_CHUNK::HASH_LENGTH;
      static const size_t CHUNK_SIZE = SHA_CHUNK::CHUNK_SIZE;
      static const size_t H_COUNT = SHA_CHUNK::H_COUNT;
      static const UNIT_T*
      H()
      {
        return SHA_CHUNK::H();
      }
      static void
      process_chunk(UNIT_T* H, UNIT_T* M_i)
      {
        return SHA_CHUNK::process_chunk(H, M_i);
      }

     public:
      static int generate(char* buffer, size_t length, const char* block,
                          size_t block_size);
      static std::string generate(const char* block, size_t block_size);
      static std::string generate(const std::string& block);

     protected:
      static void process_block(UNIT_T* H, const char* block,
                                size_t block_size);
    };
    template <typename SHA_TYPE>
    void
    sha224_512_chunk<SHA_TYPE>::process_chunk(UNIT_T* H, UNIT_T* M_i)
    {
      UNIT_T* W = new UNIT_T[sha224_512_chunk::K_COUNT];
      for (size_t t = 0; t < 16; ++t)
        W[t] = utils::net_to_host(M_i[t]);
      for (size_t t = 16; t < sha224_512_chunk::K_COUNT; ++t)
        W[t] = SSIG1(W[t - 2]) + W[t - 7] + SSIG0(W[t - 15]) + W[t - 16];

      UNIT_T a = H[0];
      UNIT_T b = H[1];
      UNIT_T c = H[2];
      UNIT_T d = H[3];
      UNIT_T e = H[4];
      UNIT_T f = H[5];
      UNIT_T g = H[6];
      UNIT_T h = H[7];

      for (size_t t = 0; t < sha224_512_chunk::K_COUNT; ++t)
      {
        UNIT_T T1 =
            h + BSIG1(e) + CH(e, f, g) + sha224_512_chunk::K()[t] + W[t];
        UNIT_T T2 = BSIG0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
      }
      H[0] += a;
      H[1] += b;
      H[2] += c;
      H[3] += d;
      H[4] += e;
      H[5] += f;
      H[6] += g;
      H[7] += h;
      delete[] W;
    }

    template <typename SHA_TYPE>
    void
    sha1_chunk<SHA_TYPE>::process_chunk(UNIT_T* H, UNIT_T* M_i)
    {
      UNIT_T* W = new UNIT_T[sha1_chunk::K_COUNT];
      for (size_t t = 0; t < 16; ++t)
        W[t] = miacropp::utils::host_to_net(M_i[t]);
      for (size_t t = 16; t < sha1_chunk::K_COUNT; ++t)
        W[t] = sha1_chunk::ROTL(1, W[t - 3] ^ W[t - 8] ^ W[t - 14] ^ W[t - 16]);

      UNIT_T A = H[0];
      UNIT_T B = H[1];
      UNIT_T C = H[2];
      UNIT_T D = H[3];
      UNIT_T E = H[4];
      for (size_t t = 0; t < sha1_chunk::K_COUNT; ++t)
      {
        UNIT_T TEMP = sha1_chunk::ROTL(5, A) + f(t, B, C, D) + E + W[t] + K(t);
        E = D;
        D = C;
        C = sha1_chunk::ROTL(30, B);
        B = A;
        A = TEMP;
      }
      H[0] += A;
      H[1] += B;
      H[2] += C;
      H[3] += D;
      H[4] += E;
      delete[] W;
    }

    template <typename SHA_CHUNK>
    int
    sha_base<SHA_CHUNK>::generate(char* buffer, size_t length,
                                  const char* block, size_t block_size)
    {
      if (length < sha_base::HASH_LENGTH)
        return -1;

      UNIT_T H[sha_base::H_COUNT];
      for (size_t i = 0; i < sha_base::H_COUNT; ++i)
        H[i] = sha_base::H()[i];

      sha_base::process_block(H, block, block_size);
      UNIT_T* buffer_uint = reinterpret_cast<UNIT_T*>(buffer);
      for (size_t i = 0; i < sha_base::HASH_LENGTH / sizeof(UNIT_T); ++i)
        buffer_uint[i] = utils::host_to_net(H[i]);
      return 0;
    }

    template <typename SHA_CHUNK>
    std::string
    sha_base<SHA_CHUNK>::generate(const char* block, size_t block_size)
    {
      std::string buffer;
      buffer.resize(sha_base::HASH_LENGTH);
      if (sha_base::generate(const_cast<char*>(buffer.c_str()), buffer.length(),
                             block, block_size)
          == -1)
        buffer.clear();
      return buffer;
    }

    template <typename SHA_CHUNK>
    std::string
    sha_base<SHA_CHUNK>::generate(const std::string& block)
    {
      return sha_base::generate(block.c_str(), block.length());
    }

    template <typename SHA_CHUNK>
    void
    sha_base<SHA_CHUNK>::process_block(UNIT_T* H, const char* block,
                                       size_t block_size)
    {
      size_t chunk_size = sha_base::CHUNK_SIZE;
      const size_t append_length_size = sizeof(UNIT_T) * 2;
      size_t block_pre_count = block_size / chunk_size;
      size_t block_left_size = block_size % chunk_size;
      size_t block_pre_size = block_size - block_left_size;
      for (size_t i = 0; i < block_pre_count; ++i)
      {
        UNIT_T* M_i = reinterpret_cast<UNIT_T*>(const_cast<char*>(block)
                                                + i * chunk_size);
        sha_base::process_chunk(H, M_i);
      }

      char* chunk_1 = new char[chunk_size];

      std::memcpy(chunk_1, const_cast<char*>(block) + block_pre_size,
                  block_left_size);
      chunk_1[block_left_size] = 0x80;

      UNIT_T append_length1 = block_size >> (sizeof(UNIT_T) * 8 - 3);
      UNIT_T append_length2 = static_cast<UNIT_T>(block_size << 3);

      if (block_left_size + 1 + append_length_size <= chunk_size)
      {
        size_t zero_count =
            chunk_size - 1 - block_left_size - append_length_size;
        std::memset(chunk_1 + block_left_size + 1, 0, zero_count);

        UNIT_T* padded_chunk = reinterpret_cast<UNIT_T*>(chunk_1 + chunk_size
                                                         - append_length_size);
        padded_chunk[0] = utils::host_to_net(append_length1);
        padded_chunk[1] = utils::host_to_net(append_length2);

        UNIT_T* M_i = reinterpret_cast<UNIT_T*>(const_cast<char*>(chunk_1));
        sha_base::process_chunk(H, M_i);
      }
      else
      {
        char* chunk_2 = new char[chunk_size];
        if (block_left_size + 1 < chunk_size)
          std::memset(chunk_1 + block_left_size + 1, 0,
                      chunk_size - block_left_size - 1);
        std::memset(chunk_2, 0, chunk_size - append_length_size);

        UNIT_T* padded_chunk = reinterpret_cast<UNIT_T*>(chunk_2 + chunk_size
                                                         - append_length_size);
        padded_chunk[0] = utils::host_to_net(append_length1);
        padded_chunk[1] = utils::host_to_net(append_length2);

        UNIT_T* M_i = reinterpret_cast<UNIT_T*>(const_cast<char*>(chunk_1));
        sha_base::process_chunk(H, M_i);
        M_i = reinterpret_cast<UNIT_T*>(const_cast<char*>(chunk_2));
        sha_base::process_chunk(H, M_i);
        delete[] chunk_2;
      }
      delete[] chunk_1;
    }

    typedef sha_base<sha1_chunk<sha1_type>> sha1;
    typedef sha_base<sha224_512_chunk<sha224_type>> sha224;
    typedef sha_base<sha224_512_chunk<sha256_type>> sha256;
    typedef sha_base<sha224_512_chunk<sha384_type>> sha384;
    typedef sha_base<sha224_512_chunk<sha512_type>> sha512;
  };
};
#endif  // __SHA_HPP__
